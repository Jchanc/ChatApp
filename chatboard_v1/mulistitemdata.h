#ifndef MULISTITEMDATA_H
#define MULISTITEMDATA_H

#include <QMetaType>

/*
 * 参考 https://blog.csdn.net/a844651990/article/details/84324560
*/

typedef struct {
    QString iconPath;
    QString usrName;
    QString desc;
} MuItemData;

Q_DECLARE_METATYPE(MuItemData)

#endif // MULISTITEMDATA_H
