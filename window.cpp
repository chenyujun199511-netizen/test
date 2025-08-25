#include "window.h"
#include "ui_window.h"
#include "ledwindow.h"
#include "camerawindow.h"
#include "photowindow.h"
#include "aiwindow.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window),
    status_beep(false) // 初始化 status_beep 变量
{
    ui->setupUi(this);
    // 打开蜂鸣器
    fd_beep = 0;
    fd_beep = open("/dev/beep", O_RDWR);
    if(fd_beep == -1)
    {
        perror("open:");
        exit(0);
    }
}

Window::~Window()
{
    delete ui;
#if 1
    ::close(fd_beep);
#endif
}

// 退出登录
void Window::on_pushButton_6_clicked()
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

// 开关灯
void Window::on_pushButton_2_clicked()
{
    // 跳转到用户界面
    LedWindow *w = new LedWindow(this);
    //设置它的属性为自动释放
    w->setAttribute(Qt::WA_DeleteOnClose);
    //显示界面1的窗口
    w->show();
    //影藏当前界面
    this->hide();
}

// 照相机
void Window::on_pushButton_4_clicked()
{
#if 1
    cameraWindow *w = new cameraWindow(this);
    //设置它的属性为自动释放
    w->setAttribute(Qt::WA_DeleteOnClose);
    //显示界面1的窗口
    w->show();
    //影藏当前界面
    this->hide();
#endif
}

// 自动播放相册
void Window::on_pushButton_clicked()
{
    photoWindow *w = new photoWindow(this);
    //设置它的属性为自动释放
    w->setAttribute(Qt::WA_DeleteOnClose);
    //显示界面1的窗口
    w->show();
    //影藏当前界面
    this->hide();
}

// 蜂鸣器警报
void Window::on_pushButton_3_clicked()
{
#if 1
    status_beep = !status_beep;
    // 使能蜂鸣器
    ioctl(fd_beep, status_beep, 1);
#endif
}

// 语音
void Window::on_pushButton_5_clicked()
{
        aiWindow *w = new aiWindow(this);
        //设置它的属性为自动释放
        w->setAttribute(Qt::WA_DeleteOnClose);
        //显示界面1的窗口
        w->show();
        //影藏当前界面
        this->hide();
}
