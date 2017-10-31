#include "DiamondSquareGenerator.h"

namespace Plat
{
  DiamondSquareGenerator::DiamondSquareGenerator(int size, float noise) {
    mSize  = size;
    mNoise = noise;
  }

  void DiamondSquareGenerator::next(Field& map) {
    const int w = map.width();
    const int h = map.height();

    int n = mSize;
    n = std::min(n, map.xbits());
    n = std::min(n, map.ybits());

    int s = 1 << n;
    int d = s / 2;
    int m = 0;

    float r;
    float v;
    // float z = mNoise / 2;
    float z = (mNoise == 1)? 0.5 / n : (mNoise - 1) / (pow(mNoise, n) - 1) * 0.5;

    std::uniform_real_distribution<float> init(0.5 - z, 0.5 + z);
    for(int x = 0; x < w; x += s) {
      for(int y = 0; y < h; y += s) {
        map.set(x, y, init(mGenerator));
      }
    }

    while(d > 0) {
      z *= mNoise;
      std::uniform_real_distribution<float> noise(-z, +z);

      for(int x = d; x < w; x += s) {
        for(int y = d; y < h; y += s) {
          v  = map.get(x + d, y + d);
          v += map.get(x + d, y - d);
          v += map.get(x - d, y + d);
          v += map.get(x - d, y - d);
          r  = noise(mGenerator);
          map.set(x, y, r + v / 4);
        }
      }

      for(int x = 0; x < w; x += d) {
        for(int y = (m ^= d); y < h; y += s) {
          v  = map.get(x + d, y + 0);
          v += map.get(x - d, y + 0);
          v += map.get(x + 0, y + d);
          v += map.get(x + 0, y - d);
          r  = noise(mGenerator);
          map.set(x, y, r + v / 4);
        }
      }

      s /= 2;
      d /= 2;
      m  = 0;
    }
  }
}
