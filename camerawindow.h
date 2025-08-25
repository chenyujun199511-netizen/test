#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include "v4l2api.h"
#include "picshowmainwindow.h" // 子窗口的头文件

namespace Ui {
class cameraWindow;
}

class cameraWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit cameraWindow(QWidget *parent = nullptr);
    ~cameraWindow();

private slots:
    void onUpdateUIData();
    void on_btn_start_clicked();

    void on_btn_stop_clicked();

    void on_btn_capture_clicked();

    void on_btn_show_clicked();
    void on_btn_show_2_clicked();

private:
    Ui::cameraWindow *ui;
    V4l2Api *v4l2;//定义一个摄像头类的指针
    QTimer *m_timer;

    QImage saveImage;  //图片处理类的对象
};

#endif // CAMERAWINDOW_H

