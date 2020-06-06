#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str = ui->comboBox->currentText();
    qDebug() << str;
    ui->lineEdit->setText("1212321321");
    ui->lineEdit->setTextMargins(15, 0, 0, 0);
//    ui->lineEdit->setEchoMode(QLineEdit::Password);

    // 有提示输入

    QStringList list;
    list << "hello" << "yes" << "hi" << "my name is xx";
    QCompleter *com = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseSensitive);

    ui->lineEdit->setCompleter(com);

    //labelText
    ui->labelText->setText("^_^");
    ui->labelText->setPixmap(QPixmap("://image/img2.png"));
    ui->labelText->setScaledContents(true);

    ui->labelUrl->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    ui->labelUrl->setOpenExternalLinks(true);

    ui->lcdNumber->display("A");
    ui->webView->load(QUrl("https://www.baidu.com"));

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_4_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i % 4); // 每次取值都是0-3
}
