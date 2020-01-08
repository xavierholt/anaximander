#ifndef PLAT_INTVALUE_H
#define PLAT_INTVALUE_H

#include "Value.h"

namespace Plat
{
  class IntValue: public Value {
  public:
    static IntValue* byName(const std::string& name);
  public:
    virtual int get() = 0;
    virtual Value::Type type() const;
  };
}

#endif
