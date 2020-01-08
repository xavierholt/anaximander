#include "Param.h"

#include "FieldValue.h"
#include "FloatValue.h"
#include "IntValue.h"

#include <QtCore>

namespace Plat
{
  Param::Param(Value* parent, const std::string& name, Value::Type type): mParent(parent), mName(name) {
    mValue = nullptr;
    mType  = type;
  }

  Param* Param::child(size_t index) {
    if(mValue && index < mValue->mParams.size())
      return mValue->mParams[index];
    return nullptr;
  }

  bool Param::editable() const {
    return mValue && mValue->editable();
  }

  Value::Type Param::edittype() const {
    if(!mValue) return Value::Type::NONE;
    return mValue->edittype();
  }

  // FieldValue* Param::fieldValue() {
  //   if(mValue && mValue->type() & Value::Type::FIELD)
  //     return (FieldValue*) mValue;
  //   return nullptr;
  // }

  // FloatValue* Param::floatValue() {
  //   if(mValue && mValue->type() & Value::Type::FLOAT)
  //     return (FloatValue*) mValue;
  //   return nullptr;
  // }

  float Param::getFloat() const {
    // if(!mValue) throw Something;
    return mValue->getFloat();
  }

  int Param::getInt() const {
    // if(!mValue) throw Something;
    return mValue->getInt();
  }

  int Param::index() const {
    if(!mParent) return 0;
    const auto& siblings = mParent->mParams;
    for(size_t i = 0; i < siblings.size(); ++i) {
      if(siblings[i] == this) return i;
    }

    return 0;
  }

  // IntValue* Param::intValue() {
  //   if(mValue && mValue->type() & Value::Type::INT)
  //     return (IntValue*) mValue;
  //   return nullptr;
  // }

  const std::string& Param::name() const {
    return mName;
  }

  int Param::nchildren() const {
    if(!mValue) return 0;
    if(mValue->editable()) return 0;
    return mValue->mParams.size();
  }

  Param* Param::parent() {
    if(!mParent) return nullptr;
    return mParent->mParent;
  }

  bool Param::setValue(Value* value) {
    if(value) {
      if((value->type() & mType) == 0)
        return false;
      value->mParent = this;
      // value->reference();
    }

    // if(mValue) mValue->dereference();
    mValue = value;
    return true;
  }

  Value::Type Param::type() const {
    return mType;
  }

  bool Param::update(float f) {
    qDebug("Param::update(float)");
    if(!mValue) return false;
    return mValue->setFloat(f);
  }

  bool Param::update(int i) {
    if(!mValue) return false;
    return mValue->setInt(i);
  }

  Value* Param::value() {
    return mValue;
  }
}
