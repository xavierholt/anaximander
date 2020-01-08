CONFIG += debug
QT += widgets opengl

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

SOURCES += $$files(src/core/*.cpp, true)
SOURCES += $$files(src/gui/*.cpp, true)
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
  src/gen/WhirlyGenerator.cpp \
  src/gen/WorleyGenerator.cpp
