#include "StarOfDavidGenerator.h"

namespace Plat
{
  StarOfDavidGenerator::StarOfDavidGenerator(float noise, float falloff) {
    mFalloff = falloff;
    mNoise   = noise;
  }

  void StarOfDavidGenerator::next(Field& map) {
    std::uniform_real_distribution<float> distribution(0, 1);
    const int w = map.width();
    const int h = map.height();

    int n = std::min(map.xbits(), map.ybits());
    int s = std::min(w, h);
    int d = s / 2;

    for(int x = 0; x < w; x += s) {
      for(int y = 0; y < h; y += s) {
        map.set(x, y, 0.5);
      }
    }

    for(int i = n-1; d > 0; --i) {
      float p = std::min(1.0f, mNoise * std::pow(mFalloff, float(i)));
      float q = 1.0f - p;
      float r;
      float v;

      for(int x = d; x < w; x += s) {
        for(int y = d; y < h; y += s) {
          v  = map.get(x + d, y + d);
          v += map.get(x - d, y - d);
          r  = distribution(mGenerator);
          map.set(x, y, p * r + q * v / 2);
        }
      }

      for(int x = d; x < w; x += s) {
        for(int y = 0; y < h; y += s) {
          v  = map.get(x + d, y + 0);
          v += map.get(x - d, y - 0);
          r  = distribution(mGenerator);
          map.set(x, y, p * r + q * v / 2);
        }
      }

      for(int x = 0; x < w; x += s) {
        for(int y = d; y < h; y += s) {
          v  = map.get(x + 0, y + d);
          v += map.get(x - 0, y - d);
          r  = distribution(mGenerator);
          map.set(x, y, p * r + q * v / 2);
        }
      }

      s /= 2;
      d /= 2;
    }
  }
}
