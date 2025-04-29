#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "databaseinterface.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 800);
    ui->stackedWidget_main->setCurrentIndex(0);
    ui->stackedWidget_search->setCurrentIndex(0);
    m_chatServer = new ChatServer(this);
    connect(m_chatServer,&ChatServer::logMessage, this, &MainWindow::logMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startStopButton_clicked()
{
    if(m_chatServer->isListening())
    {m_chatServer->stopServer();
        ui->startStopButton->setText(QStringLiteral("启动服务器"));
        logMessage(QStringLiteral("服务器已停止"));
    } else {
        if(!m_chatServer->listen(QHostAddress::Any,1967)){
            QMessageBox::critical(this,QStringLiteral("错误"),QStringLiteral("无法启动服务器"));
            return;}
        logMessage(QStringLiteral("服务器已经启动"));
        ui->startStopButton->setText(QStringLiteral("停止服务器"));}


}

void MainWindow::logMessage(const QString &msg)
{
    ui->logEdit->appendPlainText(msg);
}


void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}

void MainWindow::on_pushButton_search_clicked()
{
    if(0 == m_curIndex)
    {
        return;
    }

    QList<MessageInfo> msgList;
    if(1 == m_curIndex)
    {
        QDate date = ui->dateEdit->date();

        QString datestr = date.toString("yyyy/MM/dd");

       msgList = DataBaseInterface::getInstance()->selectFromDate(datestr);
    }
    else if(2 == m_curIndex)
    {
         QString str = ui->lineEdit_sender->text();
         if(str.isEmpty())
         {
             return;
         }
         msgList = DataBaseInterface::getInstance()->selectFromSender(str);
    }
    else if(3 == m_curIndex)
    {
        QString str = ui->lineEdit_keycode->text();
        if(str.isEmpty())
        {
            return;
        }
        msgList = DataBaseInterface::getInstance()->selectFromKeycode(str);
    }

    ui->textBrowser->clear();

    for(auto msg : msgList)
    {
        QString str = msg.sender + " " + msg.message + " " + msg.date;
        ui->textBrowser->append(str);

    }
}

void MainWindow::on_pushButton_gosearch_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->textBrowser->clear();
    m_curIndex = index;
    ui->stackedWidget_search->setCurrentIndex(index);
}
