#ifndef PLAT_FLOATVALUE_H
#define PLAT_FLOATVALUE_H

#include "Value.h"

namespace Plat
{
  class FloatValue: public Value {
  public:
    static FloatValue* byName(const std::string& name);
  public:
    virtual float get() = 0;
    virtual Value::Type type() const;
  };
}

#endif
