#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set(QString str1,QString str2)
    {
        account = str1;
        password = str2;
    }
    QString get_acc()
    {
        return account;
    }
    QString get_psd()
    {
        return password;
    }

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QString account;
    QString password;
};
#endif // MAINWINDOW_H
