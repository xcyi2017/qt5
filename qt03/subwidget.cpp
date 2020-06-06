#include "subwidget.h"

subWidget::subWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("小弟");
    b1.setParent(this);
    b1.setText("切换到主窗口");
    b1.setGeometry(200, 200, 400, 400);
    connect(&b1, &QPushButton::clicked, this, &subWidget::sendSlot);
}

void subWidget::sendSlot() {
    emit mySignal();
    emit mySignal(250, "我是窗口");
}
