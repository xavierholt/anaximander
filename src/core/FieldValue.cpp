#include "FieldValue.h"

#include "FieldConstant.h"

#include "../gen/DiamondSquareGenerator.h"
#include "../gen/MarbleGenerator.h"
#include "../gen/PerlinGenerator.h"
#include "../gen/VoronoiGenerator.h"
#include "../gen/WorleyGenerator.h"

#include "fields/FieldSum.h"
#include "fields/FieldProduct.h"

namespace Plat
{
  FieldValue* FieldValue::byName(const std::string& name) {
    if(name == FieldConstant::TYPENAME)
      return new FieldConstant();

    if(name == MarbleGenerator::TYPENAME)
      return new MarbleGenerator();
    if(name == PerlinGenerator::TYPENAME)
      return new PerlinGenerator();
    if(name == DiamondSquareGenerator::TYPENAME)
      return new DiamondSquareGenerator();
    if(name == VoronoiGenerator::TYPENAME)
      return new VoronoiGenerator();
    if(name == WorleyGenerator::TYPENAME)
      return new WorleyGenerator();

    if(name == FieldSum::TYPENAME)
      return new FieldSum();
    if(name == FieldProduct::TYPENAME)
      return new FieldProduct();

    throw "What?";
  }

  FieldValue::FieldValue() {
    mField = nullptr;
  }

  float FieldValue::get(int x, int y) const {
    return mField->get(x, y);
  }

  bool FieldValue::release() {
    if(Value::release()) {
      delete mField;
      mField = nullptr;
      return true;
    }

    return false;
  }

  Field* FieldValue::take() {
    if(mConsumers > 1)
      return nullptr;
    Field* field = mField;
    mField = nullptr;
    return field;
  }

  Value::Type FieldValue::type() const {
    return Value::Type::FIELD;
  }
}
