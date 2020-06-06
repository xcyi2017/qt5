/********************************************************************************
** Form generated from reading UI file 'qfile_test.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFILE_TEST_H
#define UI_QFILE_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qfile_test
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *readBt;
    QPushButton *writeBt;
    QPushButton *colorBt;
    QFontComboBox *fontChose;
    QTextEdit *textEdit;

    void setupUi(QWidget *Qfile_test)
    {
        if (Qfile_test->objectName().isEmpty())
            Qfile_test->setObjectName(QString::fromUtf8("Qfile_test"));
        Qfile_test->resize(589, 333);
        verticalLayout = new QVBoxLayout(Qfile_test);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        readBt = new QPushButton(Qfile_test);
        readBt->setObjectName(QString::fromUtf8("readBt"));

        horizontalLayout->addWidget(readBt);

        writeBt = new QPushButton(Qfile_test);
        writeBt->setObjectName(QString::fromUtf8("writeBt"));

        horizontalLayout->addWidget(writeBt);

        colorBt = new QPushButton(Qfile_test);
        colorBt->setObjectName(QString::fromUtf8("colorBt"));

        horizontalLayout->addWidget(colorBt);


        verticalLayout->addLayout(horizontalLayout);

        fontChose = new QFontComboBox(Qfile_test);
        fontChose->setObjectName(QString::fromUtf8("fontChose"));

        verticalLayout->addWidget(fontChose);

        textEdit = new QTextEdit(Qfile_test);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        retranslateUi(Qfile_test);

        QMetaObject::connectSlotsByName(Qfile_test);
    } // setupUi

    void retranslateUi(QWidget *Qfile_test)
    {
        Qfile_test->setWindowTitle(QCoreApplication::translate("Qfile_test", "Qfile_test", nullptr));
        readBt->setText(QCoreApplication::translate("Qfile_test", "readFile", nullptr));
        writeBt->setText(QCoreApplication::translate("Qfile_test", "writeFile", nullptr));
        colorBt->setText(QCoreApplication::translate("Qfile_test", "\351\242\234\350\211\262\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qfile_test: public Ui_Qfile_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFILE_TEST_H
