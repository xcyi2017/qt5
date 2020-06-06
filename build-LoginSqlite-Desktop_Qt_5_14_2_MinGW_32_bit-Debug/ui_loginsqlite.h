/********************************************************************************
** Form generated from reading UI file 'loginsqlite.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSQLITE_H
#define UI_LOGINSQLITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginSqlite
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QCheckBox *checkBox;
    QLabel *label_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *userEdit;
    QLineEdit *passwordEdit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *checkBt;
    QSplitter *splitter;
    QPushButton *pushButton_2;
    QPushButton *regBt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginSqlite)
    {
        if (LoginSqlite->objectName().isEmpty())
            LoginSqlite->setObjectName(QString::fromUtf8("LoginSqlite"));
        LoginSqlite->resize(437, 315);
        LoginSqlite->setStyleSheet(QString::fromUtf8("background-color:white"));
        centralwidget = new QWidget(LoginSqlite);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 60, 91, 16));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(110, 180, 71, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 50, 71, 21));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/img/baidu.png);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 90, 221, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        userEdit = new QLineEdit(widget);
        userEdit->setObjectName(QString::fromUtf8("userEdit"));
        userEdit->setInputMethodHints(Qt::ImhNone);
        userEdit->setInputMask(QString::fromUtf8(""));
        userEdit->setFrame(true);
        userEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout->addWidget(userEdit);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordEdit);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(130, 200, 157, 54));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBt = new QPushButton(widget1);
        checkBt->setObjectName(QString::fromUtf8("checkBt"));
        checkBt->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);"));

        verticalLayout_2->addWidget(checkBt);

        splitter = new QSplitter(widget1);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter->addWidget(pushButton_2);
        regBt = new QPushButton(splitter);
        regBt->setObjectName(QString::fromUtf8("regBt"));
        splitter->addWidget(regBt);

        verticalLayout_2->addWidget(splitter);

        LoginSqlite->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginSqlite);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 437, 23));
        LoginSqlite->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginSqlite);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginSqlite->setStatusBar(statusbar);

        retranslateUi(LoginSqlite);

        QMetaObject::connectSlotsByName(LoginSqlite);
    } // setupUi

    void retranslateUi(QMainWindow *LoginSqlite)
    {
        LoginSqlite->setWindowTitle(QCoreApplication::translate("LoginSqlite", "LoginSqlite", nullptr));
        label_2->setText(QCoreApplication::translate("LoginSqlite", "\347\224\250\346\210\267\345\220\215\345\257\206\347\240\201\347\231\273\345\275\225", nullptr));
        checkBox->setText(QCoreApplication::translate("LoginSqlite", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("LoginSqlite", "1", nullptr));
        userEdit->setText(QString());
        userEdit->setPlaceholderText(QCoreApplication::translate("LoginSqlite", "\346\211\213\346\234\272/\351\202\256\347\256\261/\347\224\250\346\210\267\345\220\215", nullptr));
        checkBt->setText(QCoreApplication::translate("LoginSqlite", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginSqlite", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        regBt->setText(QCoreApplication::translate("LoginSqlite", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginSqlite: public Ui_LoginSqlite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSQLITE_H
