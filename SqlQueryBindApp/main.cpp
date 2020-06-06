#include "sqlquerybindapp.h"

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

    QString sql = QString("create table if not exists student(id integer primary key autoincrement,"
                  "name varchar(256),"
                  "sex varchar(16))");

    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }


    SqlQueryBindApp w;
    w.show();
    return a.exec();
}
