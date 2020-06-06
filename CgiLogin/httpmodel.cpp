#include "httpmodel.h"

HttpModel::HttpModel(QObject *parent) : QObject(parent)
{

}

void HttpModel::read_data()
{
    QByteArray array = reply->readAll();
    //qDebug()<<"----"<<QString(array);
    dataArray.append(array);//接收一段追加一段
}

void HttpModel::read_finish()
{
    //读取完成
    emit recvData(dataArray);
    //当应答对象有数据可读的时候会发送readyRead信号--在槽函数中读取数据
    disconnect(reply,&QNetworkReply::readyRead,this, &HttpModel::read_data);
    //reply对想接收数据后会在适当的时候发送下在进度信号
    disconnect(reply, &QNetworkReply::finished,this, &HttpModel::read_finish);
    reply->deleteLater();//释放应答对应
}

void HttpModel::request(QString url)
{
    QUrl _url(url);//
    //创建请求对象
    QNetworkRequest request;
    request.setUrl(_url);
    //发送请求
    dataArray.clear();//清空存储数据的容器
    reply = manager.get(request);
    //当应答对象有数据可读的时候会发送readyRead信号--在槽函数中读取数据
    connect(reply,&QNetworkReply::readyRead,this, &HttpModel::read_data);
    //reply对想接收数据后会在适当的时候发送下在进度信号
    connect(reply, &QNetworkReply::finished,this, &HttpModel::read_finish);
}
