#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class subWidget : public QWidget
{
    Q_OBJECT
    QPushButton b1;
public:
    explicit subWidget(QWidget *parent = 0);

signals:
    void mySignal();
    void mySignal(int, QString);

public slots:
    void sendSlot();
};

#endif // SUBWIDGET_H
