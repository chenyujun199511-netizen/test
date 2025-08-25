#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QMainWindow>

namespace Ui {
class chooseWindow;
}

class chooseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit chooseWindow(QWidget *parent = nullptr);
    ~chooseWindow();

private:
    Ui::chooseWindow *ui;
};

#endif // CHOOSEWINDOW_H
