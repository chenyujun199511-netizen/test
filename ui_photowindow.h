/********************************************************************************
** Form generated from reading UI file 'photowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOWINDOW_H
#define UI_PHOTOWINDOW_H

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

class Ui_photoWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_pictrue;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *photoWindow)
    {
        if (photoWindow->objectName().isEmpty())
            photoWindow->setObjectName(QStringLiteral("photoWindow"));
        photoWindow->resize(800, 480);
        centralwidget = new QWidget(photoWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_pictrue = new QLabel(centralwidget);
        label_pictrue->setObjectName(QStringLiteral("label_pictrue"));
        label_pictrue->setGeometry(QRect(0, 0, 800, 480));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 0, 120, 40));
        pushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        photoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(photoWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        photoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(photoWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        photoWindow->setStatusBar(statusbar);

        retranslateUi(photoWindow);

        QMetaObject::connectSlotsByName(photoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *photoWindow)
    {
        photoWindow->setWindowTitle(QApplication::translate("photoWindow", "MainWindow", 0));
        label_pictrue->setText(QString());
        pushButton->setText(QApplication::translate("photoWindow", "quit", 0));
    } // retranslateUi

};

namespace Ui {
    class photoWindow: public Ui_photoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOWINDOW_H
