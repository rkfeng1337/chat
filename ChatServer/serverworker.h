#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>
#include <QTcpSocket>
class ServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ServerWorker(QObject *parent = nullptr);
    virtual bool setSocketDesctiptor(qintptr socketDescrtptor);

    QString userName();
    void setUserName(QString user);

    QString userId();
    QTcpSocket *m_serverSocket;
    void setUserId(const QString &userid);


    void setUserDisconnect();
signals:
    void logMessage(const QString &msg);
    void jsonReceived(ServerWorker *sender,const QJsonObject &docObj);
    void disconnectedFromclient();
private:
    QString m_userName;
    QString m_userId;

public slots:
    void sendMessage(const QString &text,const QString &type = "message");
    void onReadyRead()  ;
    void sendJson(const QJsonObject &json);

};

#endif // SERVERWORKER_H
