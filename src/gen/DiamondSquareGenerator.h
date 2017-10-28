#ifndef PLAT_DIAMONDSQUAREGENERATOR_H
#define PLAT_DIAMONDSQUAREGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class DiamondSquareGenerator: public FieldGenerator {
  protected:
    int   mSize;
    float mNoise;
  public:
    DiamondSquareGenerator(int size, float noise);
    void next(Field& map);
  };
}

#endif
