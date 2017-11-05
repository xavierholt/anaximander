#ifndef PLAT_WHIRLYGENERATOR_H
#define PLAT_WHIRLYGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class WhirlyGenerator: public FieldGenerator {
  protected:
    int mSize;
    int mCount;
  public:
    WhirlyGenerator(int size, int count);
    void next(Field& map);
  };
}

#endif
