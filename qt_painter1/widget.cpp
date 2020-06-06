#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->update();
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBackground(QBrush(Qt::red));
    //painter.setPen(Qt::red);
    painter.drawEllipse(20, 20, 100, 100);
}
