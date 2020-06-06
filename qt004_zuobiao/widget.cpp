#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    move(100, 100);

    QPushButton *b = new QPushButton(this);
    b->move(100, 100);
    b->setText("^_^");
    b->resize(50, 50);

    QPushButton *b1 = new QPushButton(b);

    b1->setText("@");
    b1->resize(20, 20);
}

Widget::~Widget()
{
    delete ui;
}
