#ifndef PLAT_FIELDGENERATOR_H
#define PLAT_FIELDGENERATOR_H

#include <random>

#include "../map.h"

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
  };
}

#endif
