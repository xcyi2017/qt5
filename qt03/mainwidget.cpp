#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("lala");
    this->setGeometry(100, 100, 300, 300);

    b1.setParent(this);
    b1.setText("^_^");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText(QString("hello"));

    b->setParent(this);
    b->setText("Lambda表达式");
    b->move(150, 150);


    connect(b, &QPushButton::released,
            [b] () {
        b->setText("123");
        qDebug() << "11111111";
    }
            );

    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    // 自定义槽
    // 成员函数，普通全局函数，静态函数
    // 槽函数与信号一致
    // 槽函数没有返回值
    connect(b2, &QPushButton::released, this, &MainWidget::MySlot);

    connect(b2, &QPushButton::released, &b1, &MainWidget::hide);


    b3.setParent(this);
    b3.setText("切换子窗口");
    b3.move(50, 50);
    // 显示子窗口

     connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

     // 处理子窗口信号

     void (subWidget::*funcSignal) () = &subWidget::mySignal;
     connect(&w1, funcSignal, this, &MainWidget::dealSub);
     void (subWidget::*testSignal) (int, QString) = &subWidget::mySignal;
     connect(&w1, testSignal, this, &MainWidget::MySlot);
}

void MainWidget::MySlot() {
    b2->setText("123");
}

void MainWidget::changeWin() {
    w1.show();
    this->hide();
}

void MainWidget::dealSub() {
    this->show();
    w1.hide();
}

void MainWidget::dealSlot(int a, QString str) {
    qDebug() << a << str;
}

MainWidget::~MainWidget()
{

}
