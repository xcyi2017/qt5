#include "qsstest.h"
#include "ui_qsstest.h"

QssTest::QssTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QssTest)
{
    ui->setupUi(this);
    connect(ui->actionnew, SIGNAL(triggered()), this, SLOT(showInfo()));

}

QssTest::~QssTest()
{
    delete ui;
}

void QssTest::showInfo()
{
    QStatusBar  *status_bar = statusBar();
    status_bar->showMessage(ui->actionnew->text());
}

