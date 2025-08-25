#include "mainwindow.h"
#include "window.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textAccount->setText("123456");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 注册按钮
void MainWindow::on_pushButton1_clicked()
{
    QString str_pswd = ui->textPassword->text();   // 获取密码输入框的内容

       // 检查密码是否为空
       if (str_pswd.isEmpty())
       {
           QMessageBox::warning(this, "注册失败", "密码不能为空！");
           return;
       }
       else
       {
           set("123456",str_pswd);
           QMessageBox::information(this, "result", "注册成功");
       }
}

// 登录按钮
void MainWindow::on_pushButton2_clicked()
{
    QString str_pswd1 = ui->textPassword->text();
    QString str_pswd2 = get_psd();
    if(str_pswd1 == str_pswd2 && str_pswd1 != NULL)
    {
        qDebug()<<"登录成功!";
        QMessageBox::information(this,"result","登录成功!");

        // 跳转到用户界面
        Window *w = new Window(this);
        //设置它的属性为自动释放
        w->setAttribute(Qt::WA_DeleteOnClose);
        //显示界面1的窗口
        w->show();
        //影藏当前界面
        this->hide();
    }
    else
    {
        qDebug()<<"登录失败!";
        QMessageBox::warning(this, "result", "登录失败");
    }
}

// 键盘1
void MainWindow::on_pushButton_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "1"; // 追加 "1"
    ui->textPassword->setText(currentText);
}
// 键盘2
void MainWindow::on_pushButton_2_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "2"; // 追加 "2"
    ui->textPassword->setText(currentText);
}
// 键盘3
void MainWindow::on_pushButton_3_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "1"; // 追加 "1"
    ui->textPassword->setText(currentText);
}
// 键盘4
void MainWindow::on_pushButton_6_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "4"; // 追加 "4"
    ui->textPassword->setText(currentText);
}
// 键盘5
void MainWindow::on_pushButton_5_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "5";
    ui->textPassword->setText(currentText);
}
// 键盘6
void MainWindow::on_pushButton_4_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "6";
    ui->textPassword->setText(currentText);
}
// 键盘7
void MainWindow::on_pushButton_8_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "7";
    ui->textPassword->setText(currentText);
}
// 键盘8
void MainWindow::on_pushButton_7_clicked()
{
    QString currentText = ui->textPassword->text();
    currentText += "8";
    ui->textPassword->setText(currentText);
}
// 键盘9
void MainWindow::on_pushButton_9_clicked()
{
    QString currentText = ui->textPassword->text(); // 获取当前文本
    currentText += "9";
    ui->textPassword->setText(currentText);
}
// 键盘0
void MainWindow::on_pushButton_10_clicked()
{
    QString currentText = ui->textPassword->text();
    currentText += "0";
    ui->textPassword->setText(currentText);
}
// 键盘del
void MainWindow::on_pushButton_11_clicked()
{
    ui->textPassword->setText("");
}

