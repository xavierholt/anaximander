#include "MainPanel.h"

#include "MapWindow.h"
#include "map/BiomeViewer.h"
#include "map/ElevationViewer.h"
#include "map/RainfallViewer.h"
#include "map/TemperatureViewer.h"

namespace Plat
{
  MainPanel::MainPanel(const MapWindow* window) {
    addTab(mElevation   = new ElevationViewer,   "Elevation");
    addTab(mTemperature = new TemperatureViewer, "Temperature");
    addTab(mRainfall    = new RainfallViewer,    "Rainfall");
    addTab(mBiome       = new BiomeViewer,       "Biomes");

    connect(window, SIGNAL(generated(Map)), this, SLOT(update(Map)));
  }

  void MainPanel::update(const Map& map) {
    mElevation->update(map);
    mTemperature->update(map);
    mRainfall->update(map);
    mBiome->update(map);
  }
}
