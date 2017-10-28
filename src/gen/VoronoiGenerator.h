#ifndef PLAT_VORONOIGENERATOR_H
#define PLAT_VORONOIGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class VoronoiGenerator: public FieldGenerator {
  protected:
    float mDensity;
  public:
    VoronoiGenerator(float density);
    void next(Field& map);
  };
}

#endif
