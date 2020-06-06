#include "hwtablemodelapp.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
    }

    QString sql = QString("create table if not exists homework(id integer primary key autoincrement,"
                          "class varchar(256) not null,"
                          "name varchar(256) not null,"
                          "time varchar(256) not null,"
                          "hwname varchar(256) not null)");

    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }

    HWTablemodelApp w;
    w.show();
    return a.exec();
}
