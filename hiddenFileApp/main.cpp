#include "hiddenfileapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hiddenFileApp w;
    w.show();
    return a.exec();
}
