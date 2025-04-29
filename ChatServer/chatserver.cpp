#include "chatserver.h"
#include "serverworker.h"
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include "databaseinterface.h"
#include <QDate>
ChatServer::ChatServer(QObject *parent ) :
    QTcpServer(parent)
{
    DataBaseInterface::getInstance()->createTable();
}

void ChatServer::incomingConnection(qintptr socketDescriptor)
{
    ServerWorker *worker = new ServerWorker(this);
    if(!worker->setSocketDesctiptor(socketDescriptor)){
        worker->deleteLater();
        return;
    }
    connect(worker,&ServerWorker::logMessage,this,&ChatServer::logMessage);
    connect(worker,&ServerWorker::jsonReceived,this,&ChatServer::jsonReceived);
    connect(worker,&ServerWorker::disconnectedFromclient, this,
            std::bind(&ChatServer::userDisconnected,this,worker));
    m_clients.append(worker);
    //emit logMessage(QStringLiteral("新的用户连接上了"));

}

void ChatServer::broadcast(const QJsonObject &message, ServerWorker *exelude)
{
    for(ServerWorker *worker :m_clients){
        worker->sendJson(message);
    }
}

void ChatServer::boradcastUserKickout(const QString &userid)
{
    for(auto key : m_userMap.keys())
    {
        //! 存在被踢用户
        if(key == userid)
        {
            m_userMap.remove(key);
            for(ServerWorker *worker:m_clients)
            {
                QJsonObject message;
                message[QStringLiteral("type")]="kickout";
                message[QStringLiteral("userid")]= userid;
                worker->sendJson(message);

            }

//            for(ServerWorker *worker:m_clients)
//            {
//                QJsonObject message;
//                message[QStringLiteral("type")]="kickout";
//                message[QStringLiteral("userid")]= userid;
//                worker->sendJson(message);

//            }



        }
    }
}

void ChatServer::saveMessage(const QString &sender, const QString &message)
{
    MessageInfo msgInfo;
    msgInfo.sender = sender;
    msgInfo.message = message;
    QDate date = QDate::currentDate();
    QString datestr = date.toString("yyyy/MM/dd");

    msgInfo.date = datestr;

    DataBaseInterface::getInstance()->insertMessage(msgInfo);


}

void ChatServer::stopServer()
{
    close();
}

void ChatServer::jsonReceived(ServerWorker *sender, const QJsonObject &docObj)
{
    const QJsonValue typeVal= docObj.value("type");
    if(typeVal.isNull()||!typeVal.isString())
        return;
    if(typeVal.toString().compare("message",Qt::CaseInsensitive)==0){
        const QJsonValue textVal= docObj.value("text");
        if(textVal.isNull()||!textVal.isString())
            return;
        const QString text=textVal.toString().trimmed();
        if(text.isEmpty())return;
        QJsonObject message;
        message[QStringLiteral("type")]="message";
        message[QStringLiteral("text")]= text;
        message[QStringLiteral("sender")]=sender->userName();
        message[QStringLiteral("destid")]=docObj.value("destid").toString();
        message[QStringLiteral("sourceid")]=docObj.value("sourceid").toString();

        saveMessage(sender->userName(), text);
        broadcast(message,sender);
    }else if(typeVal.toString().compare("login",Qt::CaseInsensitive)==0)
    {
        const QJsonValue usernameVal =docObj.value("text");
        if(usernameVal.isNull()||!usernameVal.isString())
            return;

        const QJsonValue userUuid =docObj.value("destid");
        if(userUuid.isNull()||!userUuid.isString())
            return;


        qDebug() <<__FUNCTION__ <<userUuid.toString();
        sender->setUserName(usernameVal.toString());
        sender->setUserId(userUuid.toString());
        QJsonObject connectedMessage;
        connectedMessage["type"]="newuser";
        connectedMessage["username"]=usernameVal.toString();
        connectedMessage["userid"]=userUuid.toString();
//         broadcast(connectedMessage,sender);

        //send user list to new logined user
        QJsonObject userListMessage;
        userListMessage["type"]="userlist";
        QJsonArray userlist;
        QMap<QString, QVariant> userMap;

        for(ServerWorker *worker:m_clients)
        {
            if(worker == sender)
            {
                userlist.append(worker->userName()+ "*" );
            }
            else
            {

                userlist.append(worker->userName());
            }
            userMap.insert(worker->userId(), worker->userName());
        }
        userListMessage["userlist"]= QJsonObject::fromVariantMap(userMap);
//        sender->sendJson(userListMessage);

        broadcast(userListMessage,sender);
        m_userMap = userMap;

    }
    else if(typeVal.toString().compare("kickout",Qt::CaseInsensitive)==0)
    {


        const QJsonValue userUuid =docObj.value("destid");
        if(userUuid.isNull()||!userUuid.isString())
            return;

        //send user list to new logined user
        QJsonObject userListMessage;
        userListMessage["type"]="userlist";
        QJsonArray userlist;

        boradcastUserKickout(userUuid.toString());

#if 0
        for(auto key : m_userMap.keys())
        {
            //! 存在被踢用户
            if(key == userUuid.toString())
            {
                m_userMap.remove(key);
                userListMessage["userlist"]= QJsonObject::fromVariantMap(m_userMap);
                sender->sendJson(userListMessage);

                for(ServerWorker *worker:m_clients)
                {
                    if(key == worker->userId())
                    {
                        worker->setUserDisconnect();
//                        worker->m_serverSocket->disconnectFromHost();
                        m_clients.removeOne(worker);
                    }
                }

            }
        }
#endif


    }
}
void ChatServer::userDisconnected(ServerWorker *sender)
{
    m_clients.removeAll(sender);
    const QString userName = sender->userName();
    if(!userName.isEmpty()){
        QJsonObject disconnectedMessage;
        disconnectedMessage["type"]= "userdisconnected";
        disconnectedMessage["username"]=userName;
        broadcast(disconnectedMessage,nullptr);
        emit logMessage(userName +"disconnected" );}
    sender->deleteLater();
}
