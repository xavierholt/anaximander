#ifndef PLAT_STAROFDAVIDGENERATOR_H
#define PLAT_STAROFDAVIDGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class StarOfDavidGenerator: public FieldGenerator {
  protected:
    float mNoise;
    float mFalloff;
  public:
    StarOfDavidGenerator(float noise, float falloff);
    void next(Field& map);
  };
}

#endif
