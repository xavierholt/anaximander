#include "DiamondSquareGenerator.h"

#include "../core/FieldConstant.h"
#include "../core/FloatConstant.h"
#include "../core/IntConstant.h"

namespace Plat
{
  DiamondSquareGenerator::DiamondSquareGenerator(int scale, float noise): random(42) {
    mScale    =   intParam("scale");
    mVariance = fieldParam("variance");
    mFalloff  = floatParam("falloff");

    mScale->setValue(new IntConstant(scale));
    mVariance->setValue(new FieldConstant(0.25f));
    mFalloff->setValue(new FloatConstant(noise));
  }

  const char* DiamondSquareGenerator::name() const {
    return DiamondSquareGenerator::TYPENAME;
  }

  void DiamondSquareGenerator::next(Field& map) {
    const int w = map.width();
    const int h = map.height();

    int n = mScale->value()->get();
    n = std::min(n, map.xbits());
    n = std::min(n, map.ybits());

    int s = 1 << n;
    int d = s / 2;
    int m = 0;

    float z = 1.0;
    float v;

    FloatValue* falloff  = mFalloff->value();
    FieldValue* variance = mVariance->value();

    std::uniform_real_distribution<float> r(-1, +1);
    for(int x = 0; x < w; x += s) {
      for(int y = 0; y < h; y += s) {
        v = r(mGenerator) * variance->get(x, y) + 0.5;
        map.set(x, y, v);
      }
    }

    while(d > 0) {
      z *= falloff->get();
      std::uniform_real_distribution<float> r(-1, +1);

      for(int x = d; x < w; x += s) {
        for(int y = d; y < h; y += s) {
          v  = map.get(x + d, y + d);
          v += map.get(x + d, y - d);
          v += map.get(x - d, y + d);
          v += map.get(x - d, y - d);
          v  = v / 4 + r(mGenerator) * z * variance->get(x, y);
          map.set(x, y, v);
        }
      }

      for(int x = 0; x < w; x += d) {
        for(int y = (m ^= d); y < h; y += s) {
          v  = map.get(x + d, y + 0);
          v += map.get(x - d, y + 0);
          v += map.get(x + 0, y + d);
          v += map.get(x + 0, y - d);
          v  = v / 4 + r(mGenerator) * z * variance->get(x, y);
          map.set(x, y, v);
        }
      }

      s /= 2;
      d /= 2;
      m  = 0;
    }
  }
}
