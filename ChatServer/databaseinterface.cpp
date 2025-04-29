#include "databaseinterface.h"
#include <QDate>
#include <QDebug>

#pragma execution_character_set("utf-8");
DataBaseInterface* DataBaseInterface::m_instance = nullptr;

DataBaseInterface *DataBaseInterface::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new DataBaseInterface();
    }
    return m_instance;
}

DataBaseInterface::~DataBaseInterface()
{
    release();
}

QSqlQuery DataBaseInterface::execSql(const QString &sql)
{
    QSqlQuery t_query;
    bool t_isQuery = false;
    SqlQueue queue;
    queue.sql = sql;
    queue.callback = [&](const bool &isQuery,const  QSqlQuery &query){
        t_isQuery = isQuery;
        t_query = query;
    };
    dealData(queue);
    return t_query;
}

bool DataBaseInterface::insertMessage(const MessageInfo & info)
{
    bool rslt = false;
    QString insertDataQuery = QString("INSERT INTO message (sender, message, customd) VALUES ('%1', '%2', '%3')")
            .arg(info.sender).arg(info.message).arg(info.date);
    QSqlQuery query;

    if (!query.exec(insertDataQuery)) {


        qDebug() << "Unable to insert data:" << query.lastError();

    } else {
        rslt = true;
        qDebug() << "Data inserted successfully";
    }
    return rslt;
}

void DataBaseInterface::createTable()
{
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS message ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "sender VARCHAR(40) NOT NULL, "
                               "message VARCHAR(1000) NOT NULL, "
                               "customd VARCHAR(40) NOT NULL)";


    QSqlQuery query;

    if (!query.exec(createTableQuery)) {
        qDebug() << "Unable to create table:" << query.lastError();
    } else {
        qDebug() << "Table created successfully";
    }

}

QList<MessageInfo> DataBaseInterface::getMessageInfo()
{
    QList<MessageInfo>list;

    QDate date = QDate::currentDate();

    QString datestr = date.toString("yyyy/MM/dd");
    return  list;
}

QList<MessageInfo> DataBaseInterface::selectFromSender(const QString & sender)
{
    QList<MessageInfo> msgList;
    QString strSql = QString("SELECT * FROM message WHERE sender = %1 ").arg(sender);
    QSqlQuery query = DataBaseInterface::getInstance()->execSql(strSql);
    while (query.next()) {

        MessageInfo info;
        info.sender = query.value(1).toString();
        info.message = query.value(2).toString();
        info.date = query.value(3).toString();

        msgList.append(info);
    }

    return msgList;
}

QList<MessageInfo> DataBaseInterface::selectFromDate(const QString & date)
{
    QList<MessageInfo> msgList;
    QString strSql = QString("SELECT * FROM message");
    QSqlQuery query = DataBaseInterface::getInstance()->execSql(strSql);
    while (query.next()) {

        MessageInfo info;
        info.sender = query.value(1).toString();
        info.message = query.value(2).toString();
        info.date = query.value(3).toString();
        if(info.date == date)
        {
            msgList.append(info);
        }
    }

    return msgList;
}

QList<MessageInfo> DataBaseInterface::selectFromKeycode(const QString & keycode)
{
    QList<MessageInfo> msgList;
    QString strSql = QString("SELECT * FROM message ");
    QSqlQuery query = DataBaseInterface::getInstance()->execSql(strSql);
    while (query.next()) {

        MessageInfo info;
        info.sender = query.value(1).toString();
        info.message = query.value(2).toString();
        info.date = query.value(3).toString();

        if(info.message.contains(keycode))
        {
            msgList.append(info);
        }
    }

    return msgList;
}



DataBaseInterface::DataBaseInterface(QObject *parent) : QObject(parent)
{

    init();
}

void DataBaseInterface::init()
{
    qRegisterMetaType<std::function<void()>>("std::function<void()>");
    initDatabase();
}

void DataBaseInterface::release()
{
    if(m_database)
    {
        m_database->close();
        delete m_database;
        m_database = nullptr;
    }
}

void DataBaseInterface::initDatabase()
{
    qDebug() << "SqlDatabase::drivers: " << QSqlDatabase::drivers();
    m_database = new QSqlDatabase();
    // 设置数据库类型
    *m_database = QSqlDatabase::addDatabase("QSQLITE");
    //    得到实例对象之后需要初始化连接信息
    m_database->setHostName("127.0.0.1");
    m_database->setPort(3306);
    m_database->setDatabaseName("MessageLog.db");
    //  连接数据库
    bool bl = m_database->open();
    if(!bl)
    {
        // 数据库连接失败
        qDebug() << m_database->lastError().text();
    }
}

void DataBaseInterface::dealData(const SqlQueue &queue)
{
    if(!queue.sql.isEmpty())
    {
        ///事务
        m_database->transaction();
        ///执行并回调
        QMutexLocker locker(&m_dbMutex);
        QSqlQuery query(*m_database);
        bool isExex = true;
        if (!query.exec(queue.sql)){
            reportSqlError(query);
            m_database->rollback();
            isExex = false;
        }
        queue.callback(isExex, query);
        m_database->commit();
    }
    else{
        qDebug()<<"DatabaseQueue::dealQueue error:"<<queue.sql;
    }
}

void DataBaseInterface::reportSqlError(QSqlQuery &query)
{
    qDebug()<<"ERROR:"<< query.lastError().text()<<" DataBase: sql:"<<query.lastQuery();
}
