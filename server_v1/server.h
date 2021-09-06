#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <unordered_map>
#include <iostream>
#include <QSignalMapper>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

public:
    QSqlDatabase database;                          // 连接的数据库
    QSignalMapper *signalMapper;                    // 信号映射，可理解为转发器的一部分
    QList<QTcpSocket*> TCP_connectSockets;          // 用户套接字列表
    std::unordered_map<std::string, int> mapper;    // 记录登陆用户的用户名，对应index为对应用户的套接字

private:
    Ui::Server *ui;
    QTcpServer *TCP_server;

private:
    void connectMYSQL();    // 连接数据库
    void saveMsg();         // 保存聊天记录
    bool checkUsrAccPw_login(std::string acc, std::string pw);  // 登陆验证

signals:
    void signal_locateSocket(int);  // 定位套接字

private slots:
    void slot_startServer();    // 开启服务
    void slot_validation(int);  // 验证登陆
    void slot_newConnect();     // 用户新连接
    void slot_recvMsg();        // 接收消息
    void slot_transmitMsg(int); // 传输消息
    void slot_disconnect();     // 断开连接

};

#endif // SERVER_H
