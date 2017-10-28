#include "BiomeViewer.h"

#include "../../map.h"
#include "../../Biome.h"


namespace Plat
{
  void BiomeViewer::xxx(const Map& map, QImage& image) {
    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        const Tile& tile = map.get(x, y);

        if(tile.elevation < 128) {
          image.setPixelColor(x, y, QColor(0, 0, 64));
        }
        else {
          image.setPixelColor(x, y, Biome::COLORS[tile.biome]);
        }
      }
    }
  }
}
