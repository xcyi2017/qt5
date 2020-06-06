#include "tableviewapp.h"
#include "ui_tableviewapp.h"

TableViewApp::TableViewApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableViewApp)
{
    ui->setupUi(this);
    model = new QSqlTableModel;
    model->setTable("homework");
    model->select();
    ui->tableView->setModel(model);

    // 隐藏第0列数据
    ui->tableView->setColumnHidden(0, true);
    // 设置表水平头的信息
    model->setHeaderData(1, Qt::Horizontal, "班级");
    model->setHeaderData(2, Qt::Horizontal, "姓名");
    model->setHeaderData(3, Qt::Horizontal, "时间");
    model->setHeaderData(4, Qt::Horizontal, "作业名称");

    ui->tableView->setGridStyle(Qt::SolidLine);

}

TableViewApp::~TableViewApp()
{
    delete ui;
    delete model;
}

