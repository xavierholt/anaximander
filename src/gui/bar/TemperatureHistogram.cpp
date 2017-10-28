#include "TemperatureHistogram.h"

#include <QPainter>

namespace Plat
{
  void TemperatureHistogram::calculate(const Map& map) {
    mHistogram.clear();
    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        mHistogram.add(map.get(x, y).temperature);
      }
    }
  }

  void TemperatureHistogram::paint(QPainter& painter) {
    qreal w = width() / qreal(256);
    for(int i = 0; i < 256; ++i) {
      qreal h = qreal(mHistogram[i]) / mHistogram.maxbar() * height();
      painter.fillRect(w * i, height() - h, w * (i + 1), height(), QColor(i, 128, 255-i));
      painter.fillRect(w * i, 0, w * (i + 1), height() - h, Qt::black);
    }
  }
}
