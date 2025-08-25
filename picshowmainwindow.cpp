#include "picshowmainwindow.h"
#include "ui_picshowmainwindow.h"

PicShowMainWindow::PicShowMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PicShowMainWindow)
{
    ui->setupUi(this);
    /*
        将当前pic目录里面的bmp照片存储到链表中
    */
    //打开pic目录
    QDir dir("./pic"); //打开目录
    dir.setFilter(QDir::Files);
    //将目录下所有的文件信息存储到该容器中
    fileList = dir.entryInfoList(); //将目录里面所有的bmp照片添加到链表中

    for(int i=0; i<fileList.size() ;i++){
         qDebug()<<fileList.at(i).filePath(); //打印图片的名字
    }

    index = 0;
}

PicShowMainWindow::~PicShowMainWindow()
{
    delete ui;
}

//上一张
void PicShowMainWindow::on_btn_prev_clicked()
{
    //index = (index-1) >0 ?  (index-1) : 0;
    index--;
    if(index == -1)
         index = fileList.size() -1;

    QString picName = fileList.at(index).filePath(); //从链表里面获取图片的路径

    QPixmap pic(picName);
    pic = pic.scaled(ui->label->size());
    ui->label->setPixmap(pic);
}

//下一张
void PicShowMainWindow::on_btn_next_clicked()
{
    index = ++index % fileList.size();
    QString picName = fileList.at(index).filePath(); //从链表里面获取图片的路径

    QPixmap pic(picName);
    pic = pic.scaled(ui->label->size());
    ui->label->setPixmap(pic);
}

//子窗口的返回键
void PicShowMainWindow::on_btn_back_clicked()
{
    //先获取父窗口的对象
    QWidget *parent = this->parentWidget();

    //显示父窗口
    parent->show();

    //关闭子窗口
    this->close();
    delete this;

}
