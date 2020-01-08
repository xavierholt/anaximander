#ifndef PLAT_TILE_H
#define PLAT_TILE_H

#include <QDataStream>

namespace Plat
{
  struct Tile {
    unsigned char elevation;
    unsigned char waterlevel;
    unsigned char temperature;
    unsigned char rainfall;
    unsigned char biome;

    friend QDataStream& operator << (QDataStream& stream, const Tile& tile) {
      return stream << tile.elevation << tile.waterlevel << tile.temperature << tile.rainfall << tile.biome;
    }

    friend QDataStream& operator >> (QDataStream& stream, Tile& tile) {
      return stream >> tile.elevation >> tile.waterlevel >> tile.temperature >> tile.rainfall >> tile.biome;
    }
  };
}

#endif
