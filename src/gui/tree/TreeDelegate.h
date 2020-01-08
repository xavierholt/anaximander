#ifndef PLAT_TREEDELEGATE_H
#define PLAT_TREEDELEGATE_H

#include <QStyledItemDelegate>

class QModelIndex;
class QStyleOptionViewItem;
class QWidget;

namespace Plat
{
  class TreeDelegate: public QStyledItemDelegate {
    Q_OBJECT
  public:
    TreeDelegate(QObject* parent = 0);

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void setEditorData(QWidget* editor, const QModelIndex& index) const;
    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
  };
}

#endif
