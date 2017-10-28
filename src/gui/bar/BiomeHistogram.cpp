#include "BiomeHistogram.h"

#include "../../Biome.h"

#include <QPainter>

namespace Plat
{
  void BiomeHistogram::calculate(const Map& map) {
    mHistogram.clear();
    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        mHistogram.add(map.get(x, y).biome);
      }
    }
  }

  void BiomeHistogram::paint(QPainter& painter) {
    qreal w = width() / qreal(8);
    for(int i = 0; i < 8; ++i) {
      qreal h = qreal(mHistogram[i]) / mHistogram.maxbar() * height();
      painter.fillRect(w * i, height() - h, w * (i + 1), height(), Biome::COLORS[i]);
      painter.fillRect(w * i, 0, w * (i + 1), height() - h, Qt::black);
    }
  }
}
