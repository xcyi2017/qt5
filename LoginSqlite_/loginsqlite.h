#ifndef LOGINSQLITE_H
#define LOGINSQLITE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginSqlite; }
QT_END_NAMESPACE

class LoginSqlite : public QMainWindow
{
    Q_OBJECT

public:
    LoginSqlite(QWidget *parent = nullptr);
    ~LoginSqlite();

private slots:
    void on_checkBt_clicked();


    void on_regBt_clicked();

private:
    Ui::LoginSqlite *ui;
    QString password_md5(QString password);
};
#endif // LOGINSQLITE_H
