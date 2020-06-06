#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->frame->setParent(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPainter *p)
{
    p = new QPainter(ui->frame);
    p->setBrush(Qt::red);
    p->setBackground(Qt::SolidPattern);
    QSize t = ui->frame->size();
    p->drawRect(t.width() + 100, t.height() + 100, 20, 20);
}
