#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent), currShapeCode(Shape::Line), shape(null), perm(false)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void PaintWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, size.width(), size.height());
    foreach(Shape* shape, shapelist) {
        shape->paint(painter);
    }
    if (shape) {
        shape->paint(painter);
    }
}


void PaintWidget::mousePressEvent(QMouseEvent *event) {
    switch (currShapeCode) {
    case Shape::line:
    {
        shape = new Line;
        break;
    }
    case Shape::Rect:
    {
        shape = new Rect;
    }
    }
    if (shape != NULL) {
        perm = false;
        shapelist << shape;
        shape->setStart(event->pos());
        shape->setEnd(event->pos());
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event) {
    if (shape && !perm) {
        shape->setEnd(event->pos());
        update();
    }
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *) {
    perm = true;
}
