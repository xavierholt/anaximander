#include "Biome.h"

#include <QColor>

namespace Plat
{
  QColor Biome::COLORS[8] = {
    QColor(255, 255, 255),
    QColor(128, 255, 192),
    QColor(192, 192,   0),
    QColor(  0, 128,   0),
    QColor(  0, 255,   0),
    QColor(255, 255,   0),
    QColor(128, 255,   0),
    QColor(255, 128,   0)
  };
}
