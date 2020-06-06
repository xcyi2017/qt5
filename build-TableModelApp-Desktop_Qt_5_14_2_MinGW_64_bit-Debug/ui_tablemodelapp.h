/********************************************************************************
** Form generated from reading UI file 'tablemodelapp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEMODELAPP_H
#define UI_TABLEMODELAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableModelApp
{
public:
    QTableView *tableView;
    QPushButton *select;

    void setupUi(QWidget *TableModelApp)
    {
        if (TableModelApp->objectName().isEmpty())
            TableModelApp->setObjectName(QString::fromUtf8("TableModelApp"));
        TableModelApp->resize(400, 425);
        tableView = new QTableView(TableModelApp);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 256, 391));
        select = new QPushButton(TableModelApp);
        select->setObjectName(QString::fromUtf8("select"));
        select->setGeometry(QRect(290, 20, 75, 23));

        retranslateUi(TableModelApp);

        QMetaObject::connectSlotsByName(TableModelApp);
    } // setupUi

    void retranslateUi(QWidget *TableModelApp)
    {
        TableModelApp->setWindowTitle(QCoreApplication::translate("TableModelApp", "TableModelApp", nullptr));
        select->setText(QCoreApplication::translate("TableModelApp", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableModelApp: public Ui_TableModelApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEMODELAPP_H
