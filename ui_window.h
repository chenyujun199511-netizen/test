/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(800, 480);
        Window->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(Window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 0, 100, 50));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 310, 200, 50));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 180, 100, 100));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(420, 60, 100, 100));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 180, 100, 100));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 60, 100, 100));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(0, 0, 120, 40));
        Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Window);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window->setStatusBar(statusbar);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "MainWindow", 0));
        label->setText(QApplication::translate("Window", "\344\270\273\351\241\265\351\235\242", 0));
        pushButton->setText(QApplication::translate("Window", "\350\207\252\345\212\250\346\222\255\346\224\276\347\233\270\345\206\214", 0));
        pushButton_2->setText(QApplication::translate("Window", "\345\274\200\345\205\263\347\201\257", 0));
        pushButton_3->setText(QApplication::translate("Window", "\346\212\245\350\255\246", 0));
        pushButton_4->setText(QApplication::translate("Window", "\347\205\247\347\233\270\346\234\272", 0));
        pushButton_5->setText(QApplication::translate("Window", "\350\257\255\351\237\263", 0));
        pushButton_6->setText(QApplication::translate("Window", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
