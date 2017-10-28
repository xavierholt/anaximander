#ifndef PLAT_SIDEPANEL_H
#define PLAT_SIDEPANEL_H

#include <QWidget>

class QPushButton;

namespace Plat
{
  class Map;
  class MapWindow;
  class HistogramViewer;

  class SidePanel: public QWidget {
    Q_OBJECT
  protected:
    HistogramViewer*  mBiome;
    HistogramViewer*  mElevation;
    HistogramViewer*  mTemperature;
    HistogramViewer*  mRainfall;
    QPushButton*      mRegenerate;
  public:
    SidePanel(const MapWindow* window);
  public slots:
    void update(const Map& map);
  };
}

#endif
