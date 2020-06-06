#include "cgilogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CgiLogin w;
    w.show();

    return a.exec();
}
