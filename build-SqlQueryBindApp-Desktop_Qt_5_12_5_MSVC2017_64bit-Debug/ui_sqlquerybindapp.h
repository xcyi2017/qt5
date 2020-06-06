/********************************************************************************
** Form generated from reading UI file 'sqlquerybindapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLQUERYBINDAPP_H
#define UI_SQLQUERYBINDAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SqlQueryBindApp
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *mulBindBt;
    QLineEdit *nameEdit;
    QLineEdit *sexEdit;
    QPushButton *bindBt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SqlQueryBindApp)
    {
        if (SqlQueryBindApp->objectName().isEmpty())
            SqlQueryBindApp->setObjectName(QString::fromUtf8("SqlQueryBindApp"));
        SqlQueryBindApp->resize(334, 91);
        centralwidget = new QWidget(SqlQueryBindApp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mulBindBt = new QPushButton(centralwidget);
        mulBindBt->setObjectName(QString::fromUtf8("mulBindBt"));

        horizontalLayout->addWidget(mulBindBt);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);

        sexEdit = new QLineEdit(centralwidget);
        sexEdit->setObjectName(QString::fromUtf8("sexEdit"));

        horizontalLayout->addWidget(sexEdit);

        bindBt = new QPushButton(centralwidget);
        bindBt->setObjectName(QString::fromUtf8("bindBt"));

        horizontalLayout->addWidget(bindBt);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        SqlQueryBindApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SqlQueryBindApp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 334, 23));
        SqlQueryBindApp->setMenuBar(menubar);
        statusbar = new QStatusBar(SqlQueryBindApp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SqlQueryBindApp->setStatusBar(statusbar);

        retranslateUi(SqlQueryBindApp);

        QMetaObject::connectSlotsByName(SqlQueryBindApp);
    } // setupUi

    void retranslateUi(QMainWindow *SqlQueryBindApp)
    {
        SqlQueryBindApp->setWindowTitle(QApplication::translate("SqlQueryBindApp", "SqlQueryBindApp", nullptr));
        mulBindBt->setText(QApplication::translate("SqlQueryBindApp", "\346\211\271\351\207\217\347\273\221\345\256\232\346\234\272\345\210\266\346\217\222\345\205\245", nullptr));
        nameEdit->setPlaceholderText(QApplication::translate("SqlQueryBindApp", "\345\247\223\345\220\215", nullptr));
        sexEdit->setPlaceholderText(QApplication::translate("SqlQueryBindApp", "\346\200\247\345\210\253", nullptr));
        bindBt->setText(QApplication::translate("SqlQueryBindApp", "\347\273\221\345\256\232\346\234\272\345\210\266\346\217\222\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SqlQueryBindApp: public Ui_SqlQueryBindApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLQUERYBINDAPP_H
