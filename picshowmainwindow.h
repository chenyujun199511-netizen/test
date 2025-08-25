#ifndef PICSHOWMAINWINDOW_H
#define PICSHOWMAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDir> //目录类的头文件
#include <QFileInfoList> //文件链表的头文件

namespace Ui {
class PicShowMainWindow;
}

class PicShowMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PicShowMainWindow(QWidget *parent = nullptr);
    ~PicShowMainWindow();

private slots:
    void on_btn_prev_clicked();

    void on_btn_next_clicked();

    void on_btn_back_clicked();

private:
    Ui::PicShowMainWindow *ui;

    QFileInfoList fileList;  //存图片名的链表
    int index; //索引
};

#endif // PICSHOWMAINWINDOW_H
