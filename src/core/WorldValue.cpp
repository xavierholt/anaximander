#include "WorldValue.h"

#include "Param.h"

namespace Plat
{
  WorldValue::WorldValue() {
    mElevation   = fieldParam("elevation");
    mTemperature = fieldParam("temperature");
    mRainfall    = fieldParam("rainfall");
  }

  FieldValue* WorldValue::elevation() {
    return mElevation->value();
  }

  const char* WorldValue::name() const {
    return WorldValue::TYPENAME;
  }

  FieldValue* WorldValue::rainfall() {
    return mRainfall->value();
  }

  FieldValue* WorldValue::temperature() {
    return mTemperature->value();
  }

  Value::Type WorldValue::type() const {
    return Value::Type::WORLD;
  }
}
