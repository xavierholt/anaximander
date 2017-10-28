#ifndef PLAT_STATPANEL_H
#define PLAT_STATPANEL_H

#include <QWidget>

namespace Plat
{
  class HistogramViewer;
  class MapWindow;
  class Map;

  class StatPanel: public QWidget {
    Q_OBJECT
  protected:
    HistogramViewer* mBiome;
    HistogramViewer* mElevation;
    HistogramViewer* mTemperature;
    HistogramViewer* mRainfall;
  public:
    StatPanel(const MapWindow* window);
  public slots:
    void update(const Map& map);
  };
}

#endif
