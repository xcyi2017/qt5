#include "mainwindow.h"
// QApplication应用程序类
// Qt头文件没有.h
// 头文件和类名一样
#include <QApplication>

int main(int argc, char *argv[])
{
    // 有且只有一个应用程序对象
    QApplication a(argc, argv);
    // Mywidget继承与Qwidget, QWidget是一个窗口基类
    // 所以mainwindow也是窗口类
    // w就是一个窗口
    MainWindow w;
    /*
     * 窗口创建默认是隐藏，需要人为显示
     */
    w.setWindowTitle("Hello Qt!");
    w.setGeometry(300, 300, 400, 400);
    w.show();
    /*
     * 让程序一直执行，等待用户操作
     * 等待事件的发生
     */

    return a.exec();
    /*
     * a.exec();
     * return 0;
     */
}
