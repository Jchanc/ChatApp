/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *startService;
    QPushButton *endService;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListView *clientConnections;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *totalAccounts;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_4;
    QTextBrowser *serverBehaviors;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QTextBrowser *clientBehaviors;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(1098, 620);
        groupBox = new QGroupBox(Server);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 1101, 621));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayoutWidget_4 = new QWidget(groupBox);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 510, 391, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        startService = new QPushButton(verticalLayoutWidget_4);
        startService->setObjectName(QStringLiteral("startService"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Devanagari"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        startService->setFont(font);

        verticalLayout_3->addWidget(startService);

        endService = new QPushButton(verticalLayoutWidget_4);
        endService->setObjectName(QStringLiteral("endService"));
        endService->setFont(font);

        verticalLayout_3->addWidget(endService);

        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 391, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        clientConnections = new QListView(verticalLayoutWidget_3);
        clientConnections->setObjectName(QStringLiteral("clientConnections"));

        verticalLayout->addWidget(clientConnections);

        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 410, 341, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        totalAccounts = new QLCDNumber(horizontalLayoutWidget);
        totalAccounts->setObjectName(QStringLiteral("totalAccounts"));
        sizePolicy1.setHeightForWidth(totalAccounts->sizePolicy().hasHeightForWidth());
        totalAccounts->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(totalAccounts);

        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(410, 360, 681, 251));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setContentsMargins(11, 11, 11, 11);
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout_1->addWidget(label_4);

        serverBehaviors = new QTextBrowser(verticalLayoutWidget);
        serverBehaviors->setObjectName(QStringLiteral("serverBehaviors"));

        verticalLayout_1->addWidget(serverBehaviors);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(410, 10, 681, 341));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        clientBehaviors = new QTextBrowser(verticalLayoutWidget_2);
        clientBehaviors->setObjectName(QStringLiteral("clientBehaviors"));
        sizePolicy.setHeightForWidth(clientBehaviors->sizePolicy().hasHeightForWidth());
        clientBehaviors->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(clientBehaviors);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", Q_NULLPTR));
        groupBox->setTitle(QString());
        startService->setText(QApplication::translate("Server", "Start Service", Q_NULLPTR));
        endService->setText(QApplication::translate("Server", "End Service", Q_NULLPTR));
        label_2->setText(QApplication::translate("Server", "Client Connections", Q_NULLPTR));
        label->setText(QApplication::translate("Server", "        Total Accounts", Q_NULLPTR));
        label_4->setText(QApplication::translate("Server", "Server Behaviors", Q_NULLPTR));
        label_5->setText(QApplication::translate("Server", "Client Behaviors", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
