#ifndef PLAT_PERLINGENERATOR_H
#define PLAT_PERLINGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class PerlinGenerator: public FieldGenerator {
  public:
    static constexpr const char* TYPENAME = "field/perlin";
  protected:
    IntParam* mScale;
  public:
    PerlinGenerator(int scale = 5);
    virtual const char* name() const;
    void next(Field& map);
  };
}

#endif
