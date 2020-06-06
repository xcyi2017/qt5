/********************************************************************************
** Form generated from reading UI file 'transectionapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSECTIONAPP_H
#define UI_TRANSECTIONAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transectionApp
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *nameEdit;
    QLineEdit *sexEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *beginBt;
    QPushButton *commitBt;
    QPushButton *rollbackBt;
    QPushButton *insertBt;
    QPushButton *searchBt;

    void setupUi(QWidget *transectionApp)
    {
        if (transectionApp->objectName().isEmpty())
            transectionApp->setObjectName(QString::fromUtf8("transectionApp"));
        transectionApp->resize(544, 295);
        gridLayout = new QGridLayout(transectionApp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nameEdit = new QLineEdit(transectionApp);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);

        sexEdit = new QLineEdit(transectionApp);
        sexEdit->setObjectName(QString::fromUtf8("sexEdit"));

        horizontalLayout->addWidget(sexEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        beginBt = new QPushButton(transectionApp);
        beginBt->setObjectName(QString::fromUtf8("beginBt"));

        verticalLayout->addWidget(beginBt);

        commitBt = new QPushButton(transectionApp);
        commitBt->setObjectName(QString::fromUtf8("commitBt"));

        verticalLayout->addWidget(commitBt);

        rollbackBt = new QPushButton(transectionApp);
        rollbackBt->setObjectName(QString::fromUtf8("rollbackBt"));

        verticalLayout->addWidget(rollbackBt);

        insertBt = new QPushButton(transectionApp);
        insertBt->setObjectName(QString::fromUtf8("insertBt"));

        verticalLayout->addWidget(insertBt);

        searchBt = new QPushButton(transectionApp);
        searchBt->setObjectName(QString::fromUtf8("searchBt"));

        verticalLayout->addWidget(searchBt);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(transectionApp);

        QMetaObject::connectSlotsByName(transectionApp);
    } // setupUi

    void retranslateUi(QWidget *transectionApp)
    {
        transectionApp->setWindowTitle(QApplication::translate("transectionApp", "transectionApp", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("transectionApp", "\345\247\223\345\220\215", nullptr));
        sexEdit->setPlaceholderText(QApplication::translate("transectionApp", "\346\200\247\345\210\253", nullptr));
        beginBt->setText(QApplication::translate("transectionApp", "\345\274\200\345\220\257\344\272\213\345\212\241", nullptr));
        commitBt->setText(QApplication::translate("transectionApp", "\351\200\222\344\272\244\344\272\213\345\212\241", nullptr));
        rollbackBt->setText(QApplication::translate("transectionApp", "\345\233\236\346\273\232\344\272\213\345\212\241", nullptr));
        insertBt->setText(QApplication::translate("transectionApp", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        searchBt->setText(QApplication::translate("transectionApp", "\346\237\245\350\257\242\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transectionApp: public Ui_transectionApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSECTIONAPP_H
