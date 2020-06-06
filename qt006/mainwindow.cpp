#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar* mBar = menuBar();
    setMenuBar(mBar);
    QMenu* menu = mBar->addMenu("对话框");
    QAction *p1 = menu->addAction("模态对话框");

    connect(p1, &QAction::triggered,
           [=] ()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() << "hello";
            }
           );

    QAction *p2 = menu->addAction("非模态对话框");

    connect(p2, &QAction::triggered,
           [=] ()
            {
                //dlg.show(); // 当作类成员不会退出
//                QDialog *p = new QDialog(this);
//                p->show(); // 动态分配内存也不会退出 // 指定父对象，在程序退出后，才会停止，不停的点，会动态分配很多内存
                  QDialog *p = new QDialog; // 不指定父对象
                  p->setAttribute(Qt::WA_DeleteOnClose);
                  p->show();
                  qDebug() << "hello world";
            }
           );

    QAction *p3 = menu->addAction("对话框");

    connect(p3, &QAction::triggered,
           [=] ()
            {
                QMessageBox::about(this, "about", "关于Qt"); // 静态方法
            }
           );

    QAction *p4 = menu->addAction("问题对话框");

    connect(p4, &QAction::triggered,
           [=] ()
            {
                int ret = QMessageBox::question(this, "question", "Are you ok?"); // 静态方法
                switch (ret) {
                case QMessageBox::Yes:
                    qDebug() << "yes";
                    break;
                case QMessageBox::No:
                    qDebug() << "no";
                    break;
                default:
                    break;
                }
            }
           );


    QAction *p5 = menu->addAction("文件对话框");

    connect(p5, &QAction::triggered,
           [=] ()
            {   // 过滤条件
                QString path = QFileDialog::getOpenFileName(this, "Open", "../", tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"));
                qDebug() << path;
            }
           );

}

MainWindow::~MainWindow()
{

}
