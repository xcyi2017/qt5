#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            s[i][j] = 0;
        }
    }
    button = new QPushButton("开始游戏", this);
    button->setGeometry(60, 400, 200, 50);

    // 随机种子
    qsrand(uint(QTime(0, 0, 0).secsTo(QTime::currentTime())));

    // 槽与信号
    connect(button, SIGNAL(clicked()), this, SLOT(slotStart()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setBrush(Qt::blue);
    p.setFont(QFont("微软雅黑", 20, 700, false));

    QString strScore;
    p.drawText(QPoint(20, 60), "分数 " + QString::number(score));

    // 格子实现
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            p.setPen(Qt::transparent);
            switch (s[i][j]) {
            case 0:
                p.setBrush(Qt::gray);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                break;

            case 2:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(2), QTextOption(Qt::AlignCenter));
                break;

            case 4:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(4), QTextOption(Qt::AlignCenter));
                break;

            case 8:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(8), QTextOption(Qt::AlignCenter));
                break;

            case 16:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(16), QTextOption(Qt::AlignCenter));
                break;
            case 32:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(32), QTextOption(Qt::AlignCenter));
                break;
            case 64:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(64), QTextOption(Qt::AlignCenter));
                break;
            case 128:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(128), QTextOption(Qt::AlignCenter));
                break;
            case 256:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(256), QTextOption(Qt::AlignCenter));
                break;
            case 512:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(512), QTextOption(Qt::AlignCenter));
                break;
            case 1024:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(1024), QTextOption(Qt::AlignCenter));
                break;
            case 2048:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(2048), QTextOption(Qt::AlignCenter));
                break;
            case 4096:
                p.setBrush(Qt::red);
                p.drawRect(i * 60 + 40, j * 60 + 120, 55, 55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑", 10, 700, false));
                p.drawText(QRectF(i * 60 + 40, j * 40 + 120, 55, 55), QString::number(4096), QTextOption(Qt::AlignCenter));
                break;
            default:
                break;
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!state) {
        return;
    }
    switch (event->key()) {
    case Qt::Key_W:
        pressUp();
        break;
    case Qt::Key_S:
        pressDown();
        break;
    case Qt::Key_A:
        pressLeft();
        break;
    case Qt::Key_D:
        pressRight();
        break;
    default:
        return;
    }
    myRand();
    update(); // 强制界面刷新
}

void MainWindow::pressUp()
{
    //移动
        for (int i=0;i<4;i++) {
            for (int j=1;j<4;j++) {
                if(s[i][j]==0)continue;
                for (int p=0;p<j;p++) {
                    //查看前面是否有空格子可移动
                    if(s[i][p]==0){
                        s[i][p]=s[i][j];
                        s[i][j]=0;
                        break;
                    }
                }
            }
        }
        //相加
        for (int i=0;i<4;i++) {
            for (int j=0;j<3;j++) {
                if(s[i][j]==s[i][j+1]){
                    s[i][j]=2*s[i][j];
                    s[i][j+1]=0;
                    score+=s[i][j];
                    for (int p=j+2;p<4;p++) {
                        s[i][p-1]=s[i][p];
                    }
                }
            }
        }
}

void MainWindow::pressDown()
{
    //移动
        for (int i=0;i<4;i++) {
            for (int j=2;j>=0;j--) {
                if(s[i][j]==0)continue;
                for (int p=3;p>j;p--) {
                    //查看前面是否有空格子可移动
                    if(s[i][p]==0){
                        s[i][p]=s[i][j];
                        s[i][j]=0;
                        break;
                    }
                }
            }
        }
        //相加
        for (int i=0;i<4;i++) {
            for (int j=3;j>0;j--) {
                if(s[i][j]==s[i][j-1]){
                    s[i][j]=2*s[i][j];
                    s[i][j-1]=0;
                    score+=s[i][j];
                    for (int p=j-2;p>=0;p--) {
                        s[i][p+1]=s[i][p];
                    }
                }
            }
        }
}

void MainWindow::pressLeft()
{
    //移动
        for (int j=0;j<4;j++) {
            for (int i=1;i<4;i++) {
                if(s[i][j]==0){
                    continue;
                }
                for (int p=0;p<i;p++) {
                    //查看前面是否有空格可移入
                    if(s[p][j] == 0){
                        s[p][j] = s[i][j];
                        s[i][j] = 0;
                        break;
                    }
                }
            }
        }
        //相加
        for (int j=0;j<4;j++) {
            for (int i=0;i<3;i++) {
                if(s[i][j]==s[i+1][j]){
                    s[i][j]=s[i][j]*2;
                    score+=s[i][j];
                    s[i+1][j]=0;
                    for(int p=i+2;p<4;p++){
                        s[p-1][j] = s[p][j];
                   }
                }
            }
        }
}

void MainWindow::pressRight()
{
    //移动
        for (int j=0;j<4;j++) {
            for (int i=2;i>=0;i--) {
                if(s[i][j]==0){
                    continue;
                }
                for (int p=3;p>i;p--) {
                    //查看前面是否有空格可移入
                    if(s[p][j] == 0){
                        s[p][j] = s[i][j];
                        s[i][j] = 0;
                        break;
                    }
                }
            }
        }
        //相加
        for (int j=0;j<4;j++) {
            for (int i=3;i>=0;i--) {
                if(s[i][j]==s[i-1][j]){
                    s[i][j]=s[i][j]*2;
                    s[i-1][j]=0;
                    score+=s[i][j];
                    for(int p=i-2;p>=0;p--){
                        s[p+1][j] = s[p][j];
                    }
                }
            }
        }
}

void MainWindow::myRand()
{
    struct Ns n[15];
    int ni = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; i < 4; ++j) {
            if (s[i][j] == 0) {
                n[ni].x = i;
                n[ni].y = j;
                ++ni;
            }
        }
    }

    // 判断游戏是否结束
    if (ni == 0) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (s[i][j] == s[i][j+1]) {
                    return;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (s[i][j] == s[i+1][j]) {
                    return;
                }
            }
        }
        QMessageBox::about(this, "游戏失败", "游戏的分数为: " + QString::number(score));
        return;
    }
    int rand = qrand() % ni;
    qDebug() << n[rand].x  << " " << n[rand].y << endl;
    s[n[rand].x][n[rand].y] = 2;

}

void MainWindow::slotStart()
{
    QMessageBox::about(this, "游戏规则", "WASD控制方块上下左右");
    score = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            s[i][j] = 0;
        }
    }
    button->setText("重新开始游戏");
    int randi = qrand()%4;
    int randj = qrand()%4;
    s[randi][randj] = 2;
    state = true;
    update();
}
