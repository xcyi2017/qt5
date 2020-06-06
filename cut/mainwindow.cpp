#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageViewer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ImageViewer view(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

