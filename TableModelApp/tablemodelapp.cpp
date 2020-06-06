#include "tablemodelapp.h"
#include "ui_tablemodelapp.h"

TableModelApp::TableModelApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableModelApp)
{
    ui->setupUi(this);
    model = new QSqlTableModel; // 会自动绑定到默认连接的数据库
    // 数据表
    model->setTable("student");
    ui->tableView->setModel(model);
}

TableModelApp::~TableModelApp()
{
    delete ui;
}


void TableModelApp::on_select_clicked()
{
    // 查询--用数据库中的数据
    model->select();
}
