#ifndef PLAT_INTCONSTANT_H
#define PLAT_INTCONSTANT_H

#include "IntValue.h"

namespace Plat
{
  class IntConstant: public IntValue {
    int mValue;
  public:
    static constexpr const char* TYPENAME = "int/constant";
  public:
    IntConstant(int v = 0): mValue(v) {
      // That is all.
    }

    virtual bool constant() const {
      return true;
    }

    virtual Value::Type edittype() const {
      return Value::Type::INT;
    }

    virtual int get() {
      return mValue;
    }

    virtual int getInt() const {
      return mValue;
    }

    virtual const char* name() const {
      return TYPENAME;
    }

    virtual bool setInt(int i) {
      mValue = i;
      return true;
    }
  };
}

#endif
