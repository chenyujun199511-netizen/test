/********************************************************************************
** Form generated from reading UI file 'ledwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEDWINDOW_H
#define UI_LEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LedWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LedWindow)
    {
        if (LedWindow->objectName().isEmpty())
            LedWindow->setObjectName(QStringLiteral("LedWindow"));
        LedWindow->resize(800, 480);
        LedWindow->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        centralwidget = new QWidget(LedWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 60, 100, 50));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 130, 100, 50));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 200, 100, 50));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 270, 100, 50));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(470, 60, 100, 50));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(470, 130, 100, 50));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(470, 270, 100, 50));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(470, 200, 100, 50));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 10, 120, 40));
        LedWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LedWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        LedWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LedWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LedWindow->setStatusBar(statusbar);

        retranslateUi(LedWindow);

        QMetaObject::connectSlotsByName(LedWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LedWindow)
    {
        LedWindow->setWindowTitle(QApplication::translate("LedWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("LedWindow", "\345\274\200\347\201\2571", 0));
        pushButton_2->setText(QApplication::translate("LedWindow", "\345\274\200\347\201\2572", 0));
        pushButton_3->setText(QApplication::translate("LedWindow", "\345\274\200\347\201\2573", 0));
        pushButton_4->setText(QApplication::translate("LedWindow", "\345\274\200\347\201\2574", 0));
        pushButton_5->setText(QApplication::translate("LedWindow", "\345\205\263\347\201\2571", 0));
        pushButton_6->setText(QApplication::translate("LedWindow", "\345\205\263\347\201\2572", 0));
        pushButton_7->setText(QApplication::translate("LedWindow", "\345\205\263\347\201\2574", 0));
        pushButton_8->setText(QApplication::translate("LedWindow", "\345\205\263\347\201\2573", 0));
        pushButton_9->setText(QApplication::translate("LedWindow", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class LedWindow: public Ui_LedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEDWINDOW_H
