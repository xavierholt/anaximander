#ifndef PLAT_WORLDVALUE_H
#define PLAT_WORLDVALUE_H

#include "Value.h"

namespace Plat
{
  class FieldValue;

  class WorldValue: public Value {
  public:
    static constexpr const char* TYPENAME = "world/world";
  protected:
    FieldParam* mElevation;
    FieldParam* mTemperature;
    FieldParam* mRainfall;
  public:
    WorldValue();

    virtual const char* name() const;
    virtual Value::Type type() const;

    FieldValue* elevation();
    FieldValue* temperature();
    FieldValue* rainfall();
  };
}

#endif
