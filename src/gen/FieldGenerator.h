#ifndef PLAT_FIELDGENERATOR_H
#define PLAT_FIELDGENERATOR_H

#include <random>

#include "../Field.h"

namespace Plat
{
  class FieldGenerator {
  protected:
    static std::default_random_engine cGenerator;
  protected:
    std::default_random_engine mGenerator;
    unsigned int mSeed;
  public:
    FieldGenerator();
    FieldGenerator(unsigned int seed);
    virtual void next(Field& map) = 0;

    float smoothstep(float a, float b, float p) {
      p = (p * p) * (3 - 2 * p);
      return (1-p) * a + p * b;
    }

    float smootherstep(float a, float b, float p) {
      p = (p * p * p) * (p * (p * 6 - 15) + 10);
      return (1-p) * a + p * b;
    }
  };
}

#endif
