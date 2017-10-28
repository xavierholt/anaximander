#ifndef PLAT_BIOMEHISTOGRAM_H
#define PLAT_BIOMEHISTOGRAM_H

#include "HistogramViewer.h"

namespace Plat
{
  class BiomeHistogram: public HistogramViewer {
  protected:
    void calculate(const Map& map);
    void paint(QPainter& painter);
  };
}

#endif
