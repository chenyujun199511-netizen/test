#include "photowindow.h"
#include "ui_photowindow.h"

photoWindow::photoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::photoWindow),
    index(0),
    m_timer(new QTimer(this))
{
    ui->setupUi(this);

    // 加载图片
    QDir dir("./background");
    if (!dir.exists()) {
        qDebug() << "Directory ./pic does not exist!";
        return;
    }

    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    dir.setNameFilters(QStringList() << "*.bmp" << "*.jpg" << "*.png" << "*.jpeg");
    fileList = dir.entryInfoList();

    if (fileList.isEmpty()) {
        qDebug() << "No images found in ./pic directory!";
        return;
    }

    qDebug() << "Found" << fileList.size() << "images:";
    for (const QFileInfo &fileInfo : fileList) {
        qDebug() << fileInfo.filePath();
    }

    // 显示第一张图片
    showCurrentImage();

    // 设置定时器
    connect(m_timer, &QTimer::timeout, this, &photoWindow::showNextImage);
    m_timer->start(3000); // 3秒切换一次
}

photoWindow::~photoWindow()
{
    m_timer->stop();
    delete m_timer;
    delete ui;
}

void photoWindow::showNextImage()
{
    if (!fileList.isEmpty()) {
        index = (index + 1) % fileList.size();
        showCurrentImage();
    }
}

void photoWindow::showCurrentImage()
{
    QString picName = fileList.at(index).filePath();
    QPixmap pic(picName);

    if (pic.isNull()) {
        qDebug() << "Failed to load image:" << picName;
        return;
    }

    pic = pic.scaled(ui->label_pictrue->size());

    ui->label_pictrue->setPixmap(pic);
    ui->label_pictrue->setAlignment(Qt::AlignCenter);
}

void photoWindow::on_pushButton_clicked()
{
    m_timer->stop();

    // 先获取父窗口的对象
    QWidget *parent = this->parentWidget();

    // 显示父窗口
    if (parent) {
        parent->show();
    }

    // 关闭子窗口
    this->close();
}
