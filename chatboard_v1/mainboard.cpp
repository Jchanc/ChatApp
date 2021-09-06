#include "mainboard.h"
#include "mulistitemdata.h"
#include "muitemdelegate.h"
#include "ui_mainboard.h"
#include <QDebug>
#include <QDateTime>

MainBoard::MainBoard(std::string usr, QTcpSocket *ts, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainBoard)
{
    // 初始化
    currentUsrName = usr;
    this->TCPsendMsgSocket = ts;
    ui->setupUi(this);
    this->setWindowTitle("ChatBoard");
    ui->label_accUsrName->setText(QString::fromStdString(currentUsrName));
    initList();     // 初始化好友列表
    // 添加连接
    QObject::connect(ui->sender, SIGNAL(clicked()), this, SLOT(sender()));
    QObject::connect(ui->friendList->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(showSelectedUsr()));
    QObject::connect(TCPsendMsgSocket,SIGNAL(readyRead()),this,SLOT(receiver()));
}

MainBoard::~MainBoard()
{
    delete ui;
}

void MainBoard::sender(){
    // 发送消息
    QString content = ui->messInput->toPlainText();
    if(content.toStdString()=="" || content == nullptr)
    {
        // 提示发送消息不能为空，可使用<QMessageBox>进行相关的提示
        //qDebug() << "null content!";
    }
    else{
        std::string localTime;
        time(&timep);
        strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
        localTime = tmp;
        QString time_qstring = QString::fromStdString(localTime);

        // 发送的消息在当前用户聊天框直接显示
        ui->messInput->setDocument(nullptr);
        ui->messShow->moveCursor(QTextCursor::End);
        ui->messShow->setAlignment(Qt::AlignCenter);
        ui->messShow->insertPlainText(time_qstring+"\n");
        ui->messShow->setAlignment(Qt::AlignRight);         // 存在缺陷
        ui->messShow->insertPlainText("["+QString::fromStdString(currentUsrName)+"]\n"+content+"\n\n");

        // 将被发送的消息内容+当前用户+当前聊天对象+时间格式化为"from:::to:::time:::content"传给服务端，服务端进行处理并将内容发送给当前聊天对象用户(to)
        QString content2server = QString::fromStdString(currentUsrName)+":::"+QString::fromStdString(currentChatName)+":::"+time_qstring+":::"+content;
        this->TCPsendMsgSocket->write(content2server.toUtf8());
    }
}

void MainBoard::receiver(){
    // 从服务端接收消息
    QByteArray byteArray;
    byteArray = this->TCPsendMsgSocket->readAll();
    qDebug() << byteArray;
    QString tmp = byteArray;
    QStringList data = tmp.split(":::");
    QString msgFromWho = data[0];
    QString msgSendTime = data[1];
    QString msgContent = data[2];
    // 只在聊天框展示信息
    ui->messShow->moveCursor(QTextCursor::End);
    ui->messShow->setAlignment(Qt::AlignCenter);
    ui->messShow->insertPlainText(msgSendTime+"\n");
    ui->messShow->setAlignment(Qt::AlignLeft);
    ui->messShow->insertPlainText("["+msgFromWho+"]\n"+msgContent+"\n\n");
}


void MainBoard::showSelectedUsr(){
    // 切换并显示与当前选中好友用户的聊天框
    QItemSelectionModel *selmodel = ui->friendList->selectionModel();
    if(selmodel){
        QModelIndex index = selmodel->selectedIndexes()[0];
        QString usr = ui->friendList->model()->data(index, Qt::DisplayRole).toString();

        ui->label_chatUsrName->setText(usr);
        ui->messInput->setEnabled(true);
        ui->messShow->setEnabled(true);
        currentChatName = usr.toStdString();

        //QString all_chatContent = ui->messShow->toPlainText();
        // +++ 解析当前聊天内容，并存储到本地/数据库中记录
        ui->messShow->setText(nullptr);     // 清空（缺陷）
        // +++ 从数据库中获取历史信息/在本地调取历史信息 进行展示
        // showMsg
    }
}

void MainBoard::initList()
{
    // 好友列表展示
    //
    // 需求：好友信息存在本地或数据库，优先从本地获取数据以展示好友列表，若本地无相关数据则从数据库获取 等
    // 假设此处已获取相关信息
    QStandardItemModel *pModel = new QStandardItemModel();
    setUsr_Names_Descs();

    for(int i=0; i<usrNames.size(); i++){
        QStandardItem *pItem = new QStandardItem(usrNames.at(i));
        MuItemData itemData;
        itemData.usrName = usrNames.at(i);
        itemData.desc = usrDescs.at(i);
        //itemData.iconPath = ...：  // 添加头像
        pItem->setData(QVariant::fromValue(itemData), Qt::UserRole+1);
        pModel->appendRow(pItem);
    }

    MuItemDelegate *pItemDelegate = new MuItemDelegate(this);
    ui->friendList->setItemDelegate(pItemDelegate);
    ui->friendList->setModel(pModel);
    ui->messInput->setEnabled(false);
    ui->messShow->setEnabled(false);

}

void MainBoard::setUsr_Names_Descs(){
    // 从本地/数据库中获取当前账户的所有好友昵称/ID和描述
    // 赋值给usrNames, usrDescs

    // 从本地数据文件获取 的实现
    // ...

    // 从数据库获取 的实现
    // ...

    // 测试用 （假设）
    std::vector<std::string> names = { "user1", "user2"};
    std::vector<std::string> descs = {"nothing...", "nothing..."};

    for (int i=0; i<names.size(); i++){
        if (currentUsrName != names[i]){
            usrNames.append(QString::fromStdString(names[i]));
            usrDescs.append(QString::fromStdString(descs[i]));
        }
    }
}

