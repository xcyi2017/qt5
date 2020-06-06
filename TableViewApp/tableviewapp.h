#ifndef TABLEVIEWAPP_H
#define TABLEVIEWAPP_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class TableViewApp; }
QT_END_NAMESPACE

class TableViewApp : public QWidget
{
    Q_OBJECT

public:
    TableViewApp(QWidget *parent = nullptr);
    ~TableViewApp();

private:
    Ui::TableViewApp *ui;
    QSqlTableModel *model;
};
#endif // TABLEVIEWAPP_H
