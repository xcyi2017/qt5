#include "citynameapp.h"

#include <QApplication>
int init_data();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    init_data();
    CityNameApp w;
    w.show();
    return a.exec();
}
