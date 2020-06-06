#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QPushButton>
#include "subwidget.h" // 子窗口头文件

class MainWidget : public QMainWindow
{
    Q_OBJECT
    QPushButton b1;
    QPushButton* b2;
    QPushButton b3;
    subWidget w1;
    QPushButton *b;
public:
    MainWidget(QWidget *parent = 0);
    void MySlot();
    void changeWin();
    void dealSub();
    void dealSlot(int, QString);
    ~MainWidget();
};

#endif // MAINWIDGET_H
