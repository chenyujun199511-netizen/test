/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_video;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QPushButton *btn_capture;
    QPushButton *btn_show;
    QPushButton *btn_show_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 480);
        label_video = new QLabel(Widget);
        label_video->setObjectName(QStringLiteral("label_video"));
        label_video->setGeometry(QRect(0, 0, 640, 480));
        label_video->setStyleSheet(QStringLiteral("background-color: rgb(158, 158, 158);"));
        btn_start = new QPushButton(Widget);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(660, 10, 111, 61));
        btn_stop = new QPushButton(Widget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        btn_stop->setGeometry(QRect(660, 90, 111, 61));
        btn_capture = new QPushButton(Widget);
        btn_capture->setObjectName(QStringLiteral("btn_capture"));
        btn_capture->setGeometry(QRect(660, 170, 111, 61));
        btn_show = new QPushButton(Widget);
        btn_show->setObjectName(QStringLiteral("btn_show"));
        btn_show->setGeometry(QRect(660, 260, 111, 61));
        btn_show_2 = new QPushButton(Widget);
        btn_show_2->setObjectName(QStringLiteral("btn_show_2"));
        btn_show_2->setGeometry(QRect(660, 350, 111, 61));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_video->setText(QString());
        btn_start->setText(QApplication::translate("Widget", "\345\274\200\345\220\257", 0));
        btn_stop->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", 0));
        btn_capture->setText(QApplication::translate("Widget", "\346\212\223\346\213\215", 0));
        btn_show->setText(QApplication::translate("Widget", "\346\265\217\350\247\210", 0));
        btn_show_2->setText(QApplication::translate("Widget", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
