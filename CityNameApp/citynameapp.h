#ifndef CITYNAMEAPP_H
#define CITYNAMEAPP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CityNameApp; }
QT_END_NAMESPACE

class CityNameApp : public QWidget
{
    Q_OBJECT

public:
    CityNameApp(QWidget *parent = nullptr);
    ~CityNameApp();

private:
    Ui::CityNameApp *ui;
};
#endif // CITYNAMEAPP_H
