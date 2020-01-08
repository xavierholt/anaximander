#ifndef PLAT_DIAMONDSQUAREGENERATOR_H
#define PLAT_DIAMONDSQUAREGENERATOR_H

#include "FieldGenerator.h"

#include  "../core/Param.h"

#include "XorShiftGenerator.h"

namespace Plat
{
  class DiamondSquareGenerator: public FieldGenerator {
  public:
    static constexpr const char* TYPENAME = "field/diamond-square";
  protected:
    IntParam*   mScale;
    FieldParam* mVariance;
    FloatParam* mFalloff;

    XorShiftGenerator random;
  public:
    DiamondSquareGenerator(int size = 6, float noise = 0.5);
    virtual const char* name() const;
    void next(Field& map);
  };
}

#endif
