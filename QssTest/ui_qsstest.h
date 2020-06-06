/********************************************************************************
** Form generated from reading UI file 'qsstest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSSTEST_H
#define UI_QSSTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QssTest
{
public:
    QAction *actionnew;
    QAction *actionfile;
    QAction *actionsave;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QssTest)
    {
        if (QssTest->objectName().isEmpty())
            QssTest->setObjectName(QString::fromUtf8("QssTest"));
        QssTest->resize(800, 600);
        QssTest->setStyleSheet(QString::fromUtf8(""));
        actionnew = new QAction(QssTest);
        actionnew->setObjectName(QString::fromUtf8("actionnew"));
        actionfile = new QAction(QssTest);
        actionfile->setObjectName(QString::fromUtf8("actionfile"));
        actionsave = new QAction(QssTest);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        centralwidget = new QWidget(QssTest);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 100, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: bold;\n"
"	background-color:green;\n"
"	border-radius: 5px;\n"
"	border-width: 1px;\n"
"	font-size: 20px;\n"
"	font-weight:20px;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 71, 231, 291));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border-image: url(:/image/image/test.jpg);\n"
"}"));
        QssTest->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QssTest);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        QssTest->setMenuBar(menubar);
        statusbar = new QStatusBar(QssTest);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QssTest->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionnew);
        menu->addAction(actionfile);
        menu->addAction(actionsave);

        retranslateUi(QssTest);

        QMetaObject::connectSlotsByName(QssTest);
    } // setupUi

    void retranslateUi(QMainWindow *QssTest)
    {
        QssTest->setWindowTitle(QApplication::translate("QssTest", "QssTest", nullptr));
        actionnew->setText(QApplication::translate("QssTest", "new", nullptr));
        actionfile->setText(QApplication::translate("QssTest", "file", nullptr));
        actionsave->setText(QApplication::translate("QssTest", "save", nullptr));
        pushButton->setText(QApplication::translate("QssTest", "\346\265\213\350\257\225", nullptr));
        label->setText(QString());
        menu->setTitle(QApplication::translate("QssTest", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QssTest: public Ui_QssTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSSTEST_H
