#ifndef PLAT_PERLINGENERATOR_H
#define PLAT_PERLINGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class PerlinGenerator: public FieldGenerator {
  protected:
    int mSize;
  public:
    PerlinGenerator(int size = 5);
    void next(Field& map);
  };
}

#endif
