/********************************************************************************
** Form generated from reading UI file 'muldatabaseapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULDATABASEAPP_H
#define UI_MULDATABASEAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MulDatabaseApp
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *insertBt;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *Acheck;
    QRadioButton *Bcheck;

    void setupUi(QWidget *MulDatabaseApp)
    {
        if (MulDatabaseApp->objectName().isEmpty())
            MulDatabaseApp->setObjectName(QString::fromUtf8("MulDatabaseApp"));
        MulDatabaseApp->resize(368, 209);
        widget = new QWidget(MulDatabaseApp);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 100, 355, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        horizontalLayout->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        horizontalLayout->addWidget(passwordEdit);

        insertBt = new QPushButton(widget);
        insertBt->setObjectName(QString::fromUtf8("insertBt"));

        horizontalLayout->addWidget(insertBt);

        widget1 = new QWidget(MulDatabaseApp);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 70, 90, 18));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Acheck = new QRadioButton(widget1);
        Acheck->setObjectName(QString::fromUtf8("Acheck"));

        horizontalLayout_2->addWidget(Acheck);

        Bcheck = new QRadioButton(widget1);
        Bcheck->setObjectName(QString::fromUtf8("Bcheck"));

        horizontalLayout_2->addWidget(Bcheck);


        retranslateUi(MulDatabaseApp);

        QMetaObject::connectSlotsByName(MulDatabaseApp);
    } // setupUi

    void retranslateUi(QWidget *MulDatabaseApp)
    {
        MulDatabaseApp->setWindowTitle(QApplication::translate("MulDatabaseApp", "MulDatabaseApp", nullptr));
        insertBt->setText(QApplication::translate("MulDatabaseApp", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        Acheck->setText(QApplication::translate("MulDatabaseApp", "Adb", nullptr));
        Bcheck->setText(QApplication::translate("MulDatabaseApp", "Bdb", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MulDatabaseApp: public Ui_MulDatabaseApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULDATABASEAPP_H
