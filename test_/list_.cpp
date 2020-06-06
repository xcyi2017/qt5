#include "list_.h"
#include "ui_list_.h"

list_::list_(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::list_)
{
    ui->setupUi(this);
}

list_::~list_()
{
    delete ui;
}

