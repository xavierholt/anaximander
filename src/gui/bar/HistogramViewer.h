#ifndef PLAT_HISTOGRAMVIEWER_H
#define PLAT_HISTOGRAMVIEWER_H

#include "../../map.h"
#include "../../Histogram.h"

#include <QWidget>

class QPainter;
class QPaintEvent;

namespace Plat
{
  class HistogramViewer: public QWidget {
  protected:
    Histogram mHistogram;
  protected:
    virtual void calculate(const Map& map) = 0;
    virtual void paintEvent(QPaintEvent*);
    virtual void paint(QPainter& painter) = 0;
  public:
    HistogramViewer(QWidget* parent = 0);

  public slots:
    void clear();
    void update(const Map& map);
  };
}

#endif
