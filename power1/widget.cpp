#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPainter *)
{
    QPainter p(this);
    p.setPen(Qt::red);
    //QSize size = ui->frame->size();
    p.drawRect(10, 10, 20, 20);
}
