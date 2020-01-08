#include "MapWindow.h"

#include "MainPanel.h"
#include "SidePanel.h"

#include "../Biome.h"
#include "../Field.h"
#include "../Map.h"

#include "../gen/DiamondSquareGenerator.h"
#include "../gen/MarbleGenerator.h"
#include "../gen/PerlinGenerator.h"
#include "../gen/StarOfDavidGenerator.h"
#include "../gen/VoronoiGenerator.h"
#include "../gen/WhirlyGenerator.h"
#include "../gen/WorleyGenerator.h"

#include <QHBoxLayout>
#include <QSplitter>

namespace Plat
{
  MapWindow::MapWindow(QWidget* parent): QWidget(parent) {
    QHBoxLayout* layout = new QHBoxLayout;
    QSplitter* splitter = new QSplitter(this);

    splitter->addWidget(mMainPanel = new MainPanel(this));
    splitter->addWidget(mSidePanel = new SidePanel(this));

    layout->addWidget(splitter);
    // layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    setWindowTitle("Map Viewer");
    generate(9, 9);
  }

  void MapWindow::generate(int xbits, int ybits) {
    Map map(xbits, ybits);

    genElevation(map);
    genTemperature(map);
    genRainfall(map);
    genBiome(map);

    emit(generated(map));
  }

  void MapWindow::genBiome(Map& map) {
    const unsigned char A = 120;
    const unsigned char B = 32;

    const unsigned char C = 128;
    const unsigned char D = 32;

    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        Tile& tile = map.get(x, y);
        tile.biome = Biome::TUNDRA;

        if(tile.temperature < A - B) {
          tile.biome = Biome::TUNDRA;
        }
        else if(tile.temperature < A) {
          if(tile.rainfall < C - D) {
            tile.biome = Biome::TUNDRA;
          }
          else {
            tile.biome = Biome::BOREAL_FOREST;
          }
        }
        else if(tile.temperature < A + B) {
          if(tile.rainfall < C - D) {
            tile.biome = Biome::TEMPERATE_GRASSLAND;
          }
          else if(tile.rainfall < C) {
            tile.biome = Biome::TEMPERATE_FOREST;
          }
          else {
            tile.biome = Biome::TEMPERATE_RAINFOREST;
          }
        }
        else {
          if(tile.rainfall < C - D) {
            tile.biome = Biome::DESERT;
          }
          else if(tile.rainfall < C) {
            tile.biome = Biome::TROPICAL_GRASSLAND;
          }
          else {
            tile.biome = Biome::TROPICAL_RAINFOREST;
          }
        }
      }
    }
  }

  void MapWindow::genElevation(Map& mMap) {
    Plat::Field map(mMap.xbits(), mMap.ybits());
    Plat::MarbleGenerator gen(6, 5, 3);
    // Plat::PerlinGenerator gen(6);
    // Plat::DiamondSquareGenerator gen(4, 0.1);
    // Plat::VoronoiGenerator gen(0.005);
    // Plat::WhirlyGenerator gen(6, 1);
    // Plat::WorleyGenerator gen(6, 1);
    gen.next(map);

    for(int x = 0; x < mMap.width(); ++x) {
      for(int y = 0; y < mMap.height(); ++y) {
        unsigned char v = 255 * map.get(x, y);
        mMap.get(x, y).elevation = v;
      }
    }
  }

  void MapWindow::genRainfall(Map& mMap) {
    Plat::Field map(mMap.xbits(), mMap.ybits());
    Plat::DiamondSquareGenerator gen;
    gen.next(map);

    for(int x = 0; x < mMap.width(); ++x) {
      for(int y = 0; y < mMap.height(); ++y) {
        unsigned char v = 255 * map.get(x, y);
        mMap.get(x, y).rainfall = v;
      }
    }
  }

  void MapWindow::genTemperature(Map& mMap) {
    Plat::Field map(mMap.xbits(), mMap.ybits());
    Plat::DiamondSquareGenerator gen;
    gen.next(map);

    for(int x = 0; x < mMap.width(); ++x) {
      for(int y = 0; y < mMap.height(); ++y) {
        unsigned char v = 255 * map.get(x, y);
        mMap.get(x, y).temperature = v;
      }
    }
  }

  void MapWindow::setElevation(const Field& field) {
    Map map(field.xbits(), field.ybits());

    float min = +std::numeric_limits<float>::infinity();
    float max = -std::numeric_limits<float>::infinity();

    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        float v = field.get(x, y);
        min = std::min(min, v);
        max = std::max(max, v);
      }
    }

    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        unsigned char v = 255 * (field.get(x, y) - min) / (max - min);
        map.get(x, y).elevation = v;
      }
    }

    genTemperature(map);
    genRainfall(map);
    genBiome(map);

    emit(generated(map));
  }

  // void MapWindow::load() {
  //   QFile file("test.map");
  //   file.open(QIODevice::ReadOnly);
  //   QDataStream stream(&file);
  //   mMap = Map::load(stream);
  // }

  // void MapWindow::save() {
  //   QFile file("test.map");
  //   file.open(QIODevice::WriteOnly);
  //   QDataStream stream(&file);
  //   mMap.save(stream);
  // }
}
