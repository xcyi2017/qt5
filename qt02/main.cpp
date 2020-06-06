#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("hello world");
    w.setGeometry(100, 100, 300, 300);
    QPushButton b(&w);
    b.setText("^_^");
    b.move(100, 100);
    w.show();

    return a.exec();
}
