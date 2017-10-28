#include "StatPanel.h"

#include "MapWindow.h"
#include "bar/BiomeHistogram.h"
#include "bar/ElevationHistogram.h"
#include "bar/RainfallHistogram.h"
#include "bar/TemperatureHistogram.h"

#include <QPushButton>
#include <QVBoxLayout>

namespace Plat
{
  StatPanel::StatPanel(const MapWindow* window) {
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(mElevation   = new ElevationHistogram);
    layout->addWidget(mTemperature = new TemperatureHistogram);
    layout->addWidget(mRainfall    = new RainfallHistogram);
    layout->addWidget(mBiome       = new BiomeHistogram);
    setLayout(layout);

    connect(window, SIGNAL(generated(Map)), this, SLOT(update(Map)));
  }

  void StatPanel::update(const Map& map) {
    mElevation->update(map);
    mTemperature->update(map);
    mRainfall->update(map);
    mBiome->update(map);
  }
}
