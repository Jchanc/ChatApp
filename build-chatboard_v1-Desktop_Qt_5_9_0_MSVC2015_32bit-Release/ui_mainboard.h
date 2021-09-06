/********************************************************************************
** Form generated from reading UI file 'mainboard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINBOARD_H
#define UI_MAINBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainBoard
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListView *friendList;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTextBrowser *messShow;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QPlainTextEdit *messInput;
    QPushButton *sender;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_chatUsrName;
    QPushButton *pushButton_3;
    QToolButton *toolButton_6;
    QGraphicsView *graphicsView;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QLabel *label_accUsrName;

    void setupUi(QWidget *MainBoard)
    {
        if (MainBoard->objectName().isEmpty())
            MainBoard->setObjectName(QStringLiteral("MainBoard"));
        MainBoard->resize(964, 591);
        scrollArea = new QScrollArea(MainBoard);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(80, 60, 271, 531));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 269, 529));
        friendList = new QListView(scrollAreaWidgetContents);
        friendList->setObjectName(QStringLiteral("friendList"));
        friendList->setGeometry(QRect(0, 0, 271, 531));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(MainBoard);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(350, 60, 611, 361));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 609, 359));
        messShow = new QTextBrowser(scrollAreaWidgetContents_2);
        messShow->setObjectName(QStringLiteral("messShow"));
        messShow->setGeometry(QRect(0, 0, 611, 361));
        messShow->setStyleSheet(QStringLiteral(""));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        scrollArea_3 = new QScrollArea(MainBoard);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(350, 450, 611, 111));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 609, 109));
        messInput = new QPlainTextEdit(scrollAreaWidgetContents_3);
        messInput->setObjectName(QStringLiteral("messInput"));
        messInput->setGeometry(QRect(0, 0, 611, 111));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        sender = new QPushButton(MainBoard);
        sender->setObjectName(QStringLiteral("sender"));
        sender->setGeometry(QRect(850, 560, 91, 31));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(10);
        sender->setFont(font);
        toolButton = new QToolButton(MainBoard);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(350, 420, 37, 31));
        toolButton_2 = new QToolButton(MainBoard);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(390, 420, 37, 31));
        toolButton_3 = new QToolButton(MainBoard);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(430, 420, 37, 31));
        toolButton_4 = new QToolButton(MainBoard);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(920, 420, 37, 31));
        toolButton_5 = new QToolButton(MainBoard);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(880, 420, 37, 31));
        lineEdit = new QLineEdit(MainBoard);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(112, 19, 191, 31));
        pushButton_2 = new QPushButton(MainBoard);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 20, 31, 31));
        label_chatUsrName = new QLabel(MainBoard);
        label_chatUsrName->setObjectName(QStringLiteral("label_chatUsrName"));
        label_chatUsrName->setGeometry(QRect(380, 20, 191, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        label_chatUsrName->setFont(font1);
        pushButton_3 = new QPushButton(MainBoard);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 20, 31, 31));
        toolButton_6 = new QToolButton(MainBoard);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(910, 20, 41, 41));
        toolButton_6->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        graphicsView = new QGraphicsView(MainBoard);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 61, 61));
        toolButton_7 = new QToolButton(MainBoard);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setGeometry(QRect(20, 120, 41, 41));
        toolButton_8 = new QToolButton(MainBoard);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setGeometry(QRect(20, 170, 41, 41));
        toolButton_9 = new QToolButton(MainBoard);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setGeometry(QRect(20, 220, 41, 41));
        toolButton_10 = new QToolButton(MainBoard);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setGeometry(QRect(20, 270, 41, 41));
        toolButton_11 = new QToolButton(MainBoard);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        toolButton_11->setGeometry(QRect(20, 540, 41, 41));
        toolButton_12 = new QToolButton(MainBoard);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        toolButton_12->setGeometry(QRect(470, 420, 37, 31));
        label_accUsrName = new QLabel(MainBoard);
        label_accUsrName->setObjectName(QStringLiteral("label_accUsrName"));
        label_accUsrName->setGeometry(QRect(10, 80, 61, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(11);
        label_accUsrName->setFont(font2);

        retranslateUi(MainBoard);

        QMetaObject::connectSlotsByName(MainBoard);
    } // setupUi

    void retranslateUi(QWidget *MainBoard)
    {
        MainBoard->setWindowTitle(QApplication::translate("MainBoard", "Form", Q_NULLPTR));
        sender->setText(QApplication::translate("MainBoard", "send", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainBoard", "\360\237\224\215", Q_NULLPTR));
        label_chatUsrName->setText(QString());
        pushButton_3->setText(QApplication::translate("MainBoard", "\342\236\225", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("MainBoard", "\343\200\223\343\200\223", Q_NULLPTR));
        toolButton_7->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_8->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_9->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_10->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_11->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        toolButton_12->setText(QApplication::translate("MainBoard", "...", Q_NULLPTR));
        label_accUsrName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainBoard: public Ui_MainBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINBOARD_H
