#ifndef PLAT_STAROFDAVIDGENERATOR_H
#define PLAT_STAROFDAVIDGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class StarOfDavidGenerator: public FieldGenerator {
  public:
    static constexpr const char* TYPENAME = "field/star-of-david";
  protected:
    float mNoise;
    float mFalloff;
  public:
    StarOfDavidGenerator(float noise, float falloff);
    virtual const char* name() const;
    void next(Field& map);
  };
}

#endif
