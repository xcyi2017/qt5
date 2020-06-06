#ifndef SQLQUERYBINDAPP_H
#define SQLQUERYBINDAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SqlQueryBindApp; }
QT_END_NAMESPACE

class SqlQueryBindApp : public QMainWindow
{
    Q_OBJECT

public:
    SqlQueryBindApp(QWidget *parent = nullptr);
    ~SqlQueryBindApp();

private slots:
    void on_bindBt_clicked();

    void on_mulBindBt_clicked();

private:
    Ui::SqlQueryBindApp *ui;
};
#endif // SQLQUERYBINDAPP_H
