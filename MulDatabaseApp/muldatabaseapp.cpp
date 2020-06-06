#include "muldatabaseapp.h"
#include "ui_muldatabaseapp.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>

MulDatabaseApp::MulDatabaseApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MulDatabaseApp)
{
    ui->setupUi(this);
}

MulDatabaseApp::~MulDatabaseApp()
{
    delete ui;
}


void MulDatabaseApp::on_insertBt_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString sql = QString("insert into user(username, password) values('%1', '%2')").arg(username)
            .arg(password);
    // 创建与数据库对应的对象
    if (ui->Acheck->isChecked())
    {
        qDebug() << "向A数据库插入数据\n";
        QSqlQuery query(QSqlDatabase::database("Adb"));
        query.exec(sql);
    }
    if (ui->Bcheck->isChecked())
    {
        qDebug() << "向B数据库插入数据\n";
        QSqlQuery query(QSqlDatabase::database("Bdb"));
        query.exec(sql);
    }
}
