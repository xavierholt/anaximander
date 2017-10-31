#ifndef PLAT_WORLEYGENERATOR_H
#define PLAT_WORLEYGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class WorleyGenerator: public FieldGenerator {
  protected:
    int mSize;
    int mCount;
  public:
    WorleyGenerator(int size, int count);
    void next(Field& map);
  };
}

#endif
