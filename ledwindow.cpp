#include "ledwindow.h"
#include "ui_ledwindow.h"

int fd;

LedWindow::LedWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LedWindow)
{
    ui->setupUi(this);
#if 1
    //1.在程序执行前必须确保你的驱动已经安装驱动
    //2.访问驱动设备
    fd = open("/dev/Led",O_RDWR);
    if(fd == -1)
    {
        perror("open:");
        exit(0);
    }
#endif
}

LedWindow::~LedWindow()
{
    delete ui;
#if 1
    //4. 关闭设备文件
    ::close(fd);  //::访问全局close函数，非本类close函数
#endif
}

// 返回主页面
void LedWindow::on_pushButton_9_clicked()
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
// 开灯1
void LedWindow::on_pushButton_clicked()
{
#if 1
    //开灯
    ioctl(fd,LED1,LED_ON);
#endif
}
// 关灯1
void LedWindow::on_pushButton_5_clicked()
{
#if 1
    //关灯
    ioctl(fd,LED1,LED_OFF);
#endif
}

// 开灯2
void LedWindow::on_pushButton_2_clicked()
{
#if 1
    ioctl(fd,LED2,LED_ON);
#endif
}
// 关灯2
void LedWindow::on_pushButton_6_clicked()
{
#if 1
    ioctl(fd,LED2,LED_OFF);
#endif
}

// 开灯3
void LedWindow::on_pushButton_3_clicked()
{
#if 1
    ioctl(fd,LED3,LED_ON);
#endif
}
// 关灯3
void LedWindow::on_pushButton_8_clicked()
{
#if 1
    ioctl(fd,LED3,LED_OFF);
#endif
}

// 开灯4
void LedWindow::on_pushButton_4_clicked()
{
#if 1
    ioctl(fd,LED4,LED_ON);
#endif
}
// 关灯4
void LedWindow::on_pushButton_7_clicked()
{
#if 1
    ioctl(fd,LED4,LED_OFF);
#endif
}
