#ifndef QSSTEST_H
#define QSSTEST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QssTest; }
QT_END_NAMESPACE

class QssTest : public QMainWindow
{
    Q_OBJECT

public:
    QssTest(QWidget *parent = nullptr);
    ~QssTest();

private slots:
    void showInfo();

private:
    Ui::QssTest *ui;
};
#endif // QSSTEST_H
