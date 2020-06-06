#include "hiddenfileapp.h"
#include "ui_hiddenfileapp.h"
#include <QFileInfo>

hiddenFileApp::hiddenFileApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hiddenFileApp)
{
    ui->setupUi(this);
}

hiddenFileApp::~hiddenFileApp()
{
    delete ui;
}

