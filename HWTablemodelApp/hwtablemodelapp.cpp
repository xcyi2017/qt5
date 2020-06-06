#include "hwtablemodelapp.h"
#include "ui_hwtablemodelapp.h"

HWTablemodelApp::HWTablemodelApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HWTablemodelApp)
{
    ui->setupUi(this);
    model = new QSqlTableModel;
    model->setTable("homework");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);

}

HWTablemodelApp::~HWTablemodelApp()
{
    delete ui;
    delete model;
}


void HWTablemodelApp::on_insertBt_clicked()
{
    QString class_ = ui->classEdit->text();
    QString name = ui->nameEdit->text();
    QString hwname = ui->hwEdit->text();
    QString time = QDateTime::currentDateTime().toString();

    // 创建一条数据记录
    QSqlRecord record = model->record();
    record.setValue("class", class_);
    record.setValue("name", name);
    record.setValue("time", time);
    record.setValue("hwname", hwname);
    // 把记录添加到表格模型中
    model->insertRecord(0, record);
    model->select();
}

void HWTablemodelApp::on_selectBt_clicked()
{
    // 查询数据
    // 设置条件过滤
    QString class_ = ui->classEdit->text();
    QString name = ui->nameEdit->text();
    QString hwname = ui->hwEdit->text();
    QString filter;
    if (!class_.isEmpty())
    {
        filter.append(QString("class=%1").arg(class_));
    }
    if (!name.isEmpty())
    {   if (!filter.isEmpty()) filter.append(" and ");
        filter.append(QString("name='%1'").arg(name));
    }
    if (!hwname.isEmpty())
    {
        if (!filter.isEmpty()) filter.append(" and ");
        filter.append(QString("hwname='%1'").arg(hwname));
    }
    qDebug() << filter;
    model->setFilter(filter);
    model->select();
}

void HWTablemodelApp::on_tableView_clicked(const QModelIndex &index)
{
    // 获取所点击的行
    int row = index.row();
    // 从模型获取模型row行的记录
    QSqlRecord record = model->record(row);
    // 获取记录中的数据
    ui->classEdit->setText(record.value("class").toString());
    ui->nameEdit->setText(record.value("name").toString());
    ui->hwEdit->setText(record.value("hwname").toString());
}

void HWTablemodelApp::on_updateBt_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row <= 0) return;
    QSqlRecord record = model->record(row);
    record.setValue("class", ui->classEdit->text());
    record.setValue("name", ui->nameEdit->text());
    record.setValue("hwname", ui->hwEdit->text());

    model->setRecord(row, record);
}

void HWTablemodelApp::on_commitBt_clicked()
{
    model->submitAll();
}

void HWTablemodelApp::on_deleteBt_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if (row <= 0) return;
    model->removeRow(row);
}
