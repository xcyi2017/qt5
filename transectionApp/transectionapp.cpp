#include "transectionapp.h"
#include "ui_transectionapp.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

transectionApp::transectionApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::transectionApp)
{
    ui->setupUi(this);
}

transectionApp::~transectionApp()
{
    delete ui;
}


void transectionApp::on_commitBt_clicked()
{
    QSqlDatabase::database().commit();
}

void transectionApp::on_beginBt_clicked()
{
    //开启事务处理
    if(QSqlDatabase::database().transaction())
    {
        qDebug() << "开启成功";
        return;
    }
    qDebug() << "开启失败";
}

void transectionApp::on_rollbackBt_clicked()
{
    QSqlDatabase::database().rollback();
}

void transectionApp::on_insertBt_clicked()
{
    QSqlQuery query;
    // 装备
    QString sql = "insert into student(name, sex) values(:name, :sex)";
    query.prepare(sql);

    // 绑定数据
    query.bindValue(0, ui->nameEdit->text());
    query.bindValue(1, ui->sexEdit->text());
    query.exec();
}

void transectionApp::on_searchBt_clicked()
{
    QSqlQuery query;
    // 装备
    QString sql = "select * from student";
    query.exec(sql);
    while(query.next())
    {
        qDebug() << query.record().value("name").toString();
    }
}
