#include "TemperatureViewer.h"

#include "../../map.h"

namespace Plat
{
  void TemperatureViewer::xxx(const Map& map, QImage& image) {
    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        const Tile& tile = map.get(x, y);
        unsigned char v = tile.temperature;

        if(tile.elevation < 128) {
          image.setPixelColor(x, y, QColor(v/2, 0, 128-v/2));
        }
        else {
          image.setPixelColor(x, y, QColor(v, 128, 255-v));
        }
      }
    }
  }
}
