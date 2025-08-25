#ifndef LEDWINDOW_H
#define LEDWINDOW_H

#if 1
extern "C"
{
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
}

#define TEST_MAGIC 'x'                    //定义幻数
#define LED1 _IO(TEST_MAGIC, 0)
#define LED2 _IO(TEST_MAGIC, 1)
#define LED3 _IO(TEST_MAGIC, 2)
#define LED4 _IO(TEST_MAGIC, 3)
#define LED_ON  	0	//灯亮
#define LED_OFF		1   //灯灭
#endif

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class LedWindow;
}

class LedWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LedWindow(QWidget *parent = nullptr);
    ~LedWindow();

private slots:
    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::LedWindow *ui;
    int fd;
};

#endif // LEDWINDOW_H
