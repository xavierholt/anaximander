#include "DiamondSquareGenerator.h"

namespace Plat
{
  DiamondSquareGenerator::DiamondSquareGenerator(int size, float noise) {
    mSize  = 1 << size;
    mNoise = noise;
  }

  void DiamondSquareGenerator::next(Field& map) {
    const int w = map.width();
    const int h = map.height();

    std::uniform_real_distribution<float> init(0.25, 0.75);
    for(int x = 0; x < w; x += mSize) {
      for(int y = 0; y < h; y += mSize) {
        map.set(x, y, init(mGenerator));
      }
    }

    int s = mSize;
    int d = s / 2;
    int m = 0;

    float z = 0.125;
    float r;
    float v;

    while(d > 0) {
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

      z /= 2;
      s /= 2;
      d /= 2;
      m  = 0;
    }
  }
}
