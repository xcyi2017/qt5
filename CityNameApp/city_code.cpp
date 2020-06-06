#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QJsonParseError>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>

int init_data()
{
    // 连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cityname.db");
    if (!db.open())
    {
        qDebug() << "打开数据库" << db.lastError().text();
        return -1;
    }

    // 创建一个数据表--省
    QString province = "CREATE TABLE if not exists province"
                       "(id integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
                       "name varchar(30) NOT NULL,"
                       "code varchar(6) NOT NULL)";
    QSqlQuery query;
    if (!query.exec(province))
    {
        qDebug() << "创建省表" << query.lastError().text();
        return -1;
    }
    // 创建一个数据表--市
    QString city = "CREATE TABLE if not exists city"
                       "(id integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
                       "name varchar(37) NOT NULL,"
                       "code varchar(6) NOT NULL,"
                       "province_id integer NOT NULL)";
    if (!query.exec(city))
    {
        qDebug() << "创建市表" << query.lastError().text();
        return -1;
    }

    // 创建一个数据表--县
    QString country = "CREATE TABLE if not exists country"
                       "(id integer NOT NULL PRIMARY KEY AUTOINCREMENT,"
                       "name varchar(52) NOT NULL,"
                       "code varchar(6) NOT NULL,"
                       "city_id integer NOT NULL,"
                       "province_id integer NOT NULL)";
    if (!query.exec(country))
    {
        qDebug() << "创建县表" << query.lastError().text();
        return -1;
    }

    // 打开资源文件中的路径--只能是以只读方式打开
    QFile file(":/file/city_code.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "open error";
    }
    QByteArray array;
    while (!file.atEnd())
    {
        QByteArray tmp = file.read(1024*10); // 读取一段
        array.append(tmp); // 存储一段
    }
    file.close(); // 关闭文件

    // 创建json--doc对象
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(array, &error);
    if (error.error != QJsonParseError::NoError)
    {
        qDebug() << "json error";
        return -1;
    }
    // 事务处理
    QSqlDatabase::database().transaction();
    //最外边的是数组
    QSqlQuery pquery;
    //准备sql语句
    pquery.prepare("insert into province(name, code) values(:name, :code)");
    QJsonArray jsonArray = doc.array();
    int cityid = 1;
    for (int i = 0; i < jsonArray.count(); ++ i)
    {
        QJsonObject jAobj = jsonArray.at(i).toObject(); // 其中一个省
        QString name = jAobj.value("name").toString(); // 获取省的名字
        QString code = jAobj.value("code").toString(); // 获取省的编号
        pquery.bindValue(0, name);
        pquery.bindValue(1, code);
        if (!pquery.exec())
        {
            qDebug() << "省:" << pquery.lastError().text();
        }
        // 获取市级城市
        QSqlQuery cquery;
        cquery.prepare("insert into city(name, code, province_id)"
                       "values(:name, :code, :province_id)");
        QJsonArray cityArray = jAobj.value("cities").toArray();
        for (int j = 0; j < cityArray.count(); ++ j, ++cityid)
        {
            // 地级市
            QJsonObject cityArrayObj = cityArray.at(j).toObject();
            QString name = cityArrayObj.value("name").toString();
            QString code = cityArrayObj.value("code").toString();
            // 绑定数据
            cquery.bindValue(0, name);
            cquery.bindValue(1, code);
            cquery.bindValue(2, i + 1);
            if (!cquery.exec())
            {
                qDebug() << "市:" << cquery.lastError().text();
            }
            // 获取县级市
            QVariantList names, codes, cities, provinces;
            QJsonArray countryArray = cityArrayObj.value("cities").toArray();
            for (int k = 0; k < countryArray.count(); ++ k)
            {
                // 地级市
                QJsonObject countryArrayObj = countryArray.at(k).toObject();
                QString name = countryArrayObj.value("name").toString();
                QString code = countryArrayObj.value("code").toString();
                names.append(name);
                codes.append(code);
                cities.append(cityid);
                provinces.append(i + 1);
            }
            if (names.size() <= 0 ) continue;
            // 批处理
            QSqlQuery countryQuery;
            countryQuery.prepare("insert into country(name, code, city_id, province_id)"
                                 " values(:name, :code, :city_id, :province_id)");
            countryQuery.addBindValue(names);
            countryQuery.addBindValue(codes);
            countryQuery.addBindValue(cities);
            countryQuery.addBindValue(provinces);
            if (!countryQuery.execBatch())
            {
                qDebug() << "县级数据插入失败";
            }
        }

    }
    // 递交事务
    QSqlDatabase::database().commit();
    return 1;
}
