/********************************************************************************
** Form generated from reading UI file 'createsqlapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESQLAPP_H
#define UI_CREATESQLAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateSqlApp
{
public:
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *CreateSqlApp)
    {
        if (CreateSqlApp->objectName().isEmpty())
            CreateSqlApp->setObjectName(QString::fromUtf8("CreateSqlApp"));
        CreateSqlApp->resize(800, 600);
        idEdit = new QLineEdit(CreateSqlApp);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));
        idEdit->setGeometry(QRect(30, 10, 151, 20));
        nameEdit = new QLineEdit(CreateSqlApp);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(230, 10, 151, 20));
        pushButton = new QPushButton(CreateSqlApp);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 10, 75, 23));

        retranslateUi(CreateSqlApp);

        QMetaObject::connectSlotsByName(CreateSqlApp);
    } // setupUi

    void retranslateUi(QWidget *CreateSqlApp)
    {
        CreateSqlApp->setWindowTitle(QApplication::translate("CreateSqlApp", "CreateSqlApp", nullptr));
        pushButton->setText(QApplication::translate("CreateSqlApp", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateSqlApp: public Ui_CreateSqlApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESQLAPP_H
