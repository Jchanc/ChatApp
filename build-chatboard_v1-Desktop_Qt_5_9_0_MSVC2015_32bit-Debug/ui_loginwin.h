/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QPushButton *loginButton;
    QLineEdit *accountInput;
    QLabel *label_account;
    QLabel *label_password;
    QPushButton *registerButton;
    QLineEdit *passwordInput;

    void setupUi(QWidget *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QStringLiteral("LoginWin"));
        LoginWin->resize(271, 333);
        loginButton = new QPushButton(LoginWin);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(70, 230, 141, 31));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(12);
        loginButton->setFont(font);
        loginButton->setStyleSheet(QStringLiteral(""));
        accountInput = new QLineEdit(LoginWin);
        accountInput->setObjectName(QStringLiteral("accountInput"));
        accountInput->setGeometry(QRect(110, 130, 121, 21));
        label_account = new QLabel(LoginWin);
        label_account->setObjectName(QStringLiteral("label_account"));
        label_account->setGeometry(QRect(50, 120, 61, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(11);
        label_account->setFont(font1);
        label_password = new QLabel(LoginWin);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(40, 160, 71, 16));
        label_password->setFont(font1);
        registerButton = new QPushButton(LoginWin);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(70, 270, 141, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(10);
        registerButton->setFont(font2);
        registerButton->setStyleSheet(QStringLiteral(""));
        passwordInput = new QLineEdit(LoginWin);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));
        passwordInput->setGeometry(QRect(110, 160, 121, 21));

        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QWidget *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "LoginWin", Q_NULLPTR));
        loginButton->setText(QApplication::translate("LoginWin", "Login", Q_NULLPTR));
        label_account->setText(QApplication::translate("LoginWin", "account", Q_NULLPTR));
        label_password->setText(QApplication::translate("LoginWin", "password", Q_NULLPTR));
        registerButton->setText(QApplication::translate("LoginWin", "Register", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
