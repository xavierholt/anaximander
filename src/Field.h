#ifndef PLAT_FIELD_H
#define PLAT_FIELD_H

#include "Grid.h"

namespace Plat
{
  class Field: public Grid<float> {
  public:
    Field(int xbits, int ybits): Grid<float>(xbits, ybits) {
      // That is all.
    }
  };
}

#endif
