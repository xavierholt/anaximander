#include "FloatValue.h"

#include "FloatConstant.h"

namespace Plat
{
  FloatValue* FloatValue::byName(const std::string& name) {
    if(name == FloatConstant::TYPENAME)
      return new FloatConstant();
    throw "What?";
  }

  Value::Type FloatValue::type() const {
    return Value::Type::FLOAT;
  }
}
