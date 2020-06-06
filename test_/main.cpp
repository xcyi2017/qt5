#include "list_.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    list_ w;
    w.show();
    return a.exec();
}
