#include "server.h"
#include "ui_server.h"

#include <QDateTime>
#include <QMessageBox>

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    connectMYSQL();
    // 初始化
    mapper = std::unordered_map<std::string, int>();
    TCP_server = new QTcpServer();
    signalMapper = new QSignalMapper(this);
    this->TCP_connectSockets = QList<QTcpSocket* >();

    // 添加连接
    connect(ui->startService, SIGNAL(clicked()), this, SLOT(slot_startServer()));
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(slot_transmitMsg(int)));
    connect(this, SIGNAL(signal_locateSocket(int)), this, SLOT(slot_validation(int)));
}

Server::~Server()
{
    delete ui;
}

void Server::slot_startServer(){
    ui->serverBehaviors->append("already start service.\n");
    if(TCP_server->listen(QHostAddress::LocalHost, 9123))
    {
        this->connect(TCP_server, SIGNAL(newConnection()), this, SLOT(slot_newConnect()));
        ui->startService->hide();
    } else
    {
        QMessageBox::critical(this, "error","IP binding error, close other servers or change the binding port!");
    }
}

void Server::slot_newConnect(){
    // 新用户连接，首先验证账号信息
    if(TCP_server->hasPendingConnections())
    {
        int index = TCP_connectSockets.size();
        QTcpSocket *TCP_connectSocket_tmp = TCP_server->nextPendingConnection();
        TCP_connectSockets.append(TCP_connectSocket_tmp);

        if(TCP_connectSocket_tmp->waitForReadyRead())
        {
            emit signal_locateSocket(index);    //  告诉服务端是index套接字进行登陆请求
        }
    }
}

void Server::slot_validation(int i){
    QString clientAddr, clientPort, clientName, userAcc, userPw;
    QString localTime = QDateTime::currentDateTime().toString(" yyyy-M-dd hh:mm:ss")+"\n";
    int index = i;

    if (index<TCP_connectSockets.size() && TCP_connectSockets[index] != nullptr)
    {
        clientAddr = TCP_connectSockets[index]->peerAddress().toString();
        clientPort = TCP_connectSockets[index]->peerPort();
        clientName = TCP_connectSockets[index]->peerName();

        QByteArray array = TCP_connectSockets[index]->readAll();
        QString str = array;    // 接收的信息格式: "account:password"
        QStringList info = str.split(":");
        userAcc = info[0];
        userPw = info[1];
        //qDebug() << "account:" << userAcc << " password:" << userPw;

        mapper[userAcc.toStdString()]=index;

        ui->clientBehaviors->append(localTime+"***"+"user account["+userAcc+"][IP"+clientAddr+"][Port"+clientPort+"][CName:"+clientName+"] trying to login.\n");
        // 验证账号密码
        bool isok = checkUsrAccPw_login(userAcc.toStdString(), userPw.toStdString());
        localTime = QDateTime::currentDateTime().toString(" yyyy-M-dd hh:mm:ss")+"\n";
        if(TCP_connectSockets[index] != nullptr)
        {
            QString msg;
            if (isok)
            {
                msg = "t";      // 验证成功，返回标识符 t
                connect(TCP_connectSockets[index], SIGNAL(readyRead()), signalMapper, SLOT(map()));
                signalMapper->setMapping(TCP_connectSockets[index], index);
            }
            else { msg = "f"; } // 验证失败，返回标识符 f
            TCP_connectSockets[index]->write(msg.toUtf8());
        }
        ui->serverBehaviors->append(localTime+"***"+"verifying login request from account["+userAcc+"]. result: login "+ ((isok)?"successful": "failed.")+"\n");
    }
}

void Server::slot_recvMsg(){

}

void Server::slot_transmitMsg(int i)
{
    // 接收并发送信息，该函数实现的只是2个用户之间的信息传输，多用户即群聊待实现
    int index=i;
    QString clientAddr = TCP_connectSockets[index]->peerAddress().toString();
    QByteArray array = TCP_connectSockets[index]->readAll();
    qDebug() << array;  // 接收的消息格式: "FromWho:::ToWho:::SendTime:::Content"
    QString str = array;
    QStringList info = str.split(":::");
    QString from=info[0], to=info[1], time=info[2], content=info[3];    // 解析，各字段使用:::分隔，info[3]指发送消息的内容，内容可能含:::，后续内容可能被截断，待改进

    QString localTime = QDateTime::currentDateTime().toString(" yyyy-M-dd hh:mm:ss")+"\n";
    ui->clientBehaviors->append(localTime+"***"+"user account["+from+"][IP:"+clientAddr+"] trying to send message to account["+to+"].\n");

    if(TCP_connectSockets[index] != nullptr)
    {
        QString msg;
        localTime = QDateTime::currentDateTime().toString(" yyyy-M-dd hh:mm:ss")+"\n";

        int toWho = mapper[to.toStdString()];
        msg = from+":::"+time+":::"+content;    // 转换发送信息格式
        TCP_connectSockets[toWho]->write(msg.toUtf8());     // 通过mapper找到需要消息发送的用户套接字
        //qDebug() << msg;
    }
    ui->serverBehaviors->append(localTime+"***"+"transmit message from account["+from+"] to account["+to+"]. Processed.\n");
}

bool Server::checkUsrAccPw_login(std::string acc, std::string pw)
{
    // 验证账号密码
    QSqlQuery query(database);
    std::string query_string = "select * from userinfo where account='"+acc+"'";
    query.exec(QString::fromStdString(query_string));   // 数据库查询
    bool correct;
    while(query.next())
    {
        // 用户信息表：（账号，密码，昵称，最近登陆IP，最近登陆时间，登陆状态）  [待完善]
        std::string right_pw = query.value(1).toString().toStdString();    //value(1) 对应密码
        if (pw == right_pw) correct = true;
        else correct = false;
    }
    // note: 运行时数据库驱动显示无法加载，连接失败
    // +++++ 故使用如下的假定进行测试
    // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (pw == "123" && (acc=="user1" || acc=="user2" || acc=="user3" || acc=="user4"))
        return true;
    else
        return false;
   // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    return correct;
}

void Server::connectMYSQL()
{
    // 连接数据库
    if(QSqlDatabase::contains("chatboard"))
    {
        database = QSqlDatabase::database("chatboard");
    }
    else{
        // 连接数据库的设置
        database = QSqlDatabase::addDatabase("QMYSQL");
        database.setDatabaseName("chatboard");
        database.setHostName("localhost");
        database.setPort(3306);
        database.setUserName("root");
        database.setPassword("");
    }
    if(!database.open())
    {
        qDebug() << "failed to connect mysql." << database.lastError().text();
    }
}

void Server::saveMsg()
{
    // 保存聊天记录
}

void Server::slot_disconnect()
{
    // 断开连接
}














