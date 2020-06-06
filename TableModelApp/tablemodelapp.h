#ifndef TABLEMODELAPP_H
#define TABLEMODELAPP_H

#include <QWidget>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class TableModelApp; }
QT_END_NAMESPACE

class TableModelApp : public QWidget
{
    Q_OBJECT

public:
    TableModelApp(QWidget *parent = nullptr);
    ~TableModelApp();

private slots:
    void on_select_clicked();

private:
    Ui::TableModelApp *ui;
    QSqlTableModel *model;
};
#endif // TABLEMODELAPP_H
