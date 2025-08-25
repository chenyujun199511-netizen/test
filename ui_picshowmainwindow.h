/********************************************************************************
** Form generated from reading UI file 'picshowmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICSHOWMAINWINDOW_H
#define UI_PICSHOWMAINWINDOW_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PicShowMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_prev;
    QPushButton *btn_next;
    QPushButton *btn_back;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PicShowMainWindow)
    {
        if (PicShowMainWindow->objectName().isEmpty())
            PicShowMainWindow->setObjectName(QStringLiteral("PicShowMainWindow"));
        PicShowMainWindow->resize(800, 480);
        centralwidget = new QWidget(PicShowMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 640, 480));
        label->setStyleSheet(QStringLiteral("background-color: rgb(216, 216, 216);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(680, 90, 81, 211));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_prev = new QPushButton(widget);
        btn_prev->setObjectName(QStringLiteral("btn_prev"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_prev->sizePolicy().hasHeightForWidth());
        btn_prev->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btn_prev);

        btn_next = new QPushButton(widget);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        sizePolicy.setHeightForWidth(btn_next->sizePolicy().hasHeightForWidth());
        btn_next->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btn_next);

        btn_back = new QPushButton(widget);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        sizePolicy.setHeightForWidth(btn_back->sizePolicy().hasHeightForWidth());
        btn_back->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btn_back);

        PicShowMainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(PicShowMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        PicShowMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(PicShowMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PicShowMainWindow->setStatusBar(statusBar);

        retranslateUi(PicShowMainWindow);

        QMetaObject::connectSlotsByName(PicShowMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PicShowMainWindow)
    {
        PicShowMainWindow->setWindowTitle(QApplication::translate("PicShowMainWindow", "MainWindow", 0));
        label->setText(QString());
        btn_prev->setText(QApplication::translate("PicShowMainWindow", "\344\270\212\344\270\200\345\274\240", 0));
        btn_next->setText(QApplication::translate("PicShowMainWindow", "\344\270\213\344\270\200\345\274\240", 0));
        btn_back->setText(QApplication::translate("PicShowMainWindow", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class PicShowMainWindow: public Ui_PicShowMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICSHOWMAINWINDOW_H
