#ifndef PLAT_ELEVATIONHISTOGRAM_H
#define PLAT_ELEVATIONHISTOGRAM_H

#include "HistogramViewer.h"

namespace Plat
{
  class ElevationHistogram: public HistogramViewer {
  protected:
    void calculate(const Map& map);
    void paint(QPainter& painter);
  };
}

#endif
