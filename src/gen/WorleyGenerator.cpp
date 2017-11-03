#include "WorleyGenerator.h"

#include "kd/src/tree.h"

namespace Plat
{
  namespace {
    struct Item {
      Point mPoint;
      float value;

      Item() {}
      Item(int x, int y, float v = 1.0f): mPoint(x, y) {
        value = v;
      }

      const Point& point() const {
        return mPoint;
      }

      int& operator [] (int i) {
        return mPoint[i];
      }

      int operator [] (int i) const {
        return mPoint[i];
      }

      bool operator == (const Item& other) {
        return this == &other;
      }
    };
  }

  WorleyGenerator::WorleyGenerator(int size, int count) {
    mSize  = size;
    mCount = count;
  }

  void WorleyGenerator::next(Field& map) {
    const int w = map.width();
    const int h = map.height();

    int n = mSize;
    n = std::min(n, map.xbits());
    n = std::min(n, map.ybits());
    int s = 1 << n;

    KD::Wrap<KD::Core<2,Item*,Point> > tree(
      Point(0, 0),
      Point(map.width(), map.height())
    );

    int i = 0;
    Item* items = new Item[h/s * w/s * mCount];
    std::uniform_int_distribution<int> d(0, s);

    for(int x = 0; x < w; x += s) {
      for(int y = 0; y < h; y += s) {
        for(int z = 0; z < mCount; ++z) {
          items[i] = Item(x + d(mGenerator), y + d(mGenerator), 0);
          tree.insert(&items[i]);
          i += 1;
        }
      }
    }

    const float m = std::sqrt(2.0f) / 2.0f + 1.0f;
    const float b = std::sqrt(2.0f) - 1.0f;

    for(int x = 0; x < w; ++x) {
      for(int y = 0; y < h; ++y) {
        Item* nearest = tree.nearest(Point(x, y));
        float dx = map.xdiff(x, nearest->point().x);
        float dy = map.ydiff(y, nearest->point().y);
        float d  = std::sqrt(dx * dx + dy * dy);
        map.get(x, y) = m * (float(s) / (float(s) + d) - b);
      }
    }

    delete [] items;
  }
}
