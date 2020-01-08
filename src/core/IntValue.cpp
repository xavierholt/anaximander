#include "IntValue.h"

#include "IntConstant.h"

namespace Plat
{
  IntValue* IntValue::byName(const std::string& name) {
    if(name == IntConstant::TYPENAME)
      return new IntConstant();
    throw "What?";
  }

  Value::Type IntValue::type() const {
    return Value::Type::INT;
  }
}
