#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_startButton_clicked();
    void display();
    void displayDatetime();

private:
    Ui::Interface *ui;
    QTimer *progressBarTimer;
    QTimer *dateDisplayTimer;
    int count;

};
#endif // INTERFACE_H
