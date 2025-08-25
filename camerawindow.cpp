#include "camerawindow.h"
#include "ui_camerawindow.h"
#include <QImage>

cameraWindow::cameraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cameraWindow)
{
    ui->setupUi(this);
    v4l2 = nullptr;

    //定时器的目的:规定时间内显示图片
    m_timer = new QTimer;
    connect(m_timer,&QTimer::timeout,this,&cameraWindow::onUpdateUIData);
}

cameraWindow::~cameraWindow()
{
    delete ui;
}

void cameraWindow::onUpdateUIData()
{
    char buffer[640*480*3] = {0};
    char rgbbuffer[640*480*3] = {0};
    //1、采集yuyv的数据
    v4l2->get_frame(buffer);

    //2、将 采集到的yuyv格式的数据buffer转换成rgb格式
    v4l2->yuv422torgb24((unsigned char *)buffer,(unsigned char *)rgbbuffer,640,480);

    //3、显示 ---- 图像源数据 rgbbuffer  到UI 控件
    QImage image = QImage((unsigned char *)rgbbuffer,640,480,QImage::Format_RGB888);
    QPixmap pic = QPixmap::fromImage(image);

    // pic = pic.scaled(ui->label1->size());
    // ui->label1->setPixmap(pic);
    pic = pic.scaled(ui->label1->size());
    ui->label1->setPixmap(pic);

    saveImage = image;
}

// 开启摄像头的按钮
void cameraWindow::on_btn_start_clicked()
{
    if(v4l2 == nullptr){
        v4l2 = new V4l2Api("/dev/video7"); // 在类V4l2Api的构造函数里面打开摄像头
    }
    v4l2->start();//启动摄像头
    //没100毫秒抓取一次摄像头的数据， 将它显示在屏幕 10fps
    m_timer->start(100); //启动定时器，
}
//停止摄像头
void cameraWindow::on_btn_stop_clicked()
{
   m_timer->stop();

   if(v4l2 != nullptr){
       v4l2->stop();
       v4l2->destory();
       delete  v4l2;
       v4l2 = nullptr;
   }

}
//抓拍按钮
void cameraWindow::on_btn_capture_clicked()
{
    /*
         将你抓拍的照片按照名字存储
         saveImage.save("1.bmp");
    */
    //获取当前的时间
    QString curTime = QTime::currentTime().toString("hh:mm:ss");
    QString fileName = QString("./pic/%1.bmp").arg(curTime);
    //fileName 把: 去掉
    fileName = fileName.remove(':');
    qDebug()<<"fileName:"<<fileName;

    //preview -->就是捕捉到的画面
    saveImage.save(fileName);  //将视频采集的yuv的格式转换为bmp的格式
}

void cameraWindow::on_btn_show_clicked()
{
    //获取子窗口的对象(widget的this指针传过去 用来返回)
    PicShowMainWindow *picWindow = new PicShowMainWindow(this);
    //设置它自动关闭的属性
    picWindow->setAttribute(Qt::WA_DeleteOnClose);
    //显示子窗口
    picWindow->show();
    //隐藏当前窗口
    this->hide();
}

void cameraWindow::on_btn_show_2_clicked()
{
    //获取父类的窗口
    QWidget *parent = this->parentWidget();
    //显示父类的窗口
    parent->show();
    //关闭当前的子窗口
    this->close();
    //销毁子窗口
    delete this;
}
