#include "ElevationViewer.h"

#include "../../Map.h"

namespace Plat
{
  void ElevationViewer::xxx(const Map& map, QImage& image) {
    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        const Tile& tile = map.get(x, y);
        unsigned char v = tile.elevation;

        // if(tile.elevation < 128) {
        //   image.setPixelColor(x, y, QColor(v/2, v/2, 128));
        // }
        // else {
          image.setPixelColor(x, y, QColor(v, v, v));
        // }
      }
    }
  }
}
