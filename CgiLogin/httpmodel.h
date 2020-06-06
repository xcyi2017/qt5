#ifndef HTTPMODEL_H
#define HTTPMODEL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class HttpModel : public QObject
{
    Q_OBJECT
public:
    explicit HttpModel(QObject *parent = nullptr);
    void request(QString url);
signals:
    void recvData(QByteArray array);
private slots:
    void read_data();
    void read_finish();
private:
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    QByteArray dataArray;
};

#endif // HTTPMODEL_H
