#ifndef LIST__H
#define LIST__H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class list_; }
QT_END_NAMESPACE

class list_ : public QWidget
{
    Q_OBJECT

public:
    list_(QWidget *parent = nullptr);
    ~list_();

private:
    Ui::list_ *ui;
};
#endif // LIST__H
