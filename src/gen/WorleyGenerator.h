#ifndef PLAT_WORLEYGENERATOR_H
#define PLAT_WORLEYGENERATOR_H

#include "FieldGenerator.h"

namespace Plat
{
  class WorleyGenerator: public FieldGenerator {
  public:
    static constexpr const char* TYPENAME = "field/worley";
  protected:
    IntParam* mScale;
    IntParam* mCount;
  public:
    WorleyGenerator(int scale = 5, int count = 5);
    virtual const char* name() const;
    void next(Field& map);
  };
}

#endif
