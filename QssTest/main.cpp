#include "qsstest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QssTest w;
    w.show();
    return a.exec();
}
