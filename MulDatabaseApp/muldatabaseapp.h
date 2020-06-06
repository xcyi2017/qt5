#ifndef MULDATABASEAPP_H
#define MULDATABASEAPP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MulDatabaseApp; }
QT_END_NAMESPACE

class MulDatabaseApp : public QWidget
{
    Q_OBJECT

public:
    MulDatabaseApp(QWidget *parent = nullptr);
    ~MulDatabaseApp();

private slots:
    void on_insertBt_clicked();

private:
    Ui::MulDatabaseApp *ui;
};
#endif // MULDATABASEAPP_H
