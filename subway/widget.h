#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "map.h"
#include "graphview.h"
#include "amtr_line_1.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void on_add_station_button_clicked();

    void on_add_path_button_clicked();

    void on_calc_button_clicked();

    void on_reset_button_clicked();

private:
    QList<int> preL, curL, tmpL;

    void Map_Reset();
    void preAddStation(const QString, const QPoint);
    void preAddEdge(const int, const int, const int);
 };
#endif // WIDGET_H
