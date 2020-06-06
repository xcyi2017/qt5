#ifndef MYPAINT_H
#define MYPAINT_H

#include <QWidget>

class myPaint : public QWidget
{
    Q_OBJECT

public:
    myPaint(QWidget *parent = nullptr);
    ~myPaint();
};

#endif // MYPAINT_H
