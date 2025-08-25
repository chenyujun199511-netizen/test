#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QTimer>
#include <QTime>
#include <QDebug>
#include "v4l2api.h"
#include "picshowmainwindow.h" // 子窗口的头文件

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onUpdateUIData();
    void on_btn_start_clicked();

    void on_btn_stop_clicked();

    void on_btn_capture_clicked();

    void on_btn_show_clicked();

    void on_btn_show_2_clicked();

private:
    Ui::Widget *ui;

    V4l2Api *v4l2;//定义一个摄像头类的指针
    QTimer *m_timer;

    QImage saveImage;  //图片处理类的对象
};
#endif // WIDGET_H
