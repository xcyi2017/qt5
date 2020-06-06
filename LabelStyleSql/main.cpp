#include "labelstylesql.h"

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

    QString sql = QString("create table if not exists label(id integer primary key autoincrement,"
                  "border_size int,"
                  "border_color varchar(16),"
                  "border_radius int,"
                  "background_color varchar(16),"
                  "color varchar(16))");

    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }


    LabelStyleSql w;
    w.show();
    return a.exec();
}
