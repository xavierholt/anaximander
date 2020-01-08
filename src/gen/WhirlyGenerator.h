#ifndef PLAT_WHIRLYGENERATOR_H
#define PLAT_WHIRLYGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class WhirlyGenerator: public FieldGenerator {
  public:
    static constexpr const char* TYPENAME = "field/whirly";
  protected:
    int mSize;
    int mCount;
  public:
    WhirlyGenerator(int size, int count);
    virtual const char* name() const;
    void next(Field& map);
  };
}

#endif
