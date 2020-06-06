/********************************************************************************
** Form generated from reading UI file 'citynameapp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CITYNAMEAPP_H
#define UI_CITYNAMEAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CityNameApp
{
public:

    void setupUi(QWidget *CityNameApp)
    {
        if (CityNameApp->objectName().isEmpty())
            CityNameApp->setObjectName(QString::fromUtf8("CityNameApp"));
        CityNameApp->resize(800, 600);

        retranslateUi(CityNameApp);

        QMetaObject::connectSlotsByName(CityNameApp);
    } // setupUi

    void retranslateUi(QWidget *CityNameApp)
    {
        CityNameApp->setWindowTitle(QCoreApplication::translate("CityNameApp", "CityNameApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CityNameApp: public Ui_CityNameApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CITYNAMEAPP_H
