#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chatclient.h>
#include <QListWidgetItem>
#include <QMap>
#include "databaseinterface.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sayButton_clicked();

    void on_loginoutButton_clicked();

    void on_loginButton_clicked();

    void connectedToServer();

    void messageReceived(const QString &sender,const QString &text, const bool &bpublic);
    void messageReceived(const QString &sender,const QString &text);
    void jsonReceived(const QJsonObject &docObj);
    void userJoined(const QString &user);
    void userLeft(const QString &user);
    void userListReceived(const QStringList &list);

    void on_userListWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_privatereturn_clicked();

    void on_pushButton_privatesend_clicked();

    void on_pushButton_kickout_clicked();

    void on_pushButton_loginin_clicked();

    
    void on_userListWidget_itemClicked(QListWidgetItem *item);

private:
    void initSql();

    void initUi();
    void  userListReceivedWithId(const QMap<QString, QVariant> &);


private:
    Ui::MainWindow *ui;

    QList<UserInfo> m_userInfoList;

    QString m_uuid;

    QString m_kickOutUuid = QString();

    QString m_privateChatUuid;

    ChatClient *m_chatClient;
};
#endif // MAINWINDOW_H
