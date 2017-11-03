#ifndef PLAT_POINT_H
#define PLAT_POINT_H

#include <ostream>

namespace Plat
{
  class Point {
  public:
    union {
      int coordinates[2];
      struct {
        int x;
        int y;
      };
    };
  public:
    Point(): x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}

    int& operator [] (int index) {
      return coordinates[index];
    }

    int operator [] (int index) const {
      return coordinates[index];
    }

    friend std::ostream& operator << (std::ostream& stream, const Point& point) {
      return stream << '(' << point.x << ", " << point.y << ')';
    }
  };
}

#endif
