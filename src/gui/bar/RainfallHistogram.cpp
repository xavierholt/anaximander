#include "RainfallHistogram.h"

#include <QPainter>
#include <iostream>

namespace Plat
{
  void RainfallHistogram::calculate(const Map& map) {
    mHistogram.clear();
    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        mHistogram.add(map.get(x, y).rainfall);
      }
    }
  }

  void RainfallHistogram::paint(QPainter& painter) {
    qreal w = width() / qreal(256);
    for(int i = 0; i < 256; ++i) {
      qreal h = qreal(mHistogram[i]) / mHistogram.maxbar() * height();
      // std::cout << i << " -> " << h << '\n';
      painter.fillRect(w * i, height() - h, w * (i + 1), height(), QColor(128, 128, i));
      painter.fillRect(w * i, 0, w * (i + 1), height() - h, Qt::black);
    }
  }
}
