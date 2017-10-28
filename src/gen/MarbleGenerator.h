#ifndef PLAT_MARBLEGENERATOR_H
#define PLAT_MARBLEGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class MarbleGenerator: public FieldGenerator {
  protected:
    float mXPeriod;
    float mYPeriod;
    float mTurbulence;
  public:
    MarbleGenerator(int xp, int yp, float turbulence);
    void next(Field& map);
  };
}

#endif
