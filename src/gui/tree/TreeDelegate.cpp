#include "TreeDelegate.h"

#include "../../core/Param.h"
#include "../../core/Value.h"

#include <QComboBox>
#include <QDoubleSpinBox>
#include <QModelIndex>
#include <QSpinBox>

static Plat::Param* param(const QModelIndex& index) {
  return static_cast<Plat::Param*>(index.internalPointer());
}

namespace Plat
{
  TreeDelegate::TreeDelegate(QObject* parent): QStyledItemDelegate(parent) {
    // That is all.
  }

  QWidget* TreeDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem&, const QModelIndex& index) const {
    if(index.column() == 1) {
      QComboBox* editor = new QComboBox(parent);
      if(param(index)->type() == Value::Type::FIELD) {
        editor->addItem("Constant",  "field/constant");
        editor->insertSeparator(1);
        editor->addItem("Marble",    "field/marble");
        editor->addItem("Perlin",    "field/perlin");
        editor->addItem("Recursive", "field/diamond-square");
        editor->addItem("Voronoi",   "field/voronoi");
        editor->addItem("Worley",    "field/worley");
        editor->insertSeparator(7);
        editor->addItem("Sum",       "field/sum");
        editor->addItem("Product",   "field/product");
      }
      else if(param(index)->type() == Value::Type::FLOAT) {
        editor->addItem("Constant", "float/constant");
        // editor->addItem("float/uniform");
      }
      else if(param(index)->type() == Value::Type::INT) {
        editor->addItem("Constant", "int/constant");
      }
      editor->setFrame(false);
      return editor;
    }
    if(index.column() == 2 && param(index)->edittype() == Value::Type::FLOAT) {
      QDoubleSpinBox* editor = new QDoubleSpinBox(parent);
      editor->setMinimum(-10);
      // TODO: Set bounds
      return editor;
    }
    if(index.column() == 2 && param(index)->edittype() == Value::Type::INT) {
      QSpinBox* editor = new QSpinBox(parent);
      // TODO: set bounds
      return editor;
    }

    return nullptr;
  }

  void TreeDelegate::setEditorData(QWidget* widget, const QModelIndex& index) const {
    if(index.column() == 1) {
      QString value = index.model()->data(index, Qt::EditRole).toString();
      QComboBox* editor = static_cast<QComboBox*>(widget);
      editor->setCurrentText(value);
    }
    else if(index.column() == 2 && param(index)->edittype() == Value::Type::FLOAT) {
      float value = index.model()->data(index, Qt::EditRole).toFloat();
      QDoubleSpinBox* editor = static_cast<QDoubleSpinBox*>(widget);
      editor->setValue(value);
    }
    else if(index.column() == 2 && param(index)->edittype() == Value::Type::INT) {
      int value = index.model()->data(index, Qt::EditRole).toInt();
      QSpinBox* editor = static_cast<QSpinBox*>(widget);
      editor->setValue(value);
    }
  }

  void TreeDelegate::setModelData(QWidget* widget, QAbstractItemModel* model, const QModelIndex& index) const {
    if(index.column() == 1) {
      QComboBox* editor = static_cast<QComboBox*>(widget);
      model->setData(index, editor->currentData(), Qt::EditRole);
    }
    else if(index.column() == 2 && param(index)->edittype() == Value::Type::FLOAT) {
      QDoubleSpinBox* editor = static_cast<QDoubleSpinBox*>(widget);
      editor->interpretText();

      float value = editor->value();
      model->setData(index, value, Qt::EditRole);
    }
    else if(index.column() == 2 && param(index)->edittype() == Value::Type::INT) {
      QSpinBox* editor = static_cast<QSpinBox*>(widget);
      editor->interpretText();

      int value = editor->value();
      model->setData(index, value, Qt::EditRole);
    }
  }

  void TreeDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex&) const {
    editor->setGeometry(option.rect);
  }
}
