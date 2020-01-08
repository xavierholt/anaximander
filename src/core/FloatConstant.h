#ifndef PLAT_FLOATCONSTANT_H
#define PLAT_FLOATCONSTANT_H

#include "FloatValue.h"

namespace Plat
{
  class FloatConstant: public FloatValue {
    float mValue;
  public:
    static constexpr const char* TYPENAME = "float/constant";
  public:
    FloatConstant(float v = 0): mValue(v) {
      // That is all.
    }

    virtual bool constant() const {
      return true;
    }

    virtual Value::Type edittype() const {
      return Value::Type::FLOAT;
    }

    virtual float get() {
      return mValue;
    }

    virtual float getFloat() const {
      return mValue;
    }

    virtual const char* name() const {
      return TYPENAME;
    }

    virtual bool setFloat(float f) {
      mValue = f;
      return true;
    }
  };
}

#endif
