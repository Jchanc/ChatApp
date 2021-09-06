#ifndef MUITEMDELEGATE_H
#define MUITEMDELEGATE_H

#include <QStyledItemDelegate>

/*
 * 参考 https://blog.csdn.net/a844651990/article/details/84324560
*/

class MuItemDelegate : public QStyledItemDelegate
{
public:
    MuItemDelegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // MUITEMDELEGATE_H
