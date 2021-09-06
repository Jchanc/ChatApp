#include "loginwin.h"
#include "mainboard.h"
#include "ui_loginwin.h"
#include <QString>
#include <iostream>
#include <QMessageBox>

LoginWin::LoginWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWin)
{
    // 初始化
    ui->setupUi(this);
    this->setWindowTitle("Welcome");
    this->connectedServer=false;
    // 添加连接
    QObject::connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(loginCheck()));
    QObject::connect(ui->registerButton, SIGNAL(clicked()), this, SLOT(registerOpt()));

}

LoginWin::~LoginWin()
{
    delete ui;
}

void LoginWin::loginCheck()
{
    bool success=true;
    this->TCP_sendMsgSocket = new QTcpSocket();
    std::string account = ui->accountInput->text().toStdString();       // 界面账号输入
    std::string password = ui->passwordInput->text().toStdString();     // 界面密码输入
    //qDebug() << "account: " << QString::fromStdString(account);
    //qDebug() << "password: " << QString::fromStdString(password);

    // 如果输入不合法，提示重新输入
    if (account.empty() || password.empty()){
        success = false;
        QMessageBox::warning(this, "error", "account or password can not be blank!", QMessageBox::Ok);
    }
    else{
        // tcp 连接服务端
        // 本机测试，可实现可交互的IP、端口设置
        this->TCP_sendMsgSocket->connectToHost("localhost", 9123);

        connectedServer = TCP_sendMsgSocket->waitForConnected(6000);
        //qDebug() << "connected server : " << connectedServer;

        if (connectedServer){
            // （可加密）发送账号密码至服务器
            std::string apMsg = account + ":" + password;       // "acc:pw"，服务端解析
            this->TCP_sendMsgSocket->write(QString::fromStdString(apMsg).toUtf8());

            // 等待服务器验证账号密码
            if (TCP_sendMsgSocket->waitForReadyRead(3000)){
                QByteArray byteArray = this->TCP_sendMsgSocket->readAll();
                QString validation = byteArray;
                if (validation.compare(QString::fromLocal8Bit("t")) == 0){     // 如果服务器判断登陆信息正确则返回`t`
                    success = true;
                }else {
                    success = false;
                    QMessageBox::warning(this,"error", "account or password not correct!",QMessageBox::Ok);
                }
            }
            else {
                success = false;
                QMessageBox::warning(this,"error", "cannot connect server!",QMessageBox::Ok);
            }
        }
        else {
            // 服务器连接失败，无法登陆
            success = false;
            QMessageBox::warning(this,"error","cannot connect server!",QMessageBox::Ok);
        }
    }
    if (success) {
        // 验证成功，跳转至主页面
        auto mainboard = new MainBoard(account, TCP_sendMsgSocket);
        this->hide();     // 隐藏登陆界面
        mainboard->show(); // 显示主界面
    }

}

void LoginWin::registerOpt()
{
    // 注册，跳转注册界面
    // developing ...
}
