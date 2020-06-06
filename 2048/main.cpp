#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(200, 200, 300, 500);
    w.setWindowTitle("2048");
    w.show();

    return a.exec();
}
