#ifndef PLAT_VORONOIGENERATOR_H
#define PLAT_VORONOIGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class VoronoiGenerator: public FieldGenerator {
  public:
    static constexpr const char* TYPENAME = "field/voronoi";
  protected:
    FloatParam* mDensity;
  public:
    VoronoiGenerator(float density = 0.001);
    virtual const char* name() const;
    void next(Field& map);
  };
}

#endif
