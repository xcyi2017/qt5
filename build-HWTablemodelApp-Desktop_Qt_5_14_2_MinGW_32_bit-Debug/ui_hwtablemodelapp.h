/********************************************************************************
** Form generated from reading UI file 'hwtablemodelapp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HWTABLEMODELAPP_H
#define UI_HWTABLEMODELAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HWTablemodelApp
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QLineEdit *classEdit;
    QLineEdit *nameEdit;
    QLineEdit *hwEdit;
    QPushButton *insertBt;
    QPushButton *selectBt;
    QPushButton *updateBt;
    QPushButton *deleteBt;
    QPushButton *commitBt;

    void setupUi(QWidget *HWTablemodelApp)
    {
        if (HWTablemodelApp->objectName().isEmpty())
            HWTablemodelApp->setObjectName(QString::fromUtf8("HWTablemodelApp"));
        HWTablemodelApp->resize(800, 600);
        verticalLayout = new QVBoxLayout(HWTablemodelApp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(HWTablemodelApp);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        classEdit = new QLineEdit(HWTablemodelApp);
        classEdit->setObjectName(QString::fromUtf8("classEdit"));

        horizontalLayout->addWidget(classEdit);

        nameEdit = new QLineEdit(HWTablemodelApp);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);

        hwEdit = new QLineEdit(HWTablemodelApp);
        hwEdit->setObjectName(QString::fromUtf8("hwEdit"));

        horizontalLayout->addWidget(hwEdit);

        insertBt = new QPushButton(HWTablemodelApp);
        insertBt->setObjectName(QString::fromUtf8("insertBt"));

        horizontalLayout->addWidget(insertBt);

        selectBt = new QPushButton(HWTablemodelApp);
        selectBt->setObjectName(QString::fromUtf8("selectBt"));

        horizontalLayout->addWidget(selectBt);

        updateBt = new QPushButton(HWTablemodelApp);
        updateBt->setObjectName(QString::fromUtf8("updateBt"));

        horizontalLayout->addWidget(updateBt);

        deleteBt = new QPushButton(HWTablemodelApp);
        deleteBt->setObjectName(QString::fromUtf8("deleteBt"));

        horizontalLayout->addWidget(deleteBt);

        commitBt = new QPushButton(HWTablemodelApp);
        commitBt->setObjectName(QString::fromUtf8("commitBt"));

        horizontalLayout->addWidget(commitBt);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(HWTablemodelApp);

        QMetaObject::connectSlotsByName(HWTablemodelApp);
    } // setupUi

    void retranslateUi(QWidget *HWTablemodelApp)
    {
        HWTablemodelApp->setWindowTitle(QCoreApplication::translate("HWTablemodelApp", "HWTablemodelApp", nullptr));
        classEdit->setPlaceholderText(QCoreApplication::translate("HWTablemodelApp", "\347\217\255\347\272\247", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("HWTablemodelApp", "\345\247\223\345\220\215", nullptr));
        hwEdit->setPlaceholderText(QCoreApplication::translate("HWTablemodelApp", "\344\275\234\344\270\232\345\220\215\347\247\260", nullptr));
        insertBt->setText(QCoreApplication::translate("HWTablemodelApp", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        selectBt->setText(QCoreApplication::translate("HWTablemodelApp", "\346\237\245\350\257\242", nullptr));
        updateBt->setText(QCoreApplication::translate("HWTablemodelApp", "\346\233\264\346\226\260", nullptr));
        deleteBt->setText(QCoreApplication::translate("HWTablemodelApp", "\345\210\240\351\231\244", nullptr));
        commitBt->setText(QCoreApplication::translate("HWTablemodelApp", "\351\200\222\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HWTablemodelApp: public Ui_HWTablemodelApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HWTABLEMODELAPP_H
