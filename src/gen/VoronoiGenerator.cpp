#include "VoronoiGenerator.h"

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

  VoronoiGenerator::VoronoiGenerator(float density) {
    mDensity = density;
  }

  void VoronoiGenerator::next(Field& map) {
    int npoints = mDensity * map.area();
    std::uniform_int_distribution<int>    dx(0, map.width());
    std::uniform_int_distribution<int>    dy(0, map.height());
    std::uniform_real_distribution<float> dv(0, 1);

    KD::Wrap<KD::Core<2,Item*,Point> > tree(
      Point(0, map.width()),
      Point(0, map.height())
    );

    Item* items = new Item[npoints];
    for(int i = 0; i < npoints; ++i) {
      items[i] = Item(dx(mGenerator), dy(mGenerator), dv(mGenerator));
      tree.insert(&items[i]);
    }

    for(int x = 0; x < map.width(); ++x) {
      for(int y = 0; y < map.height(); ++y) {
        Item* nearest = tree.nearest(Point(x, y));
        map.get(x, y) = nearest->value;
      }
    }

    delete [] items;
  }
}
