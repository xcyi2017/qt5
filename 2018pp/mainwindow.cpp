#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            s[i][j]=0;
        }
    }
    button = new QPushButton("开始游戏",this);
    button->setGeometry(60,400,200,50);//从(60,400)做一个200*50的按钮
    //随机函数
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));

    connect(button,SIGNAL(clicked()),this,SLOT(slotStart()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setBrush(Qt::blue);
    p.setFont(QFont("微软雅黑",20,700,false));

    QString strscore;
    p.drawText(QPoint(20,60),"分数: "+QString::number(score));

    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            p.setPen(Qt::transparent);//?
            if(s[i][j]==0){
                p.setBrush(Qt::gray);
                p.drawRect(i*60+40,j*60+120,55,55);
            }
            else if (s[i][j]==2) {
                p.setBrush(Qt::red);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方块中 绘制Text， 并且文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(2),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==4) {
                p.setBrush(Qt::darkRed);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(4),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==8) {
                p.setBrush(Qt::green);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(8),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==16) {
                p.setBrush(Qt::darkGreen);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(16),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==32) {
                p.setBrush(Qt::yellow);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(32),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==64) {
                p.setBrush(Qt::darkYellow);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(64),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==128) {
                p.setBrush(Qt::cyan);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(128),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==256) {
                p.setBrush(Qt::darkCyan);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(256),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==512) {
                p.setBrush(Qt::magenta);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(512),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==1024) {
                p.setBrush(Qt::darkMagenta);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(1024),QTextOption(Qt::AlignCenter));
            }
            else if (s[i][j]==2048) {
                p.setBrush(Qt::blue);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(2048),QTextOption(Qt::AlignCenter));
            }
            else{
                p.setBrush(Qt::darkBlue);
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(s[i][j]),QTextOption(Qt::AlignCenter));
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!state){
        return ;
    }
        switch (event->key()) {
        case Qt::Key_W:
            PressUp();
            break;

        case Qt::Key_S:
            PressDown();
            break;

        case Qt::Key_A:
            PressLeft();
            break;

        case Qt::Key_D:
            PressRight();
            break;

        default:
            return;//忽略其他按钮
        }
        myRand();
        update();
}
void MainWindow::slotStart(){
    QMessageBox::about(this,"游戏规则","WSAD控制方块上下左右移动");
    score=0;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            s[i][j]=0;
        }
    }
    button->setText("重新游戏");

    int randi=qrand()%4;
    int randj=qrand()%4;
    s[randi][randj]=2;

    state=true;
    update();
}
void MainWindow::PressUp(){
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
void MainWindow::PressDown(){
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
void MainWindow::PressLeft(){
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
void MainWindow::PressRight(){
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
void MainWindow::myRand(){
    int i=0,j=0;
    //找出格子
    struct Ns n[15];
    int ni=0;
    for (i=0;i<4;i++) {
        for (j=0;j<4;j++) {
            if(s[i][j]==0){
                n[ni].i=i;
                n[ni].j=j;
                ni++;
            }
        }
    }

    //判断游戏是否结束
    if (ni==0) {
        for (i=0;i<4;i++) {
            for (j=0;j<3;j++) {
                if(s[i][j]==s[i][j+1]){
                    return;
                }
            }
        }
        for (j=0;j<4;j++) {
            for (i=0;i<3;i++) {
                if(s[i][j]==s[i+1][j]){
                    return;
                }
            }
        }
        QMessageBox::about(this,"游戏失败","分数为："+QString::number(score)+" ");
        return;
    }
    int rand=qrand()%ni;
    s[n[rand].i][n[rand].j]=2;
}
