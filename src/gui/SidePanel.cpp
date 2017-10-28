#include "SidePanel.h"

#include "MapWindow.h"
#include "bar/BiomeHistogram.h"
#include "bar/ElevationHistogram.h"
#include "bar/RainfallHistogram.h"
#include "bar/TemperatureHistogram.h"

#include <QPushButton>
#include <QVBoxLayout>

namespace Plat
{
  SidePanel::SidePanel(const MapWindow* window) {
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(mElevation   = new ElevationHistogram);
    layout->addWidget(mTemperature = new TemperatureHistogram);
    layout->addWidget(mRainfall    = new RainfallHistogram);
    layout->addWidget(mBiome       = new BiomeHistogram);

    layout->addStretch(1);
    layout->addWidget(mRegenerate  = new QPushButton("Generate"));
    setLayout(layout);

    connect(window, SIGNAL(generated(Map)), this, SLOT(update(Map)));
    connect(mRegenerate, SIGNAL(clicked()), window, SLOT(generate()));
  }

  void SidePanel::update(const Map& map) {
    mElevation->update(map);
    mTemperature->update(map);
    mRainfall->update(map);
    mBiome->update(map);
  }
}
