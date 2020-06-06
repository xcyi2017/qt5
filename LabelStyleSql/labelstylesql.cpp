#include "labelstylesql.h"
#include "ui_labelstylesql.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>

LabelStyleSql::LabelStyleSql(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LabelStyleSql)
{
    ui->setupUi(this);
}

LabelStyleSql::~LabelStyleSql()
{
    delete ui;
}


void LabelStyleSql::on_insertBt_clicked()
{
    QString sql = QString("insert into label(border_size, border_color, border_radius, background_color, color)"
                          " values(%1, '%2', %3, '%4', '%5')").arg(ui->bsizeEdit->text())
                           .arg(ui->bcolorEdit->text()).arg(ui->bradiusEdit->text())
                           .arg(ui->backcolorEdit->text()).arg(ui->colorEdit->text());
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }
}

void LabelStyleSql::on_queryBt_clicked()
{
    QString id = ui->idEdit->text();
    QString sql = QString("select * from label where id = %1").arg(id);
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }
    if (query.next())
    {
        QSqlRecord record = query.record();
        ui->bsizeEdit->setText(record.value("border_size").toString());
        ui->bcolorEdit->setText(record.value("border_color").toString());
        ui->bradiusEdit->setText(record.value("border_radius").toString());
        ui->backcolorEdit->setText(record.value("background_color").toString());
        ui->colorEdit->setText(record.value("color").toString());
    }
}

void LabelStyleSql::on_deleteBt_clicked()
{
    QString id = ui->idEdit->text();
    QString sql = QString("delete from label where id = %1").arg(id);
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }
}

void LabelStyleSql::on_renewBt_clicked()
{
    QString id = ui->idEdit->text();
    update_field("border_size", ui->bsizeEdit->text(), id.toInt());
}
// 更新数据函数
void LabelStyleSql::update_field(QString key, QString value, int id)
{
    QString sql = QString("update label set %1 = %2 where id = %3").arg(key).arg(value).arg(id);
    QSqlQuery query;
    if(!query.exec(sql))
    {
        qDebug() << query.lastError().text();
    }
}

void LabelStyleSql::on_testBt_clicked()
{
    QString bsize = ui->bsizeEdit->text();
    QString bcolor = ui->bcolorEdit->text();
    QString bradius = ui->bradiusEdit->text();
    QString backcolor = ui->backcolorEdit->text();
    QString color = ui->colorEdit->text();
    QString style = QString("border: %1 solid%2; border-radius:%3px; background-color:%4; color:%5;").arg(bsize)
                         .arg(bcolor).arg(bradius).arg(backcolor).arg(color);
    ui->testLabel->setStyleSheet(style);
}
