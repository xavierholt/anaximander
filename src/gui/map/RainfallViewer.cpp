#include "RainfallViewer.h"

#include "../../Map.h"

namespace Plat
{
  void RainfallViewer::xxx(const Map& map, QImage& image) {
    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        const Tile& tile = map.get(x, y);
        unsigned char v = tile.rainfall;

        if(tile.elevation < 128) {
          image.setPixelColor(x, y, QColor(0, 0, v/2));
        }
        else {
          image.setPixelColor(x, y, QColor(128, 128, v));
        }
      }
    }
  }
}
