#ifndef PLAT_FIELDCONSTANT_H
#define PLAT_FIELDCONSTANT_H

#include "FieldValue.h"

namespace Plat
{
  class FieldConstant: public FieldValue {
    float mValue;
  public:
    static constexpr const char* TYPENAME = "field/constant";
  public:
    FieldConstant(float v = 0): mValue(v) {
      // That is all.
    }

    virtual bool constant() const {
      return true;
    }

    virtual Value::Type edittype() const {
      return Value::Type::FLOAT;
    }

    virtual float get(int, int) const {
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
