#include "createsqlapp.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 创建数据库链接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // 设置数据库名称
    db.setDatabaseName("my.db");
    // 打开数据库
    if(!db.open())
    {
        qDebug() << db.lastError().text(); // 输出错误信息
    }
    // 创建数据库表格

    CreateSqlApp w;
    w.show();
    return a.exec();
}
