#ifndef TRANSECTIONAPP_H
#define TRANSECTIONAPP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class transectionApp; }
QT_END_NAMESPACE

class transectionApp : public QWidget
{
    Q_OBJECT

public:
    transectionApp(QWidget *parent = nullptr);
    ~transectionApp();

private slots:
    void on_commitBt_clicked();

    void on_beginBt_clicked();

    void on_rollbackBt_clicked();

    void on_insertBt_clicked();

    void on_searchBt_clicked();

private:
    Ui::transectionApp *ui;
};
#endif // TRANSECTIONAPP_H
