#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <functional>
#include <QSqlDatabase>
#include <QMutex>
#include <QSemaphore>

#include "PublicDefines.h"
using namespace  std;


typedef struct SqlQueue{
    QString sql{""};
    std::function<void (const bool &isQuery,const  QSqlQuery &query)> callback{[&](const bool &isQuery,const  QSqlQuery &query){}};
}SqlQueue;

class DataBaseInterface : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief getInstance 获取单例
     * @return
     */
    static DataBaseInterface *getInstance();

    ~DataBaseInterface();

    /**
     * @brief execSql 添加查询sql语句
     * @param sql
     * @return
     */
    QSqlQuery execSql(const QString &sql);


    void createTable();


    QList<UserInfo> getUserInfo();





private:
    explicit DataBaseInterface(QObject *parent = nullptr);

    /**
     * @brief init
     */
    void init();

    /**
     * @brief release
     */
    void release();

    /**
     * @brief initDatabase 初始化数据库
     */
    void initDatabase();

    /**
     * @brief dealData 处理数据
     * @param queue
     */
    void dealData(const SqlQueue &queue);

    /**
     * @brief reportSqlError 返回错误
     * @param query
     */
    void reportSqlError(QSqlQuery &query);



private:

    static DataBaseInterface            *m_instance;

    /**
     * @brief m_database 数据库对象
     */
    QSqlDatabase                        *m_database;

    QSqlQuery                           m_sqlQuery;
    QMutex                              m_dbMutex;
};

#endif // DATABASEINTERFACE_H
