#ifndef V4L2API_H
#define V4L2API_H

extern "C"{
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
 #include <string.h>
#include <sys/mman.h>
#include <stdbool.h>

#include <linux/videodev2.h>//摄像头框架v4l2头文件
}

class V4l2Api
{
public:
    V4l2Api(const char*deviceName = nullptr);

    void start();
    void stop();
    void destory();

    void get_frame(char*buffer);//采集数据
    bool yuv422torgb24(unsigned char *buffer, unsigned char *rgbdata, int w, int h);
private:
    int fd;
    unsigned char *mptr[4];//存储映射成功之后的四块缓冲区的 起始地址
    unsigned int size[4] ;//存储 映射之后 这四块缓冲区的大小
};

#endif // V4L2API_H
