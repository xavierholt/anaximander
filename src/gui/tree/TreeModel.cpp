#include "TreeModel.h"

#include "../../core/Param.h"

namespace Plat
{
  TreeModel::TreeModel(Param* root, QObject* parent): QAbstractItemModel(parent) {
    mRoot = root;
  }

  TreeModel::~TreeModel() {
    // Nothing to do?
  }

  int TreeModel::columnCount(const QModelIndex&) const {
    return 3;
  }

  QVariant TreeModel::data(const QModelIndex& index, int role) const {
    if(role == Qt::DisplayRole || role == Qt::EditRole) {
      Param* param = getItem(index);
      if(!param) return QVariant();

      if(index.column() == 0)
        return QVariant(param->name().c_str());
      if(index.column() == 1) {
        if(param->value() == nullptr)
          return QVariant("none");
        else
          return QVariant(param->value()->name());
      }

      if(index.column() == 2) {
        if(param->edittype() == Value::Type::FLOAT)
          return QVariant(param->getFloat());
        if(param->edittype() == Value::Type::INT)
          return QVariant(param->getInt());
      }
    }

    return QVariant();
  }

  QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole) {
      if(section == 0)
        return QVariant("Field");
      if(section == 1)
        return QVariant("Type");
      if(section == 2)
        return QVariant("Value");
    }

    return QVariant();
  }

  Qt::ItemFlags TreeModel::flags(const QModelIndex& index) const {
    if(!index.isValid()) return Qt::NoItemFlags;
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);

    if(index.column() == 1)
      return flags | Qt::ItemIsEditable;
    if(index.column() == 2 && getItem(index)->editable())
      return flags | Qt::ItemIsEditable;
    return flags;
  }

  Param* TreeModel::getItem(const QModelIndex& index) const {
    if(index.isValid()) {
      Param* param = static_cast<Param*>(index.internalPointer());
      if(param) return param;
    }

    return mRoot;
  }

  // What is this doing!?
  QModelIndex TreeModel::index(int row, int column, const QModelIndex& parent) const {
    if(parent.isValid() && parent.column() != 0) return QModelIndex();

    Param* child = getItem(parent)->child(row);
    if(child) return createIndex(row, column, child);
    return QModelIndex();
  }

  // What is this doing!?
  QModelIndex TreeModel::parent(const QModelIndex& index) const {
    if(!index.isValid()) return QModelIndex();

    Param* parent = getItem(index)->parent();
    if(parent == mRoot || !parent) return QModelIndex();
    return createIndex(parent->index(), 0, parent);
  }

  int TreeModel::rowCount(const QModelIndex& parent) const {
    return getItem(parent)->nchildren();
  }

  bool TreeModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    Param* param = getItem(index);
    if(!param) return false;

    if(index.column() == 1) {
      std::string name = value.toString().toStdString();
      // qDebug("Got a name: %s", name.c_str());
      Value* value = Value::byName(name);

      if(value) {
        QModelIndex parent = createIndex(param->index(), 0, param);

        int n = param->nchildren();
        // qDebug("Removing %d columns...", n);
        if(n) beginRemoveRows(index, 0, n - 1);
        param->setValue(nullptr);
        if(n) endRemoveRows();

        bool result = param->setValue(value);
        n = param->nchildren();
        // qDebug("Inserting %d columns...", n);
        if(n) beginInsertRows(index, 0, n - 1);
        if(n) endInsertRows();
        return result;
      }
    }

    if(index.column() == 2) {
      // qDebug("Set data: %s", value.typeName());
      if(value.type() == QMetaType::Float)
        return param->update(value.toFloat());
      if(value.type() == QMetaType::Int)
        return param->update(value.toInt());
    }

    return false;
  }

  // bool TreeModel::insertRows(int position, int rows, const QModelIndex& parent) {

  // }

  // bool TreeModel::removeRows(int position, int rows, const QModelIndex& parent) {

  // }
}
