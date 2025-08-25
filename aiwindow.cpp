#include "aiwindow.h"
#include "ui_aiwindow.h"
#include "window.h"
#include "photowindow.h"
#include "ledwindow.h"
#include "camerawindow.h"

aiWindow::aiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aiWindow)
{
    ui->setupUi(this);
}

aiWindow::~aiWindow()
{
    delete ui;

    ::close(fd);
    ::close(sock_fd);
}

void aiWindow::on_pushButton_clicked()
{
    //获取父类的窗口
    QWidget *parent = this->parentWidget();
    //显示父类的窗口
    parent->show();
    //关闭当前的子窗口
    this->close();
    //销毁子窗口
    delete this;
}

void aiWindow::on_pushButton_2_clicked()
{
    printf("开始录音\n");
    system("arecord -d5 -c1 -r16000 -twav -fS16_LE 1.wav");

    // 创建套接字
    sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket 创建失败");
        return;
    }

    // 绑定地址
    struct sockaddr_in srvaddr;
    srvaddr.sin_family = AF_INET;  // 改用 AF_INET（更标准）
    srvaddr.sin_port = htons(55555);
    srvaddr.sin_addr.s_addr = inet_addr("192.168.2.22");

    // 连接服务器
    ret = ::connect(sock_fd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));
    if (ret < 0) {
        perror("connect 失败");
        ::close(sock_fd);
        return;
    }

    // 发送音频文件
    fd = open("1.wav", O_RDONLY);  // 改为 O_RDONLY（无需写权限）
    if (fd < 0) {
        perror("open() failed");
        ::close(sock_fd);
        return;
    }

    // 获取文件大小并发送
    int file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    if (send(sock_fd, &file_size, sizeof(file_size), 0) <= 0) {
        perror("send file_size failed");
        ::close(fd);
        ::close(sock_fd);
        return;
    }

    // 发送文件内容
    char buf[1024];
    while (1) {
        int ret_rd = read(fd, buf, sizeof(buf));
        if (ret_rd <= 0) break;
        if (send(sock_fd, buf, ret_rd, 0) <= 0) {
            perror("send failed");
            break;
        }
    }

    // 接收服务器返回的识别结果
    bzero(buf, sizeof(buf));
    int received = recv(sock_fd, buf, sizeof(buf) - 1, 0);  // 保留空间给 \0
    if (received <= 0) {
        printf("接收失败\n");
        ::close(fd);
        ::close(sock_fd);
        return;
    }
    buf[received] = '\0';  // 确保字符串终止

    // 去除换行符和空格
    char *trimmed = buf;
    while (*trimmed == ' ' || *trimmed == '\n') trimmed++;

    printf("服务器返回原始数据: ");
    for (int i = 0; i < received; i++) printf("%02x ", buf[i]);  // 打印十六进制
    printf("\n");
    printf("服务器返回文本: %s\n", trimmed);

    // 根据识别结果跳转（改用 else if 确保只匹配一个）
    if (strstr(trimmed, "相册")) {
        printf("跳转相册\n");
        photoWindow *msg1 = new photoWindow(this);
        msg1->setAttribute(Qt::WA_DeleteOnClose);
        msg1->show();
        this->hide();
    }
    else if (strstr(trimmed, "相机")) {
        printf("跳转相机\n");
        cameraWindow *msg2 = new cameraWindow(this);
        msg2->setAttribute(Qt::WA_DeleteOnClose);
        msg2->show();
        this->hide();
    }
    else if (strstr(trimmed, "灯")) {
        printf("跳转LED控制\n");
        LedWindow *msg3 = new LedWindow(this);
        msg3->setAttribute(Qt::WA_DeleteOnClose);
        msg3->show();
        this->hide();
    }
    else if (strstr(trimmed, "蜂鸣器")) {
        printf("触发蜂鸣器\n");
        int fd_beep = open("/dev/beep", O_WRONLY);
        if (fd_beep == -1) {
            perror("open /dev/beep failed");
        } else {
            ioctl(fd_beep, 1, 1);  // 触发蜂鸣器
            ::close(fd_beep);
        }
    }
    else {
        printf("未识别的命令: %s\n", trimmed);
    }

    // 关闭文件描述符
    ::close(fd);
    ::close(sock_fd);
}

