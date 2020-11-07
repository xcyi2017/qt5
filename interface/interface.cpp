#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
    , progressBarTimer(new QTimer)
    , dateDisplayTimer(new QTimer)
    , count(0)

{
    ui->setupUi(this);
    connect(progressBarTimer, SIGNAL(timeout()), this, SLOT(display()));
    connect(dateDisplayTimer, SIGNAL(timeout()), this, SLOT(displayDatetime()));
    dateDisplayTimer->start(1000);
}

Interface::~Interface()
{
    delete ui;
}

void Interface::display()
{
    count = (count + 1) % 100;
    ui->progressBar->setValue(count);
}

void Interface::displayDatetime()
{
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->timeDIsplayLabel->setText(time);
    ui->timeDIsplayLabel->adjustSize();
}


void Interface::on_startButton_clicked()
{   if (!progressBarTimer->isActive())
        progressBarTimer->start(100);
}
