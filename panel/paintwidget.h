#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H
#include <QtGui>
#include <QDebug>
#include "shape.h"
class PaintWidget : public QWidget {
    Q_OBJECT
public:
    PaintWidget(QWidget *parent = 0);
public slots:
    inline
    void setCurrentShape (Shape::Code s) {
        if (s != currShapeCode) {
            s = currShapeCode;
        }
    }
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
private:
    Shape::Code currShapeCode;
    Shape *shape;
    bool perm;
    QList<Shape*> shapelist;
};

#endif // PAINTWIDGET_H

