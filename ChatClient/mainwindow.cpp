#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>

#include <QUuid>

#define USER_ROLE  Qt::UserRole+8
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 800);
    initSql();
    initUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initSql()
{
    DataBaseInterface::getInstance()->createTable();

    m_userInfoList = DataBaseInterface::getInstance()->getUserInfo();


}

void MainWindow::initUi()
{

    ui->pushButton_kickout->setVisible(false);
    ui->stackedWidget_main->setCurrentIndex(0);
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    m_chatClient = new ChatClient(this);
    //connect(m_chatClient,&ChatClient::messageReceived, this,&MainWindow::messageReceived);
    connect(m_chatClient,&ChatClient::connected, this,&MainWindow::connectedToServer);
    connect(m_chatClient,&ChatClient::jsonReceived,this, &MainWindow:: jsonReceived);
}
void MainWindow::on_loginButton_clicked()
{
    m_chatClient->connectToserver(QHostAddress(ui->serverEdit->text()),1967);
}

void MainWindow::connectedToServer()
{
    ui->stackedWidget->setCurrentWidget(ui->chatPage);
    QUuid id = QUuid::createUuid();
    m_uuid = id.toString();
    m_chatClient->sendMessage(ui->userNameEdit->text(),"login", m_uuid);
}

void MainWindow::messageReceived(const QString &sender, const QString &text, const bool &bpublic)
{
    if(bpublic)
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->roomTextEdit->append(QString("%1 : %2").arg(sender).arg(text));
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->textBrowser->append(QString("%1 : %2").arg(sender).arg(text));
    }
}


void MainWindow::messageReceived(const QString &sender,const QString &text)
{
    ui->roomTextEdit->append(QString("%1 : %2").arg(sender).arg(text));
}

void MainWindow::jsonReceived(const QJsonObject &docObj)
{
    const QJsonValue typeVal= docObj.value("type");
    if(typeVal.isNull()||!typeVal.isString())
        return;
    if(typeVal.toString().compare("message",Qt::CaseInsensitive)==0){
        const QJsonValue textVal= docObj.value("text");
        const QJsonValue senderVal= docObj.value("sender");
        const QJsonValue privateUuid = docObj.value("destid");
        const QJsonValue privateSourceUuid = docObj.value("sourceid");


        qDebug() <<__FUNCTION__ << privateUuid.toString() <<  privateSourceUuid.toString();

        bool bPublic = false;
         if("id" == privateUuid.toString())
        {
            //! 所有人聊天
            bPublic = true;
        }
        else if(m_uuid == privateUuid.toString() || m_uuid ==  privateSourceUuid.toString())
        {
             if(m_uuid != privateSourceUuid.toString())
             {
                 m_privateChatUuid = privateSourceUuid.toString();
             }
             //! 收到之后对方的源id是本段的目的id
            //! 私信
           bPublic = false;
        }
        else
        {
            return;
        }
        if(textVal.isNull()||!textVal.isString())
            return;
        if(senderVal.isNull()||!senderVal.isString())
            return;


        messageReceived(senderVal.toString(),textVal.toString(), bPublic);

    }else if(typeVal.toString().compare("newuser",Qt::CaseInsensitive)==0){
        const QJsonValue usernameVal =docObj.value("username");
        if(usernameVal.isNull()||!usernameVal.isString())
            return;

        userJoined(usernameVal.toString());

    }else if(typeVal.toString().compare("userdisconnected",Qt::CaseInsensitive)==0){
        const QJsonValue usernameVal =docObj.value("username");
        if(usernameVal.isNull()||!usernameVal.isString())
            return;

        userLeft(usernameVal.toString());

    }else if(typeVal.toString().compare("userlist", Qt::CaseInsensitive)==0)
    {//user list
        QMap<QString , QVariant> varMap;
        varMap = docObj.toVariantMap();

        QMap<QString , QVariant> userinfoMap = varMap["userlist"].toMap();
        if(userinfoMap.isEmpty())
        {
            return;
        }
        const QJsonValue userlistVal = docObj.value("userlist");

        QMap<QString, QVariant> userInfoMap;
        userInfoMap = userlistVal.toVariant().toMap();
        qDebug()<< userlistVal.toVariant().toStringList();
        userListReceivedWithId(userInfoMap);
        //        userListReceived(userlistVal.toVariant().toStringList());

    }
    else if(typeVal.toString().compare("kickout", Qt::CaseInsensitive)==0)
    {
        const QJsonValue userid = docObj.value("userid");
        if(userid.isNull()||!userid.isString())
            return;
        if(m_uuid == userid.toString())
        {
            on_loginoutButton_clicked();
        }
        else
        {

        }
    }
}

void MainWindow::userJoined(const QString &user)
{
    ui->userListWidget->addItem(user);
}

void MainWindow::userLeft(const QString &user)
{
    for( auto aItem : ui->userListWidget->findItems(user,Qt::MatchExactly)){
        qDebug("remove");
        ui->userListWidget->removeItemWidget(aItem);
        delete aItem;
    }
}




void MainWindow::on_sayButton_clicked()
{
    if(!ui->sayLineEdit->text().isEmpty())
        m_chatClient->sendMessage(ui->sayLineEdit->text());
}


void MainWindow::on_loginoutButton_clicked()

{
    m_chatClient->disconnectFromHost();
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    for( auto aItem : ui->userListWidget->findItems(ui->userNameEdit->text(),Qt::MatchExactly)){
        qDebug("remove");
        ui->userListWidget->removeItemWidget(aItem);
        delete aItem;
    }
}

void MainWindow::userListReceived(const QStringList &list)
{
    ui->userListWidget->clear();
    ui->userListWidget->addItems(list);
}




void MainWindow::on_userListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << __FUNCTION__ <<item->data(USER_ROLE).toString();
    if(m_uuid == item->data(USER_ROLE).toString())
    {
        return;
    }

    m_privateChatUuid = item->data(USER_ROLE).toString();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::userListReceivedWithId(const QMap<QString, QVariant> & userMap)
{
    ui->userListWidget->clear();
    for(auto & user: userMap.keys())
    {
        QListWidgetItem * item = new QListWidgetItem(userMap[user].toString());
        item->setData(USER_ROLE, user);
        ui->userListWidget->addItem(item);
    }
}



void MainWindow::on_pushButton_privatereturn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_privatesend_clicked()
{
    if(ui->lineEdit_private->text().isEmpty())
    {
        return;
    }
    m_chatClient->sendMessage(ui->lineEdit_private->text(), "message", m_privateChatUuid, m_uuid);

    ui->lineEdit_private->clear();
}

void MainWindow::on_pushButton_kickout_clicked()
{
    if(m_kickOutUuid.isEmpty())
    {
        return;
    }
    m_chatClient->sendMessage("kickout", "kickout", m_kickOutUuid, m_uuid);

}

void MainWindow::on_pushButton_loginin_clicked()
{
    QString name = ui->lineEdit_username->text();
    QString pwd = ui->lineEdit_pd->text();
    if(name.isEmpty() || pwd.isEmpty())
    {
        return;
    }

    UserInfo temp_userInfo;
    bool rslt = false;
    for(auto & userinfo : m_userInfoList)
    {
        if(name == userinfo.username && pwd == userinfo.pwd)
        {
            temp_userInfo = userinfo;
            rslt = true;
        }
    }


    if(rslt && 1 == temp_userInfo.type)
    {
        ui->stackedWidget_main->setCurrentIndex(1);
        ui->pushButton_kickout->setVisible(true);
    }
    else if (rslt && 0 == temp_userInfo.type) {
        ui->pushButton_kickout->setVisible(false);
        ui->stackedWidget_main->setCurrentIndex(1);
    }



}



void MainWindow::on_userListWidget_itemClicked(QListWidgetItem *item)
{
    qDebug() << __FUNCTION__ <<item->data(USER_ROLE).toString();
    if(m_uuid == item->data(USER_ROLE).toString())
    {
        return;
    }

    m_kickOutUuid = item->data(USER_ROLE).toString();




}
