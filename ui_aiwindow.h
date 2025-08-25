/********************************************************************************
** Form generated from reading UI file 'aiwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIWINDOW_H
#define UI_AIWINDOW_H

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

class Ui_aiWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *aiWindow)
    {
        if (aiWindow->objectName().isEmpty())
            aiWindow->setObjectName(QStringLiteral("aiWindow"));
        aiWindow->resize(800, 480);
        centralwidget = new QWidget(aiWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 131, 61));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(319, 210, 111, 61));
        aiWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(aiWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        aiWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(aiWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        aiWindow->setStatusBar(statusbar);

        retranslateUi(aiWindow);

        QMetaObject::connectSlotsByName(aiWindow);
    } // setupUi

    void retranslateUi(QMainWindow *aiWindow)
    {
        aiWindow->setWindowTitle(QApplication::translate("aiWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("aiWindow", "quit", 0));
        pushButton_2->setText(QApplication::translate("aiWindow", "\350\257\264\350\257\235\357\274\201", 0));
    } // retranslateUi

};

namespace Ui {
    class aiWindow: public Ui_aiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIWINDOW_H
