#include "createsqlapp.h"
#include "ui_createsqlapp.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

CreateSqlApp::CreateSqlApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateSqlApp)
{
    ui->setupUi(this);
    QSqlQuery query;
    // 执行创建表格的语句
    if(!query.exec("create table if not exists student(id int, name text)"))
    {
        qDebug() << query.lastError().text();
    }
}

CreateSqlApp::~CreateSqlApp()
{
    delete ui;
}


void CreateSqlApp::on_pushButton_clicked()
{
    QSqlQuery query;
    QString sql = QString("insert into student values(%1, '%2')").arg(ui->idEdit->text())
            .arg(ui->nameEdit->text());
    // 插入语句
    query.exec(sql);
}
