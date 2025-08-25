#ifndef AIWINDOW_H
#define AIWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMessageBox> //消息对话框头文件
#include <QDebug> //打印信息头文件
#include <QCloseEvent>
#include <QPixmap>
#include <QMainWindow>
#include <QDir> //目录类的头文件
#include <QFileInfoList> //文件链表的头文件
#include <QTimer>
#include <QTime>

#include "window.h"
#include "photowindow.h"
#include "ledwindow.h"
#include "camerawindow.h"

extern "C"{
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/input.h>
#include <strings.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h> // for connect()
#include <arpa/inet.h>  // for sockaddr_in
}


namespace Ui {
class aiWindow;
}

class aiWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit aiWindow(QWidget *parent = nullptr);
    ~aiWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::aiWindow *ui;
    int fd = 0;
    int ret = 0;
    int sock_fd = 0;
};

#endif // AIWINDOW_H
