QT += widgets

DESTDIR         = builds/default
Release:DESTDIR = builds/release
Debug:DESTDIR   = builds/debug

OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR     = $${DESTDIR}/.moc
RCC_DIR     = $${DESTDIR}/.rcc
UI_DIR      = $${DESTDIR}/.ui

HEADERS += $$files(src/gen/kd/src/*.h, true)
HEADERS += \
  src/map.h \
  src/Biome.h \
  src/Histogram.h \
  src/gen/DiamondSquareGenerator.h \
  src/gen/FieldGenerator.h \
  src/gen/MarbleGenerator.h \
  src/gen/PerlinGenerator.h \
  src/gen/StarOfDavidGenerator.h \
  src/gen/VoronoiGenerator.h \
  src/gen/WorleyGenerator.h \
  src/gui/EditPanel.h \
  src/gui/MainPanel.h \
  src/gui/MapWindow.h \
  src/gui/SidePanel.h \
  src/gui/StatPanel.h \
  src/gui/bar/BiomeHistogram.h \
  src/gui/bar/ElevationHistogram.h \
  src/gui/bar/RainfallHistogram.h \
  src/gui/bar/TemperatureHistogram.h \
  src/gui/bar/HistogramViewer.h \
  src/gui/gen/DiamondSquareEditor.h \
  src/gui/gen/GeneratorEditor.h \
  src/gui/map/BiomeViewer.h \
  src/gui/map/ElevationViewer.h \
  src/gui/map/RainfallViewer.h \
  src/gui/map/TemperatureViewer.h \
  src/gui/map/MapViewer.h
SOURCES += \
  src/main.cpp \
  src/Biome.cpp \
  src/Histogram.cpp \
  src/gen/DiamondSquareGenerator.cpp \
  src/gen/FieldGenerator.cpp \
  src/gen/MarbleGenerator.cpp \
  src/gen/PerlinGenerator.cpp \
  src/gen/StarOfDavidGenerator.cpp \
  src/gen/VoronoiGenerator.cpp \
  src/gen/WorleyGenerator.cpp \
  src/gui/EditPanel.cpp \
  src/gui/MainPanel.cpp \
  src/gui/MapWindow.cpp \
  src/gui/SidePanel.cpp \
  src/gui/StatPanel.cpp \
  src/gui/bar/BiomeHistogram.cpp \
  src/gui/bar/ElevationHistogram.cpp \
  src/gui/bar/RainfallHistogram.cpp \
  src/gui/bar/TemperatureHistogram.cpp \
  src/gui/bar/HistogramViewer.cpp \
  src/gui/gen/DiamondSquareEditor.cpp \
  src/gui/gen/GeneratorEditor.cpp \
  src/gui/map/BiomeViewer.cpp \
  src/gui/map/ElevationViewer.cpp \
  src/gui/map/RainfallViewer.cpp \
  src/gui/map/TemperatureViewer.cpp \
  src/gui/map/MapViewer.cpp
