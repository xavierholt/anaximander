#include "MarbleGenerator.h"
#include "DiamondSquareGenerator.h"

namespace Plat
{
  MarbleGenerator::MarbleGenerator(int xp, int yp, float turbulence) {
    mXPeriod    = float(1 << xp);
    mYPeriod    = float(1 << yp);
    mTurbulence = turbulence;
  }

  void MarbleGenerator::next(Field& map) {
    const int w = map.width();
    const int h = map.height();
    DiamondSquareGenerator noise(5, 0.1);
    noise.next(map);

    for(int x = 0; x < w; ++x) {
      for(int y = 0; y < h; ++y) {
        float v = x / mXPeriod + y / mYPeriod;
        float t = map.get(x, y) * mTurbulence;
        map.set(x, y, fabs(sin((v + t) * M_PI)));
      }
    }
  }
}
