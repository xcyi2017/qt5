#include "muldatabaseapp.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase Adb = QSqlDatabase::addDatabase("QSQLITE", "Adb");
    Adb.setDatabaseName("Amy.db");
    if (!Adb.open())
    {
        qDebug() << Adb.lastError().text();
    }

    QSqlDatabase Bdb = QSqlDatabase::addDatabase("QSQLITE", "Bdb");
    Bdb.setDatabaseName("Bmy.db");
    if (!Bdb.open())
    {
        qDebug() << Bdb.lastError().text();
    }
    QString sql = "create table if not exists user(id integer primary key autoincrement,"
                  " username varchar(256) unique, password varchar(256))";

    QSqlQuery queryA(Adb);

    queryA.exec(sql);

    QSqlQuery queryB(Bdb);
    queryB.exec(sql);

    MulDatabaseApp w;
    w.show();
    return a.exec();
}
