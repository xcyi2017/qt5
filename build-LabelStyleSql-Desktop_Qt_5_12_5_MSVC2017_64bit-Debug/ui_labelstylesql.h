/********************************************************************************
** Form generated from reading UI file 'labelstylesql.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELSTYLESQL_H
#define UI_LABELSTYLESQL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabelStyleSql
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *idEdit;
    QLineEdit *bsizeEdit;
    QLineEdit *bcolorEdit;
    QLineEdit *bradiusEdit;
    QLineEdit *backcolorEdit;
    QLineEdit *colorEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *insertBt;
    QPushButton *queryBt;
    QPushButton *deleteBt;
    QPushButton *renewBt;
    QPushButton *testBt;
    QLabel *testLabel;

    void setupUi(QWidget *LabelStyleSql)
    {
        if (LabelStyleSql->objectName().isEmpty())
            LabelStyleSql->setObjectName(QString::fromUtf8("LabelStyleSql"));
        LabelStyleSql->resize(354, 213);
        gridLayout_2 = new QGridLayout(LabelStyleSql);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        idEdit = new QLineEdit(LabelStyleSql);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        verticalLayout->addWidget(idEdit);

        bsizeEdit = new QLineEdit(LabelStyleSql);
        bsizeEdit->setObjectName(QString::fromUtf8("bsizeEdit"));

        verticalLayout->addWidget(bsizeEdit);

        bcolorEdit = new QLineEdit(LabelStyleSql);
        bcolorEdit->setObjectName(QString::fromUtf8("bcolorEdit"));

        verticalLayout->addWidget(bcolorEdit);

        bradiusEdit = new QLineEdit(LabelStyleSql);
        bradiusEdit->setObjectName(QString::fromUtf8("bradiusEdit"));

        verticalLayout->addWidget(bradiusEdit);

        backcolorEdit = new QLineEdit(LabelStyleSql);
        backcolorEdit->setObjectName(QString::fromUtf8("backcolorEdit"));

        verticalLayout->addWidget(backcolorEdit);

        colorEdit = new QLineEdit(LabelStyleSql);
        colorEdit->setObjectName(QString::fromUtf8("colorEdit"));

        verticalLayout->addWidget(colorEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        insertBt = new QPushButton(LabelStyleSql);
        insertBt->setObjectName(QString::fromUtf8("insertBt"));

        verticalLayout_2->addWidget(insertBt);

        queryBt = new QPushButton(LabelStyleSql);
        queryBt->setObjectName(QString::fromUtf8("queryBt"));

        verticalLayout_2->addWidget(queryBt);

        deleteBt = new QPushButton(LabelStyleSql);
        deleteBt->setObjectName(QString::fromUtf8("deleteBt"));

        verticalLayout_2->addWidget(deleteBt);

        renewBt = new QPushButton(LabelStyleSql);
        renewBt->setObjectName(QString::fromUtf8("renewBt"));

        verticalLayout_2->addWidget(renewBt);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        testBt = new QPushButton(LabelStyleSql);
        testBt->setObjectName(QString::fromUtf8("testBt"));

        gridLayout_2->addWidget(testBt, 1, 1, 1, 1);

        testLabel = new QLabel(LabelStyleSql);
        testLabel->setObjectName(QString::fromUtf8("testLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(testLabel->sizePolicy().hasHeightForWidth());
        testLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(testLabel, 0, 1, 1, 2);


        retranslateUi(LabelStyleSql);

        QMetaObject::connectSlotsByName(LabelStyleSql);
    } // setupUi

    void retranslateUi(QWidget *LabelStyleSql)
    {
        LabelStyleSql->setWindowTitle(QApplication::translate("LabelStyleSql", "LabelStyleSql", nullptr));
        idEdit->setPlaceholderText(QApplication::translate("LabelStyleSql", "id", nullptr));
        bsizeEdit->setPlaceholderText(QApplication::translate("LabelStyleSql", "border-size", nullptr));
        bcolorEdit->setText(QString());
        bcolorEdit->setPlaceholderText(QApplication::translate("LabelStyleSql", "border-color", nullptr));
        bradiusEdit->setText(QString());
        bradiusEdit->setPlaceholderText(QApplication::translate("LabelStyleSql", "border-radius", nullptr));
        backcolorEdit->setPlaceholderText(QApplication::translate("LabelStyleSql", "background-color", nullptr));
        colorEdit->setPlaceholderText(QApplication::translate("LabelStyleSql", "color", nullptr));
        insertBt->setText(QApplication::translate("LabelStyleSql", "\345\242\236\345\212\240", nullptr));
        queryBt->setText(QApplication::translate("LabelStyleSql", "\346\237\245\350\257\242", nullptr));
        deleteBt->setText(QApplication::translate("LabelStyleSql", "\345\210\240\351\231\244", nullptr));
        renewBt->setText(QApplication::translate("LabelStyleSql", "\346\233\264\346\226\260", nullptr));
        testBt->setText(QApplication::translate("LabelStyleSql", "\346\265\213\350\257\225", nullptr));
        testLabel->setText(QApplication::translate("LabelStyleSql", "\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LabelStyleSql: public Ui_LabelStyleSql {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELSTYLESQL_H
