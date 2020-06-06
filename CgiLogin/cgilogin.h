#ifndef CGILOGIN_H
#define CGILOGIN_H

#include <QMainWindow>
#include <httpmodel.h>
namespace Ui {
class CgiLogin;
}
class CgiLogin : public QMainWindow
{
    Q_OBJECT
public:
    explicit CgiLogin(QWidget *parent = nullptr);
    ~CgiLogin();
private slots:
    void read_data(QByteArray array);
    void on_loginBt_clicked();

    void on_registerBt_clicked();
private:
    QString password_md5(QString inputpass);
private:
    Ui::CgiLogin *ui;
    int type; //注册0， 登录1
    HttpModel *httpModel;

};

#endif // CGILOGIN_H
