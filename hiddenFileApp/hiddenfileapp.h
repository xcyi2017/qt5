#ifndef HIDDENFILEAPP_H
#define HIDDENFILEAPP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class hiddenFileApp; }
QT_END_NAMESPACE

class hiddenFileApp : public QWidget
{
    Q_OBJECT

public:
    hiddenFileApp(QWidget *parent = nullptr);
    ~hiddenFileApp();

private:
    Ui::hiddenFileApp *ui;
};
#endif // HIDDENFILEAPP_H
