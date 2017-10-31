#ifndef PLAT_GUI_MAPWINDOW_H
#define PLAT_GUI_MAPWINDOW_H

#include "../map.h"

#include <QWidget>

class QHBoxLayout;
class QPushButton;
class QVBoxLayout;

namespace Plat
{
  class MainPanel;
  class SidePanel;

  class MapWindow: public QWidget {
    Q_OBJECT
  protected:
    MainPanel* mMainPanel;
    SidePanel* mSidePanel;
  public:
    MapWindow(QWidget* parent = 0);

    void genBiome(Map& map);
    void genElevation(Map& map);
    void genRainfall(Map& map);
    void genTemperature(Map& map);

  public slots:
    void generate(int xbits, int ybits);
    void setElevation(const Field& map);
    // void load();
    // void save();

  signals:
    void generated(const Map& map);
  };
}

#endif
