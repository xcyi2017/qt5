#include "citynameapp.h"
#include "ui_citynameapp.h"

CityNameApp::CityNameApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CityNameApp)
{
    ui->setupUi(this);
}

CityNameApp::~CityNameApp()
{
    delete ui;
}

