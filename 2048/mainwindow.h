#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QPainter>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent* );
    void keyPressEvent(QKeyEvent *event);

    int s[4][4];
    QPushButton* button;
    int score = 0;
    bool state; // 游戏状态
    void pressUp();
    void pressDown();
    void pressLeft();
    void pressRight();
    void myRand();
    struct Ns {
        int x;
        int y;
    };

public slots:
    void slotStart();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
