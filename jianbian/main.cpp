#include "lightpoint.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LightPoint w;
    w.show();

    return a.exec();
}
