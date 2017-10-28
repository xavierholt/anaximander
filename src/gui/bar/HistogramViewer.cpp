#include "HistogramViewer.h"

#include <QPainter>
#include <iostream>

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
    // std::cout << width() << 'x' << height() << '\n';
    // painter.fillRect(0, 0, width(), height(), Qt::black);
    paint(painter);
  }

  void HistogramViewer::update(const Map& map) {
    calculate(map);
    repaint();
  }
}
