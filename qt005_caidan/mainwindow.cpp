#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 菜单栏
    QMenuBar *mBar = menuBar();

    // 添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    // 添加菜单项
    QAction *pNew = pFile->addAction("新建");

    connect(pNew, &QAction::triggered,
            [=] ()
    {
        qDebug() << "hello";
    });
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");
    connect(pOpen, &QAction::triggered,
            [=] ()
    {
        qDebug() << "打开";
        qDebug() << mBar->size().height();
    });
    // 工具栏

    QToolBar *toolBar = addToolBar("toolBar");
    // 工具栏添加快捷方式

    toolBar->addAction(pOpen);

    QPushButton *b = new QPushButton(this);
    b->setText("^_^");

    toolBar->addWidget(b);

    connect(b, &QPushButton::clicked,
            [=] ()
    {
        qDebug() << "hahha";
    });
    // 状态栏
    QStatusBar *sBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    // 从左往右依次添加
    sBar->addWidget(label);
    sBar->addPermanentWidget(new QLabel("heihei", this));
    // 核心控件
    QTextEdit *text = new QTextEdit(this);
    setCentralWidget(text);
    // 浮动窗口
    QDockWidget* dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    QTextEdit *text1 = new QTextEdit(this);
    dock->setWidget(text1);
}

MainWindow::~MainWindow()
{

}
