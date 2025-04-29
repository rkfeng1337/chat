#pragma once

#include <QtGlobal>
#include <QString>
#include <QVector>
#include <QByteArray>
#include <qmetatype.h>
#include <QColor>
#include <QMap>

typedef struct _OrderMenu
{
    quint16 menuId;         //! 菜单号
    quint16 dishId;         //! 菜品ID
}OrderMenu;

typedef struct _OrderInfo
{
    quint16 tableID;         //! 桌号
    quint16 menuId;         //! 菜单号
}OrderInfo;

typedef struct  _CustomMenu
{
    quint16 index;
    QString name;
    QString engname;
    qreal price;

}CustomMenu;

typedef  struct _UserInfo
{
    QString username;
    QString pwd;
    quint8 type;    //! 0：是普通用户 1：管理员
}UserInfo;


