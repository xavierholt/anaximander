#include "HistogramViewer.h"

#include <QPainter>

namespace Plat
{
  HistogramViewer::HistogramViewer(QWidget* parent): QWidget(parent) {
    setMinimumSize(256, 128);
  }

  void HistogramViewer::clear() {
    mHistogram.clear();
    repaint();
  }

  void HistogramViewer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    paint(painter);
  }

  void HistogramViewer::update(const Map& map) {
    calculate(map);
    repaint();
  }
}
