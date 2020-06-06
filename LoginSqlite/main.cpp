#include "loginsqlite.h"

#include <QApplication>

#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
    }
    QString sql = "create table if not exists user(id integer primary key autoincrement, username varchar(256) unique, password varchar(256))";
    QSqlQuery query;
    if (!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }
    LoginSqlite w;
    w.show();
    return a.exec();
}
