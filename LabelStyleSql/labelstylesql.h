#ifndef LABELSTYLESQL_H
#define LABELSTYLESQL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LabelStyleSql; }
QT_END_NAMESPACE

class LabelStyleSql : public QWidget
{
    Q_OBJECT

public:
    LabelStyleSql(QWidget *parent = nullptr);
    ~LabelStyleSql();

private slots:
    void on_insertBt_clicked();

    void on_queryBt_clicked();

    void on_deleteBt_clicked();

    void on_renewBt_clicked();

    void on_testBt_clicked();

private:
    Ui::LabelStyleSql *ui;
    void update_field(QString key, QString value, int id);
};
#endif // LABELSTYLESQL_H
