#include "choosewindow.h"
#include "ui_choosewindow.h"

chooseWindow::chooseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chooseWindow)
{
    ui->setupUi(this);
}

chooseWindow::~chooseWindow()
{
    delete ui;
}
