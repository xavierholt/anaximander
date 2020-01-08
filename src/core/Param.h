#ifndef PLAT_PARAM_H
#define PLAT_PARAM_H

#include "Value.h"

namespace Plat
{
  class FieldValue;
  class FloatValue;
  class   IntValue;
  class WorldValue;

  class Param {
  protected:
    Value*      mParent;
    Value*      mValue;
    std::string mName;
    Value::Type mType;

  public:
    Param(Value* parent, const std::string& name, Value::Type type);

    const std::string& name() const;
    bool setValue(Value* value);
    Value::Type type() const;
    Value* value();

    // Sort-of Type Safety
    FieldValue* fieldValue();
    FloatValue* floatValue();
    IntValue*     intValue();

    // Editor Support
    bool        editable() const;
    Value::Type edittype() const;
    float       getFloat() const;
    int         getInt()   const;
    bool        update(float f);
    bool        update(int i);

    // Tree Structure
    Param* child(size_t index);
    int    index() const;
    int    nchildren() const;
    Param* parent();
  };

  template <class V, Value::Type VT> class TypedParam: public Param {
  public:
    TypedParam(Value* parent, const std::string& name): Param(parent, name, VT) {
      // That is all.
    }

    V* value() {
      return (V*) mValue;
    }

    bool setValue(V* value) {
      return Param::setValue(value);
    }
  };

  class FieldParam: public TypedParam<FieldValue, Value::Type::FIELD> {
  public:
    FieldParam(Value* parent, const std::string& name): TypedParam(parent, name) {}
  };

  class FloatParam: public TypedParam<FloatValue, Value::Type::FLOAT> {
  public:
    FloatParam(Value* parent, const std::string& name): TypedParam(parent, name) {}
  };

  class IntParam: public TypedParam<IntValue, Value::Type::INT> {
  public:
    IntParam(Value* parent, const std::string& name): TypedParam(parent, name) {}
  };

  class WorldParam: public TypedParam<WorldValue, Value::Type::WORLD> {
  public:
    WorldParam(Value* parent, const std::string& name): TypedParam(parent, name) {}
  };
}

#endif
