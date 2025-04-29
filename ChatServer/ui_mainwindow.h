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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget_main;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *logEdit;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_gosearch;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *startStopButton;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget_search;
    QWidget *page;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QDateEdit *dateEdit;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *lineEdit_sender;
    QWidget *page_4;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLineEdit *lineEdit_keycode;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_search;
    QSpacerItem *verticalSpacer_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_back;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(462, 466);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        stackedWidget_main = new QStackedWidget(centralwidget);
        stackedWidget_main->setObjectName(QString::fromUtf8("stackedWidget_main"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayout_5 = new QVBoxLayout(page_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(page_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        logEdit = new QPlainTextEdit(groupBox);
        logEdit->setObjectName(QString::fromUtf8("logEdit"));

        horizontalLayout->addWidget(logEdit);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_gosearch = new QPushButton(page_5);
        pushButton_gosearch->setObjectName(QString::fromUtf8("pushButton_gosearch"));

        horizontalLayout_10->addWidget(pushButton_gosearch);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(horizontalSpacer);

        startStopButton = new QPushButton(page_5);
        startStopButton->setObjectName(QString::fromUtf8("startStopButton"));

        horizontalLayout_2->addWidget(startStopButton);


        horizontalLayout_10->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_10);


        verticalLayout_5->addLayout(verticalLayout);

        stackedWidget_main->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        verticalLayout_7 = new QVBoxLayout(page_6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        comboBox = new QComboBox(page_6);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_7->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        stackedWidget_search = new QStackedWidget(page_6);
        stackedWidget_search->setObjectName(QString::fromUtf8("stackedWidget_search"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget_search->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dateEdit = new QDateEdit(page_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2025, 1, 1), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit, 0, 0, 1, 1);

        stackedWidget_search->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        lineEdit_sender = new QLineEdit(page_3);
        lineEdit_sender->setObjectName(QString::fromUtf8("lineEdit_sender"));

        horizontalLayout_5->addWidget(lineEdit_sender);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        stackedWidget_search->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        gridLayout_3 = new QGridLayout(page_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        lineEdit_keycode = new QLineEdit(page_4);
        lineEdit_keycode->setObjectName(QString::fromUtf8("lineEdit_keycode"));

        horizontalLayout_6->addWidget(lineEdit_keycode);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        stackedWidget_search->addWidget(page_4);

        verticalLayout_2->addWidget(stackedWidget_search);


        horizontalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton_search = new QPushButton(page_6);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));

        verticalLayout_3->addWidget(pushButton_search);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_8->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_8);

        textBrowser = new QTextBrowser(page_6);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_4->addWidget(textBrowser);

        verticalLayout_4->setStretch(1, 1);

        verticalLayout_6->addLayout(verticalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        pushButton_back = new QPushButton(page_6);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));

        horizontalLayout_9->addWidget(pushButton_back);


        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_7->addLayout(verticalLayout_6);

        stackedWidget_main->addWidget(page_6);

        gridLayout_4->addWidget(stackedWidget_main, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget_main->setCurrentIndex(1);
        stackedWidget_search->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\346\227\245\345\277\227", nullptr));
        pushButton_gosearch->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\350\256\260\345\275\225", nullptr));
        startStopButton->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\346\234\215\345\212\241\345\231\250", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\350\256\260\345\275\225", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\214\211\346\227\245\346\234\237\346\237\245\350\257\242", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\214\211\347\224\250\346\210\267\346\237\245\350\257\242", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\346\214\211\345\205\263\351\224\256\345\255\227\346\237\245\350\257\242", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\345\205\263\351\224\256\345\255\227\357\274\232", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        pushButton_back->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
