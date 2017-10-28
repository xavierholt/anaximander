#ifndef PLAT_RAINFALLHISTOGRAM_H
#define PLAT_RAINFALLHISTOGRAM_H

#include "HistogramViewer.h"

namespace Plat
{
  class RainfallHistogram: public HistogramViewer {
  protected:
    void calculate(const Map& map);
    void paint(QPainter& painter);
  };
}

#endif
