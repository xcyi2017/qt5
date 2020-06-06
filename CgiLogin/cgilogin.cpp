#include "cgilogin.h"
#include "ui_cgilogin.h"

CgiLogin::CgiLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CgiLogin)
{
    ui->setupUi(this);
    httpModel = new HttpModel;
    connect(httpModel, &HttpModel::recvData, this, &CgiLogin::read_data);
}

CgiLogin::~CgiLogin()
{
    delete ui;
}

void CgiLogin::read_data(QByteArray array)
{
    qDebug()<<QString(array);
    //根据type值来确认是登录/注册成功或失败
    if(type == 0)
    {
        if(QString(array)=="0") qDebug()<<"注册成功";
        else qDebug()<<"注册失败";
    }else if(type == 1)
    {
        if(QString(array)=="0") qDebug()<<"登录成功";
        else qDebug()<<"登录失败";
    }
}

QString CgiLogin::password_md5(QString inputpass)
{
    //创建加密对象
    QCryptographicHash hash(QCryptographicHash::Md5);
    //添加明文数据
    hash.addData(inputpass.toUtf8());
    //获取加密后的数据
    QByteArray  pass = hash.result();//16个字节的数据， md5数据就是把这个16个自己转十六进制
    //把pass转十六进制
    return pass.toHex();
}
void CgiLogin::on_loginBt_clicked()
{
    type = 1;
    QString username = ui->userEdit->text();
    QString password = ui->passEdit->text();
    //加密密码
    password = password_md5(password);

    //发送登录请求
    //http://192.168.0.102/cgi-bin/register_login?type=1&username=xxx&password=xxx
    QString url = QString("http://192.168.0.102/cgi-bin/student/register_login?"
                          "type=1&username=%1&password=%2").arg(username).arg(password);
    httpModel->request(url);
}

void CgiLogin::on_registerBt_clicked()
{
    type=0;
    //发送注册请求
    QString username = ui->userEdit->text();
    QString password = ui->passEdit->text();
    //加密密码
    password = password_md5(password);

    //发送登录请求
    //http://192.168.0.102/cgi-bin/register_login?type=0&username=xxx&password=xxx
    QString url = QString("http://192.168.0.102/cgi-bin/student/register_login?"
                          "type=0&username=%1&password=%2").arg(username).arg(password);
    httpModel->request(url);
}
