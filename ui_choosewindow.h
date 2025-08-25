/********************************************************************************
** Form generated from reading UI file 'choosewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEWINDOW_H
#define UI_CHOOSEWINDOW_H

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

class Ui_chooseWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chooseWindow)
    {
        if (chooseWindow->objectName().isEmpty())
            chooseWindow->setObjectName(QStringLiteral("chooseWindow"));
        chooseWindow->resize(800, 480);
        chooseWindow->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QPushButton #pushButton #pushButton_2\n"
"{\n"
"	border:1px solid #0000ff;\n"
"    border-radius:50px;\n"
"}"));
        centralwidget = new QWidget(chooseWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 180, 100, 100));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 180, 100, 100));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 0, 120, 40));
        chooseWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chooseWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        chooseWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(chooseWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        chooseWindow->setStatusBar(statusbar);

        retranslateUi(chooseWindow);

        QMetaObject::connectSlotsByName(chooseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *chooseWindow)
    {
        chooseWindow->setWindowTitle(QApplication::translate("chooseWindow", "MainWindow", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QApplication::translate("chooseWindow", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class chooseWindow: public Ui_chooseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEWINDOW_H
