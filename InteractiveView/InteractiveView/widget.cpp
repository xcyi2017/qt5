#include "widget.h"

Widget::Widget(QWidget *parent)
    : InteractiveView(parent)
{
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 60, 60);
    rect->setBrush(QBrush(QColor(255, 0, 0, 50)));

    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(rect);
    scene->addPixmap(QPixmap(":/new/prefix1/img/map.jpg"));

    setScene(scene);
}

Widget::~Widget()
{

}
