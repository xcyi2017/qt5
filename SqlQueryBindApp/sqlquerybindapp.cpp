#include "sqlquerybindapp.h"
#include "ui_sqlquerybindapp.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

SqlQueryBindApp::SqlQueryBindApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SqlQueryBindApp)
{
    ui->setupUi(this);
}

SqlQueryBindApp::~SqlQueryBindApp()
{
    delete ui;
}


void SqlQueryBindApp::on_bindBt_clicked()
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

void SqlQueryBindApp::on_mulBindBt_clicked()
{
    QVariantList names;
    names << "AAA" << "BBB" << "CCC";
    QVariantList sexs;
    sexs << "man" << "woman" << "man";
    QSqlQuery query;
    // 装备
    QString sql = "insert into student(name, sex) values(:name, :sex)";
    query.prepare(sql);

    query.addBindValue(names);
    query.addBindValue(sexs);
    query.execBatch();
}
