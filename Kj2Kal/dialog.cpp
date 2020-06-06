#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/images/apps_calorie_calculator.ico"));
    QStringList list = {"千焦(KJ)", "千卡(kcal)"};
    ui->comboBox->addItems(list);
    ui->comboBox_2->addItems(list);

    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(1);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(process(int)));
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(process(int)));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(solve(QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::process(int index)
{
    if (sender()->objectName() == ui->comboBox->objectName()) {
        ui->comboBox_2->blockSignals(true);
        ui->comboBox_2->setCurrentIndex(1-index);
        ui->comboBox_2->blockSignals(false);
    }
    else if (sender()->objectName() == ui->comboBox_2->objectName()) {
        ui->comboBox->blockSignals(true);
        ui->comboBox->setCurrentIndex(1-index);
        ui->comboBox->blockSignals(false);
    }
    solve(ui->lineEdit->text());

}

void Dialog::solve(QString str)
{
    if (ui->lineEdit->text() != "") {
        double result;
        if (ui->comboBox->currentIndex() == 0) {
            result = str.toDouble() / 4.1858518;
            ui->lineEdit_2->setText(QString::number(result) + ui->comboBox_2->currentText());
        }
        else {
            result = str.toDouble() * 4.1858518;
            ui->lineEdit_2->setText(QString::number(result) + ui->comboBox_2->currentText());
        }
    }
    else {
        ui->lineEdit_2->clear();
    }
}

