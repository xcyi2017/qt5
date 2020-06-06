#ifndef HWTABLEMODELAPP_H
#define HWTABLEMODELAPP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDateTime>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class HWTablemodelApp; }
QT_END_NAMESPACE

class HWTablemodelApp : public QWidget
{
    Q_OBJECT

public:
    HWTablemodelApp(QWidget *parent = nullptr);
    ~HWTablemodelApp();

private slots:
    void on_insertBt_clicked();

    void on_selectBt_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_updateBt_clicked();

    void on_commitBt_clicked();

    void on_deleteBt_clicked();

private:
    Ui::HWTablemodelApp *ui;
    QSqlTableModel *model;
};
#endif // HWTABLEMODELAPP_H
