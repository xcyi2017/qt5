#include "loginsqlite.h"
#include "ui_loginsqlite.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSettings>
#include <QCryptographicHash>

LoginSqlite::LoginSqlite(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginSqlite)
{
    ui->setupUi(this);
    QSettings setting(QSettings::IniFormat, QSettings::SystemScope, "./config");
    QString username = setting.value("username").toString();
    QString password = setting.value("password").toString();
    ui->userEdit->setText(username);
    ui->passwordEdit->setText(password);
}

LoginSqlite::~LoginSqlite()
{
    delete ui;
}

QString LoginSqlite::password_md5(QString password)
{
    // 创建加密对象
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(password.toUtf8());
    QByteArray pass = hash.result(); // 16个字节
    qDebug() << pass.size();
    return pass.toHex();
}
void LoginSqlite::on_checkBt_clicked()
{
    QString username = ui->userEdit->text();
    QString password = ui->passwordEdit->text();
    QString sql = QString("select * from user where username='%1' and password='%2'")
            .arg(username).arg(password_md5(password));
    QSqlQuery query;
    if (!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }
    if(query.next())
    {// 指向
         qDebug() << "查询到记录\n";
         if (ui->checkBox->isChecked())
         {
             QSettings setting(QSettings::IniFormat, QSettings::SystemScope, "./config");
             setting.setValue("username", username);
             setting.setValue("password", password);
         }
         QMessageBox::warning(this, "登录", "登录成功");
    }


    else
    {
       qDebug() << "未查询到记录";
       QMessageBox::warning(this, "登录", "登录失败");
    }
    QSqlRecord record = query.record();
    qDebug() << record.value("username").toString() << "\n";
    qDebug() << record.value("password").toString() << "\n";
}


void LoginSqlite::on_regBt_clicked()
{
    QString username = ui->userEdit->text();
    QString password = password_md5(ui->passwordEdit->text());
    QSqlQuery query;
    QString sql = QString("insert into user(username, password) values('%1', '%2')").arg(username).arg(password);
    if (!query.exec(sql))
    {
        qDebug() << query.lastError().text();
        QMessageBox::warning(this, "注册", "注册失败");
    }
    else{
        QMessageBox::warning(this, "注册", "注册成功");
    }
}
