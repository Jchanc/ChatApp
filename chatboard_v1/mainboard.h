#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <time.h>
#include <iostream>
#include <QString>
#include <vector>
#include <string>
#include <QTcpSocket>

//#include "funcs.h"

/*
 * 实现的只是两个且仅有两个用户之间的通信，须要很大程度的修改
*/

namespace Ui {
class MainBoard;
}

class MainBoard : public QWidget
{
    Q_OBJECT

public:
    time_t timep;
    char tmp[256];
    QStandardItemModel *model = new QStandardItemModel(this);   // 用于展示好友列表的model
    QTcpSocket *TCPsendMsgSocket;                               // 套接字

public:
    explicit MainBoard(std::string usr, QTcpSocket *ts, QWidget *parent = 0);
    ~MainBoard();
    void initList();                // 初始化列表
    void setUsr_Names_Descs();      // 从资源获取好友用户名称和描述/最近一条聊天记录设置于类变量，用于好友列表的展示


private:
    Ui::MainBoard *ui;
    QStringList usrNames;   // 好友用户名/账号
    QStringList usrDescs;   // 好友用户描述/最近聊天记录
    std::string currentChatName;    // 当前聊天框的对象用户名  ！！！须改进，只能显示当前，切换后记录被刷掉
    std::string currentUsrName;     // 当前登陆者用户名

private slots:
    void sender();          // 发送消息
    void receiver();        // 接收消息
    void showSelectedUsr(); // 聊天框显示被选择


private:
    void send2server();

};

#endif // MAINBOARD_H
