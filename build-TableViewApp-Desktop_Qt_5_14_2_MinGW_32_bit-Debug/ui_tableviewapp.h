/********************************************************************************
** Form generated from reading UI file 'tableviewapp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEVIEWAPP_H
#define UI_TABLEVIEWAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableViewApp
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *TableViewApp)
    {
        if (TableViewApp->objectName().isEmpty())
            TableViewApp->setObjectName(QString::fromUtf8("TableViewApp"));
        TableViewApp->resize(800, 600);
        gridLayout = new QGridLayout(TableViewApp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(TableViewApp);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(TableViewApp);

        QMetaObject::connectSlotsByName(TableViewApp);
    } // setupUi

    void retranslateUi(QWidget *TableViewApp)
    {
        TableViewApp->setWindowTitle(QCoreApplication::translate("TableViewApp", "TableViewApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableViewApp: public Ui_TableViewApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEVIEWAPP_H
