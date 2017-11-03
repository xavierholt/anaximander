#ifndef PLAT_MAP_H
#define PLAT_MAP_H

#include "Grid.h"
#include "Tile.h"

namespace Plat
{
  class Map: public Grid<Tile> {
  public:
    Map(int xbits, int ybits): Grid<Tile>(xbits, ybits) {
      // That is all.
    }
  };
}

#endif
