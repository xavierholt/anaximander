#ifndef PLAT_BIOME_H
#define PLAT_BIOME_H

class QColor;

namespace Plat
{
  class Biome {
  public:
    enum Type {
      TUNDRA,
      BOREAL_FOREST,
      TEMPERATE_GRASSLAND,
      TEMPERATE_FOREST,
      TEMPERATE_RAINFOREST,
      TROPICAL_GRASSLAND,
      TROPICAL_RAINFOREST,
      DESERT
    };
  public:
    static QColor COLORS[8];
  };
}

#endif
