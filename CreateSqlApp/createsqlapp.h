#ifndef CREATESQLAPP_H
#define CREATESQLAPP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CreateSqlApp; }
QT_END_NAMESPACE

class CreateSqlApp : public QWidget
{
    Q_OBJECT

public:
    CreateSqlApp(QWidget *parent = nullptr);
    ~CreateSqlApp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateSqlApp *ui;
};
#endif // CREATESQLAPP_H
