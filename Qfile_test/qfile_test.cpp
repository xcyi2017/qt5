#include "qfile_test.h"
#include "ui_qfile_test.h"

Qfile_test::Qfile_test(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Qfile_test)
{
    ui->setupUi(this);

}

Qfile_test::~Qfile_test()
{
    delete ui;
}


void Qfile_test::on_readBt_clicked()
{
    QString filePath = QFileDialog().getOpenFileName(this, tr("选择文件"), ".", tr("Text (*.txt *.py)"));
//    qDebug() << filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "打开失败";
    }
    QByteArray array;
    while (!file.atEnd())
    {
        QByteArray tmp = file.read(10*1024);
        array.append(tmp);
    }
    file.close();
    this->ui->textEdit->setText(array);
}

void Qfile_test::on_writeBt_clicked()
{
    QByteArray array = ui->textEdit->toPlainText().toLatin1();
    QString filePath = QFileDialog().getSaveFileName(this, tr("保存文件"), ".");
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(array);
        }
        file.close();
    }
}

void Qfile_test::on_fontChose_currentFontChanged(const QFont &f)
{
    ui->textEdit->setFont(f);
}

void Qfile_test::on_colorBt_clicked()
{
    QColor color = QColorDialog().getColor(Qt::white, this);
    ui->textEdit->setTextColor(color);
}
