#ifndef PLAT_MAINPANEL_H
#define PLAT_MAINPANEL_H

#include <QTabWidget>

namespace Plat
{
  class Map;
  class MapViewer;
  class MapWindow;

  class MainPanel: public QTabWidget {
    Q_OBJECT
  protected:
    MapViewer* mBiome;
    MapViewer* mElevation;
    MapViewer* mTemperature;
    MapViewer* mRainfall;
  public:
    MainPanel(const MapWindow* window);
  public slots:
    void update(const Map& map);
  };
}

#endif
