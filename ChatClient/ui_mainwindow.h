/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidget_main;
    QWidget *page_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLineEdit *lineEdit_pd;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_loginin;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *loginFrame;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *serverEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *userNameEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QWidget *chatPage;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *roomTextEdit;
    QListWidget *userListWidget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_kickout;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *sayLineEdit;
    QPushButton *sayButton;
    QPushButton *loginoutButton;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_privatename;
    QSpacerItem *horizontalSpacer_3;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_private;
    QPushButton *pushButton_privatesend;
    QPushButton *pushButton_privatereturn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(510, 556);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        stackedWidget_main = new QStackedWidget(centralwidget);
        stackedWidget_main->setObjectName(QString::fromUtf8("stackedWidget_main"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_2 = new QGridLayout(page_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(83, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 30));

        horizontalLayout_8->addWidget(label_3);

        lineEdit_username = new QLineEdit(page_4);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setMinimumSize(QSize(200, 30));
        lineEdit_username->setMaximumSize(QSize(200, 30));

        horizontalLayout_8->addWidget(lineEdit_username);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 30));

        horizontalLayout_9->addWidget(label_4);

        lineEdit_pd = new QLineEdit(page_4);
        lineEdit_pd->setObjectName(QString::fromUtf8("lineEdit_pd"));
        lineEdit_pd->setMinimumSize(QSize(200, 30));
        lineEdit_pd->setMaximumSize(QSize(200, 30));
        lineEdit_pd->setEchoMode(QLineEdit::Password);

        horizontalLayout_9->addWidget(lineEdit_pd);


        verticalLayout_7->addLayout(horizontalLayout_9);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        pushButton_loginin = new QPushButton(page_4);
        pushButton_loginin->setObjectName(QString::fromUtf8("pushButton_loginin"));

        horizontalLayout_10->addWidget(pushButton_loginin);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        verticalLayout_7->addLayout(horizontalLayout_10);


        gridLayout_2->addLayout(verticalLayout_7, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(83, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);

        stackedWidget_main->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayout_6 = new QVBoxLayout(page_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(page_5);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setStyleSheet(QString::fromUtf8("#titleLabel{\n"
"background: white;\n"
"border: none;\n"
"border-bottom: 1px solid black;\n"
"padding: 5px;\n"
"font: 24pt\"\351\273\221\344\275\223\";\n"
"color: rgb(255,255,255);\n"
"background-color:rgba(0,170,127,255);\n"
"}\n"
"#mainFrame {\n"
"border: none;\n"
"background: white;}\n"
"#loginFrame {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ddf, stop: 1 #aaf);\n"
"border: 1px solid gray;\n"
"padding: 10px;\n"
"border-radius: 25px;}"));

        verticalLayout->addWidget(titleLabel);

        stackedWidget = new QStackedWidget(page_5);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        loginPage = new QWidget();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        gridLayout = new QGridLayout(loginPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(31, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        loginFrame = new QFrame(loginPage);
        loginFrame->setObjectName(QString::fromUtf8("loginFrame"));
        loginFrame->setStyleSheet(QString::fromUtf8("#titleLabel{\n"
"background: white;\n"
"color: rgb(255,255,255);\n"
"font-size: 20px;\n"
"border: none;\n"
"border-bottom: 1px sold black;\n"
"padding: 5px;}\n"
"#mainFrame {\n"
"border: none;\n"
"background: white;}\n"
"#loginFrame {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ddf, stop: 1 #aaf);\n"
"border: 1px solid gray;\n"
"padding: 10px;\n"
"border-radius: 25px}"));
        loginFrame->setFrameShape(QFrame::NoFrame);
        verticalLayout_3 = new QVBoxLayout(loginFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(loginFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("#label_2{\n"
"color:black;\n"
"}"));

        horizontalLayout->addWidget(label_2);

        serverEdit = new QLineEdit(loginFrame);
        serverEdit->setObjectName(QString::fromUtf8("serverEdit"));
        serverEdit->setStyleSheet(QString::fromUtf8("#serverEdit{\n"
"background:white;\n"
"color:black;\n"
"}\n"
""));

        horizontalLayout->addWidget(serverEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(loginFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("#label_3{\n"
"color:black;\n"
"}"));

        horizontalLayout_2->addWidget(label);

        userNameEdit = new QLineEdit(loginFrame);
        userNameEdit->setObjectName(QString::fromUtf8("userNameEdit"));
        userNameEdit->setStyleSheet(QString::fromUtf8("#userNameEdit{\n"
"background:white;\n"
"color:black;\n"
"}"));

        horizontalLayout_2->addWidget(userNameEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        loginButton = new QPushButton(loginFrame);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        verticalLayout_3->addWidget(loginButton);


        gridLayout->addWidget(loginFrame, 1, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(32, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 83, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 148, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        stackedWidget->addWidget(loginPage);
        chatPage = new QWidget();
        chatPage->setObjectName(QString::fromUtf8("chatPage"));
        verticalLayout_4 = new QVBoxLayout(chatPage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        roomTextEdit = new QTextEdit(chatPage);
        roomTextEdit->setObjectName(QString::fromUtf8("roomTextEdit"));
        roomTextEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(roomTextEdit);

        userListWidget = new QListWidget(chatPage);
        userListWidget->setObjectName(QString::fromUtf8("userListWidget"));
        userListWidget->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(userListWidget);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        pushButton_kickout = new QPushButton(chatPage);
        pushButton_kickout->setObjectName(QString::fromUtf8("pushButton_kickout"));

        horizontalLayout_7->addWidget(pushButton_kickout);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sayLineEdit = new QLineEdit(chatPage);
        sayLineEdit->setObjectName(QString::fromUtf8("sayLineEdit"));

        horizontalLayout_4->addWidget(sayLineEdit);

        sayButton = new QPushButton(chatPage);
        sayButton->setObjectName(QString::fromUtf8("sayButton"));

        horizontalLayout_4->addWidget(sayButton);

        loginoutButton = new QPushButton(chatPage);
        loginoutButton->setObjectName(QString::fromUtf8("loginoutButton"));

        horizontalLayout_4->addWidget(loginoutButton);


        verticalLayout_4->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(chatPage);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_privatename = new QLabel(page);
        label_privatename->setObjectName(QString::fromUtf8("label_privatename"));
        label_privatename->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(label_privatename);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_5);

        textBrowser = new QTextBrowser(page);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_5->addWidget(textBrowser);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_private = new QLineEdit(page);
        lineEdit_private->setObjectName(QString::fromUtf8("lineEdit_private"));

        horizontalLayout_6->addWidget(lineEdit_private);

        pushButton_privatesend = new QPushButton(page);
        pushButton_privatesend->setObjectName(QString::fromUtf8("pushButton_privatesend"));

        horizontalLayout_6->addWidget(pushButton_privatesend);

        pushButton_privatereturn = new QPushButton(page);
        pushButton_privatereturn->setObjectName(QString::fromUtf8("pushButton_privatereturn"));

        horizontalLayout_6->addWidget(pushButton_privatereturn);


        verticalLayout_5->addLayout(horizontalLayout_6);

        stackedWidget->addWidget(page);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_6->addLayout(verticalLayout);

        stackedWidget_main->addWidget(page_5);

        verticalLayout_8->addWidget(stackedWidget_main);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget_main->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_loginin->setText(QCoreApplication::translate("MainWindow", "\347\231\273\351\231\206", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\346\235\245\345\210\260\350\201\212\345\244\251\345\256\244", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200:", nullptr));
        serverEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "       \346\230\265\347\247\260    : ", nullptr));
        userNameEdit->setText(QString());
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225\350\201\212\345\244\251\345\256\244", nullptr));
        pushButton_kickout->setText(QCoreApplication::translate("MainWindow", "\350\270\242\345\207\272", nullptr));
        sayButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        loginoutButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_privatename->setText(QString());
        pushButton_privatesend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        pushButton_privatereturn->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\345\244\247\345\216\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
