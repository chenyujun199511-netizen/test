#ifndef WINDOW_H
#define WINDOW_H

#if 1
extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
}
#endif

#include <QMainWindow>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Window *ui;
    int fd_beep;
    bool status_beep; // 将 status_beep 定义为一个布尔变量
};

#endif // WINDOW_H
