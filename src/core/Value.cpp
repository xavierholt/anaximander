#include "Value.h"

#include <stdexcept>

#include "FieldValue.h"
#include "FloatValue.h"
#include "IntValue.h"
#include "Param.h"

namespace Plat
{
  Value::Value(): mParams() {
    mParent = nullptr;
    mConsumers = 0;
  }

  Value::~Value() {
    // TODO?
  }

  bool Value::constant() const {
    return false;
  }

  bool Value::editable() const {
    return edittype() != Type::NONE;
  }

  Value::Type Value::edittype() const {
    return Type::NONE;
  }

  FieldParam* Value::fieldParam(const std::string& name) {
    FieldParam* param = new FieldParam(this, name);
    mParams.push_back(param);
    return param;
  }

  FloatParam* Value::floatParam(const std::string& name) {
    FloatParam* param = new FloatParam(this, name);
    mParams.push_back(param);
    return param;
  }

  // void Value::floatParam(const std::string& name, float min, float def, float max, float inc) {
  //   mParams.push_back(new FloatParam(name, new Bounds(min, def, max, inc)));
  // }

  Value* Value::byName(const std::string& name) {
    // Prefix check: https://stackoverflow.com/a/40441240
    if(name.rfind("field/", 0) == 0)
      return FieldValue::byName(name);
    if(name.rfind("float/", 0) == 0)
      return FloatValue::byName(name);
    if(name.rfind("int/", 0) == 0)
      return IntValue::byName(name);
    throw "What?";
  }

  void Value::generate(int xbits, int ybits) {
    for(auto& param: mParams) {
      param->value()->generate(xbits, ybits);
    }
  }

  float Value::getFloat() const {
    throw std::invalid_argument("Not a float.");
  }

  int Value::getInt() const {
    throw std::invalid_argument("Not an int.");
  }

  IntParam* Value::intParam(const std::string& name) {
    IntParam* param = new IntParam(this, name);
    mParams.push_back(param);
    return param;
  }

  bool Value::prepare() {
    mConsumers += 1;
    if(mConsumers == 1) {
      for(auto& param: mParams) {
        // TODO: Check for null pointers!
        param->value()->prepare();
      }

      return true;
    }

    return false;
  }

  bool Value::setFloat(float) {
    return false;
  }

  bool Value::setInt(int) {
    return false;
  }

  bool Value::release() {
    mConsumers -= 1;
    if(mConsumers == 0) {
      for(auto& param: mParams) {
        param->value()->release();
      }

      return true;
    }

    return false;
  }
}
