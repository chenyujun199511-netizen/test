/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label1;
    QLineEdit *textAccount;
    QLabel *label2;
    QLabel *label3;
    QLineEdit *textPassword;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"*\n"
"{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label1 = new QLabel(centralwidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(310, 30, 191, 50));
        textAccount = new QLineEdit(centralwidget);
        textAccount->setObjectName(QStringLiteral("textAccount"));
        textAccount->setGeometry(QRect(350, 90, 200, 30));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(270, 90, 70, 30));
        label3 = new QLabel(centralwidget);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(270, 150, 70, 30));
        textPassword = new QLineEdit(centralwidget);
        textPassword->setObjectName(QStringLiteral("textPassword"));
        textPassword->setGeometry(QRect(350, 150, 200, 30));
        textPassword->setEchoMode(QLineEdit::Password);
        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(180, 370, 80, 40));
        pushButton2 = new QPushButton(centralwidget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(560, 370, 80, 40));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(341, 220, 40, 40));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(391, 220, 40, 40));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(441, 220, 40, 40));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(441, 270, 40, 40));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(391, 270, 40, 40));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(341, 270, 40, 40));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(391, 320, 40, 40));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(341, 320, 40, 40));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(441, 320, 40, 40));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(341, 370, 41, 40));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(390, 370, 91, 40));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label1->setText(QApplication::translate("MainWindow", "\346\231\272\345\256\266\350\257\255\351\237\263\345\260\217\345\212\251\346\211\213", 0));
        textAccount->setText(QString());
        textAccount->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", 0));
        label2->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267\357\274\232", 0));
        label3->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0));
        textPassword->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        pushButton1->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", 0));
        pushButton2->setText(QApplication::translate("MainWindow", " \347\231\273\345\275\225", 0));
        pushButton->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "del", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
