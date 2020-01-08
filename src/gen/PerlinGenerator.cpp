#include "PerlinGenerator.h"

#include "../core/Param.h"
#include "../core/IntConstant.h"

namespace Plat
{
  PerlinGenerator::PerlinGenerator(int scale) {
    mScale = intParam("scale");
    mScale->setValue(new IntConstant(scale));
  }

  const char* PerlinGenerator::name() const {
    return PerlinGenerator::TYPENAME;
  }

  void PerlinGenerator::next(Field& map) {
    const int w = map.width();
    const int h = map.height();

    int n = mScale->value()->get();
    n = std::min(n, map.xbits());
    n = std::min(n, map.ybits());
    int s = 1 << n;

    Field xs(map.xbits() - n, map.ybits() - n);
    Field ys(map.xbits() - n, map.ybits() - n);

    std::uniform_real_distribution<float> angle(0, 2*M_PI);
    for(int x = 0; x < s; ++x) {
      for(int y = 0; y < s; ++y) {
        float a = angle(mGenerator);
        xs.get(x, y) = std::cos(a);
        ys.get(x, y) = std::sin(a);
      }
    }

    for(int x = 0; x < w; ++x) {
      for(int y = 0; y < h; ++y) {
        int x1 = x >> n;
        int y1 = y >> n;

        float dx = (float(x & (s - 1)) + 0.5) / s;
        float dy = (float(y & (s - 1)) + 0.5) / s;

        float a = xs.get(x1 + 0, y1 + 0) * (dx + 0.0) + ys.get(x1 + 0, y1 + 0) * (dy + 0.0);
        float b = xs.get(x1 + 1, y1 + 0) * (dx - 1.0) + ys.get(x1 + 1, y1 + 0) * (dy + 0.0);
        float c = xs.get(x1 + 1, y1 + 1) * (dx - 1.0) + ys.get(x1 + 1, y1 + 1) * (dy - 1.0);
        float d = xs.get(x1 + 0, y1 + 1) * (dx + 0.0) + ys.get(x1 + 0, y1 + 1) * (dy - 1.0);

        // Smootherstep for interpolation
        // https://en.wikipedia.org/wiki/Smoothstep
        dx = dx * dx * dx * (6 * dx * dx - 15 * dx + 10);
        dy = dy * dy * dy * (6 * dy * dy - 15 * dy + 10);

        float e = a * (1.0 - dy) + d * dy;
        float f = b * (1.0 - dy) + c * dy;
        float g = e * (1.0 - dx) + f * dx;

        map.set(x, y, (g + 1) / 2);
      }
    }
  }
}
