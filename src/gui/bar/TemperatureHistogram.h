#ifndef PLAT_TEMPERATUREHISTOGRAM_H
#define PLAT_TEMPERATUREHISTOGRAM_H

#include "HistogramViewer.h"

namespace Plat
{
  class TemperatureHistogram: public HistogramViewer {
  protected:
    void calculate(const Map& map);
    void paint(QPainter& painter);
  };
}

#endif
