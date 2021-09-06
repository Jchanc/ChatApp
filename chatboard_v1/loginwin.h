#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QWidget>
#include <string>
#include <QTcpSocket>
//#include "mainboard.h"

namespace Ui {
class LoginWin;
}

class LoginWin : public QWidget
{
    Q_OBJECT

public:
    LoginWin(QWidget *parent = 0);
    ~LoginWin();

public:
    bool connectedServer;       // 是否成功连接数据库的标识
    QTcpSocket *TCP_sendMsgSocket;  // 套接字

private slots:
    void loginCheck();  // 登陆验证
    void registerOpt(); // 注册账号

private:
    Ui::LoginWin *ui;

private:
    std::string current_account;    // 账号
    std::string current_password;   // 密码
};

#endif // LOGINWIN_H
