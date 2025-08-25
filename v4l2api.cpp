#include "v4l2api.h"

V4l2Api::V4l2Api(const char *deviceName)
{
    //1、打开摄像头驱动文件
     fd = open(deviceName,O_RDWR);
     if(fd == -1){
         perror("open camera error");
         return ;
     }
     //2、获取支持的摄像头格式 --摄像头信息  -VIDIOC_ENUM_FMT
     //#define VIDIOC_ENUM_FMT         _IOWR('V',  2, struct v4l2_fmtdesc)
     /*
     struct v4l2_fmtdesc {
     __u32		    index;             摄像头的编号
     __u32		    type;               enum v4l2_buf_type  摄像头类型  固定为V4L2_BUF_TYPE_VIDEO_CAPTURE
     __u32               flags;
     __u8		    description[32];   Description string  摄像头的描述
     __u32		    pixelformat;        Format fourcc  像素格式。，也就是说当前摄像头采集的画面格式
     __u32		    mbus_code;		Media bus code
     __u32		    reserved[3];
 };

     */
     struct v4l2_fmtdesc v4fmt;
     v4fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE ;//使用摄像头 视频采集 格式
     int i=0;

     while(1){
         v4fmt.index = i++;
         int ret = ioctl(fd,VIDIOC_ENUM_FMT,&v4fmt);
         if(ret<0){
             //perror("获取摄像头信息失败");
             break;
         }
         //显示摄像头的信息
         printf("index = %d\n",v4fmt.index);
         printf("flags = %d\n",v4fmt.flags);
         printf("description = %s\n",v4fmt.description);
         unsigned char*p =  (unsigned char*)&v4fmt.pixelformat;
         printf("pixelformat = %c%c%c%c\n",p[0],p[1],p[2],p[3]);
         printf("reserved = %d\n",v4fmt.reserved[0]);

         /*
         摄像头信息：
             index = 0
             flags = 0
             description = YUV 4:2:2 (YUYV)
             pixelformat = YUYV   --图像 格式  yuyv
             #define V4L2_PIX_FMT_YUYV    v4l2_fourcc('Y', 'U', 'Y', 'V')  16  YUV 4:2:2
             reserved = 0
         */
     }
     //3、配置摄像头采集格式  VIDIOC_S_FMT：设置当前驱动的频捕获格式
     //说白了，就是设置摄像头捕捉画面的宽度 和高度   设置摄像头图像格式
     //#define VIDIOC_S_FMT		_IOWR('V',  5, struct v4l2_format)
     struct v4l2_format vfmt;
     vfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;//使用摄像头 视频采集 格式
     vfmt.fmt.pix.width = 640;//摄像头采集图像的宽度
     vfmt.fmt.pix.height = 480;//摄像头采集图像的高度
     vfmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV; //设置视频采集格式

     int ret = ioctl(fd,VIDIOC_S_FMT,&vfmt);
     if(ret<0){
         perror("set format error");
         return ;
     }else{
         printf("set fromat success\n");
     }
     //验证刚才的设置 是否 生效  VIDIOC_G_FMT：读取当前驱动的频捕获格式
     //#define VIDIOC_G_FMT		_IOWR('V',  4, struct v4l2_format)
     memset(&vfmt,0,sizeof(vfmt));
     vfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

     ret = ioctl(fd,VIDIOC_G_FMT,&vfmt);
     if(ret<0){
         perror(" get format error");
         return ;
     }else{
         printf("get format success\n");
     }
     if(vfmt.fmt.pix.width == 640 && vfmt.fmt.pix.height == 480 && vfmt.fmt.pix.pixelformat == V4L2_PIX_FMT_YUYV)
     {
         printf("......success\n");
     }else{
         printf("设置失败\n");
     }
     //4、申请内核空间--向内核申请一个 缓冲区队列，存储摄像头拍摄的画面数据
     //VIDIOC_REQBUFS：分配内存
     //#define VIDIOC_REQBUFS		_IOWR('V',  8, struct v4l2_requestbuffers)
     struct v4l2_requestbuffers reqbuffer;
     reqbuffer.count = 4;//申请4个缓冲区 用来存储图像数据 也就是说 队列有4个元素，每个元素都是一个缓冲区
     reqbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     reqbuffer.memory = V4L2_MEMORY_MMAP ;//申请的方式为内存映射

     ret = ioctl(fd,VIDIOC_REQBUFS,&reqbuffer);
     if(ret<0){
         perror("malloc kernel memory error");
         return ;
     }else{
         printf("malloc kernel memory success\n");
     }

     //5、由于用户不能直接访问内核空间，所以将内核缓冲区队列 映射到用户的虚拟内存空间上
     //VIDIOC_QUERYBUF
     //#define VIDIOC_QUERYBUF		_IOWR('V',  9, struct v4l2_buffer)
     struct v4l2_buffer mapbuffer;

     for(int i=0; i<4; i++){
         mapbuffer.index = i; //表示你要查询第几块   一共有四块缓冲区
         mapbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
         //1)先把查询的命令发送下去，获取当前你要映射的内核空间缓冲区的大小 队列的偏移量
         ret = ioctl(fd,VIDIOC_QUERYBUF,&mapbuffer);
         if(ret<0){
             perror("申请内核空间失败");
             return ;
         }
         //2)进行内存映射 mmap
         mptr[i] = (unsigned char *)mmap(NULL,mapbuffer.length,PROT_WRITE|PROT_READ,MAP_SHARED,fd, mapbuffer.m.offset);
         size[i] = mapbuffer.length;
         //3)通知内核已经完成  VIDIOC_QBUF
         //#define VIDIOC_QBUF		_IOWR('V', 15, struct v4l2_buffer)
         ret = ioctl(fd,VIDIOC_QBUF,&mapbuffer);
         if(ret<0){
             perror("通知失败");
             return ;
         }
     }
}

void V4l2Api::start()
{
    //6、开启摄像头  VIDIOC_STREAMON：开始视频显示函数
    //#define VIDIOC_STREAMON		 _IOW('V', 18, int)
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    int ret = ioctl(fd,VIDIOC_STREAMON,&type);
    if(ret<0){
        perror("start camera error");
        return ;
    }else{
        printf("start camera success\n");
    }
}

void V4l2Api::stop()
{
    //10、停止摄像头
    //#define VIDIOC_STREAMOFF	 _IOW('V', 19, int)
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    int ret = ioctl(fd,VIDIOC_STREAMOFF,&type);
    if(ret<0){
        perror("stop camera error");
        return ;
    }else{
        printf("stop camera success\n");
    }
}

void V4l2Api::destory()
{
    //11、释放内存、关闭文件
   //释放内存 int munmap(void *addr, size_t length);
   for(int i=0;i<4;i++)
   {
       munmap(mptr[i],size[i]);
   }
   //关闭设备
   close(fd);
}

void V4l2Api::get_frame(char *buffer)
{
    //7、采集数据--采集的数据格式为 yuyv格式
     //VIDIOC_DQBUF：把数据从缓存中读取出来
     //#define VIDIOC_DQBUF		_IOWR('V', 17, struct v4l2_buffer)
     struct v4l2_buffer readbuffer;
     readbuffer.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
     //1）采集数据的命令进行发送
     int ret = ioctl(fd,VIDIOC_DQBUF,&readbuffer);
     if(ret<0){
         perror("get frame error");
         return ;
     }
     //2)进行数据的拷贝
     memcpy(buffer,mptr[readbuffer.index],readbuffer.length);
     //3)通知内核已经采集完毕
     ret = ioctl(fd,VIDIOC_QBUF,&readbuffer);
     if(ret<0){
         perror("通知失败");
         return ;
     }
}

bool V4l2Api::yuv422torgb24(unsigned char *buffer, unsigned char *rgbdata, int w, int h)
{
    int r1, g1, b1;
    int r2, g2, b2;

    for(int i=0; i<w*h/2; i++)
    {
        char data[4];
        memcpy(data, buffer+i*4, 4);
        //Y0U0Y1V1  -->[Y0 U0 V1] [Y1 U0 V1]
        unsigned char Y0=data[0];
        unsigned char U0=data[1];
        unsigned char Y1=data[2];
        unsigned char V1=data[3];

        r1 = Y0+1.4075*(V1-128); if(r1>255)r1=255; if(r1<0)r1=0;
        g1 =Y0- 0.3455 * (U0-128) - 0.7169*(V1-128); if(g1>255)g1=255; if(g1<0)g1=0;
        b1 = Y0 + 1.779 * (U0-128);  if(b1>255)b1=255; if(b1<0)b1=0;
        r2 = Y1+1.4075*(V1-128);if(r2>255)r2=255; if(r2<0)r2=0;
        g2 = Y1- 0.3455 * (U0-128) - 0.7169*(V1-128); if(g2>255)g2=255; if(g2<0)g2=0;
        b2 = Y1 + 1.779 * (U0-128);  if(b2>255)b2=255; if(b2<0)b2=0;

        rgbdata[i*6+0]=r1;
        rgbdata[i*6+1]=g1;
        rgbdata[i*6+2]=b1;
        rgbdata[i*6+3]=r2;
        rgbdata[i*6+4]=g2;
        rgbdata[i*6+5]=b2;
    }

    return true;
}
