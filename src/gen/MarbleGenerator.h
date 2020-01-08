#ifndef PLAT_MARBLEGENERATOR_H
#define PLAT_MARBLEGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class MarbleGenerator: public FieldGenerator {
  public:
    static constexpr const char* TYPENAME = "field/marble";
  protected:
    IntParam*   mScale;
    IntParam*   mXPeriod;
    IntParam*   mYPeriod;
    FieldParam* mNoise;
    FloatParam* mTurbulence;
    // float mXPeriod;
    // float mYPeriod;
    // float mTurbulence;
  public:
    MarbleGenerator(int xp = 4, int yp = 5, float turbulence = 0.3);
    virtual const char* name() const;
    void next(Field& map);
  };
}

#endif
