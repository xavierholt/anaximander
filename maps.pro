QT += widgets

DESTDIR         = builds/default
Release:DESTDIR = builds/release
Debug:DESTDIR   = builds/debug

OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR     = $${DESTDIR}/.moc
RCC_DIR     = $${DESTDIR}/.rcc
UI_DIR      = $${DESTDIR}/.ui

HEADERS += $$files(src/*.h, false)
HEADERS += $$files(src/gen/*.h, false)
HEADERS += $$files(src/gen/kd/src/*.h, true)
HEADERS += $$files(src/gui/*.h, true)

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
