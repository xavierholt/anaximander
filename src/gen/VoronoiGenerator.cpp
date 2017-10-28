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

    KD::Tree<KD::Core<2,Item*,Point> > tree(
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
        std::vector<Item*> neighbors = tree.nearest(Point(x, y), 2);
        float dx0 = x - neighbors[0]->point().x;
        float dx1 = x - neighbors[1]->point().x;
        float dy0 = y - neighbors[0]->point().y;
        float dy1 = y - neighbors[1]->point().y;
        map.get(x, y) = std::sqrt((dx0 * dx0 + dy0 * dy0) / (dx1 * dx1 + dy1 * dy1));
      }
    }

    delete [] items;
  }
}
