#include "WhirlyGenerator.h"

#include "../Point.h"
#include "kd/src/tree.h"

namespace Plat
{
  namespace {
    struct Item: public Point {
      float value;

      Item() {}
      Item(int x, int y, float v = 1.0f): Point(x, y) {
        value = v;
      }

      const Point& point() const {
        return *this;
      }

      const Item& operator = (const Item& other) {
        Point::operator = (other);
        value = other.value;
        return *this;
      }

      bool operator == (const Item& other) {
        return this == &other;
      }
    };

    // float triarea(const Point& a, const Point& b, const Point& c) {
    //   int pos = (a.x * b.y + b.x * c.y + c.x * a.y);
    //   int neg = (a.x * c.y + b.x * a.y + c.x * b.y);
    //   return std::abs(pos - neg);
    // }

    // bool splits(const Point& a, const Point& b, const Point& c, const Point& d) {
    //   int div = (d.x - c.x) * (b.y - a.y) - (b.x - a.x) * (d.y - c.y);
    //   if(div == 0) return false;

    //   int t = (d.x - c.x) * (c.y - a.y) - (c.x - a.x) * (d.y - c.y);
    //   if(div < 0 && (t < div || t > 0)) return false;
    //   if(div > 0 && (t > div || t < 0)) return false;

    //   t = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    //   if(div < 0 && (t < div || t > 0)) return false;
    //   if(div > 0 && (t > div || t < 0)) return false;

    //   return true;
    // }
  }

  WhirlyGenerator::WhirlyGenerator(int size, int count) {
    mSize  = size;
    mCount = count;
  }

  const char* WhirlyGenerator::name() const {
    return WhirlyGenerator::TYPENAME;
  }

  void WhirlyGenerator::next(Field& map) {
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
    std::vector<Item> items(h/s * w/s * mCount);
    std::uniform_int_distribution<int>   d(0, s);
    std::uniform_int_distribution<float> v(0, 2*M_PI);

    for(int x = 0; x < w; x += s) {
      for(int y = 0; y < h; y += s) {
        for(int z = 0; z < mCount; ++z) {
          items[i] = Item(x + d(mGenerator), y + d(mGenerator), 1 - (rand() & 2));
          tree.insert(&items[i]);
          i += 1;
        }
      }
    }

    for(int x = 0; x < w; ++x) {
      for(int y = 0; y < h; ++y) {
        std::vector<Item*> nearest = tree.nearest(Point(x, y), 9);

        float v = 0;
        float w = 0;

        for(Item* item: nearest) {
          float dx = map.xdiff(x, item->x);
          float dy = map.ydiff(y, item->y);
          float d  = std::sqrt(dx * dx + dy * dy);
          float a  = std::atan2(dy, dx);

          float f = std::pow(1.1f, -d);
          v += f * (std::sin(a + d / 2) + 1) / 2;
          w += f;
        }

        map.get(x, y) = v / w;
      }
    }
  }
}
