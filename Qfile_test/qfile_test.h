#ifndef QFILE_TEST_H
#define QFILE_TEST_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QIODevice>
#include <QColorDialog>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class Qfile_test; }
QT_END_NAMESPACE

class Qfile_test : public QWidget
{
    Q_OBJECT

public:
    Qfile_test(QWidget *parent = nullptr);
    ~Qfile_test();

private slots:
    void on_readBt_clicked();

    void on_writeBt_clicked();

    void on_fontChose_currentFontChanged(const QFont &f);

    void on_colorBt_clicked();

private:
    Ui::Qfile_test *ui;

};
#endif // QFILE_TEST_H
