#ifndef CHATSERVER_H
#define CHATSERVER_H
#include <serverworker.h>
#include <QObject>
#include <QTcpServer>

class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor);
    QVector<ServerWorker *>m_clients;

    void broadcast(const QJsonObject &message,ServerWorker *exelude);

    void boradcastUserKickout(const QString & userid);


    void saveMessage(const QString &sender, const QString &message);


public slots:
    void stopServer();
    void jsonReceived(ServerWorker *sender,const QJsonObject &docObj);
    void userDisconnected(ServerWorker *sender);
signals:
    void logMessage(const QString& msg);

private:
    QMap<QString, QVariant> m_userMap;

};

#endif // CHATSERVER_H
