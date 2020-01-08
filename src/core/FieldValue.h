#ifndef PLAT_FIELDVALUE_H
#define PLAT_FIELDVALUE_H

#include "Value.h"

namespace Plat
{
  class Field;

  class FieldValue: public Value {
  public:
    static FieldValue* byName(const std::string& name);
  protected:
    Field* mField;
  public:
    FieldValue();

    virtual float get(int x, int y) const;
    virtual bool release();
    virtual Field* take();

    virtual Value::Type type() const;
  };
}

#endif
