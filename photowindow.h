#ifndef PHOTOWINDOW_H
#define PHOTOWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDir> //目录类的头文件
#include <QFileInfoList> //文件链表的头文件
#include <QTimer>
#include <QThread>
#include <QPixmap>
#include <QLabel>

extern "C"
{
    #include <unistd.h>
}

namespace Ui {
class photoWindow;
}

class photoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit photoWindow(QWidget *parent = nullptr);
    ~photoWindow();

private slots:
    void on_pushButton_clicked();
    void showNextImage();  // 新增槽函数，用于显示下一张图片

private:
    Ui::photoWindow *ui;

    QFileInfoList fileList;  //存图片名的链表
    int index; //索引
    QTimer *m_timer;  // 新增成员变量，用于定时切换图片

    void showCurrentImage();  // 新增函数，显示当前图片
};

#endif // PHOTOWINDOW_H
