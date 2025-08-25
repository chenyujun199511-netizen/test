/********************************************************************************
** Form generated from reading UI file 'camerawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWINDOW_H
#define UI_CAMERAWINDOW_H

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

class Ui_cameraWindow
{
public:
    QWidget *centralwidget;
    QLabel *label1;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QPushButton *btn_capture;
    QPushButton *btn_show;
    QPushButton *btn_show_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cameraWindow)
    {
        if (cameraWindow->objectName().isEmpty())
            cameraWindow->setObjectName(QStringLiteral("cameraWindow"));
        cameraWindow->resize(800, 480);
        centralwidget = new QWidget(cameraWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label1 = new QLabel(centralwidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(0, 0, 640, 480));
        label1->setStyleSheet(QStringLiteral("background-color: rgb(158, 158, 158);"));
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(660, 10, 111, 61));
        btn_stop = new QPushButton(centralwidget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        btn_stop->setGeometry(QRect(660, 90, 111, 61));
        btn_capture = new QPushButton(centralwidget);
        btn_capture->setObjectName(QStringLiteral("btn_capture"));
        btn_capture->setGeometry(QRect(660, 170, 111, 61));
        btn_show = new QPushButton(centralwidget);
        btn_show->setObjectName(QStringLiteral("btn_show"));
        btn_show->setGeometry(QRect(660, 260, 111, 61));
        btn_show_2 = new QPushButton(centralwidget);
        btn_show_2->setObjectName(QStringLiteral("btn_show_2"));
        btn_show_2->setGeometry(QRect(660, 350, 111, 61));
        cameraWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cameraWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        cameraWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(cameraWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        cameraWindow->setStatusBar(statusbar);

        retranslateUi(cameraWindow);

        QMetaObject::connectSlotsByName(cameraWindow);
    } // setupUi

    void retranslateUi(QMainWindow *cameraWindow)
    {
        cameraWindow->setWindowTitle(QApplication::translate("cameraWindow", "MainWindow", 0));
        label1->setText(QString());
        btn_start->setText(QApplication::translate("cameraWindow", "\345\274\200\345\220\257", 0));
        btn_stop->setText(QApplication::translate("cameraWindow", "\345\201\234\346\255\242", 0));
        btn_capture->setText(QApplication::translate("cameraWindow", "\346\212\223\346\213\215", 0));
        btn_show->setText(QApplication::translate("cameraWindow", "\346\265\217\350\247\210", 0));
        btn_show_2->setText(QApplication::translate("cameraWindow", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class cameraWindow: public Ui_cameraWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWINDOW_H
