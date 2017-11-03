#ifndef PLAT_GRID_H
#define PLAT_GRID_H

#include <algorithm>
#include <cstring>
#include <ostream>

#include <QDataStream>
#include <QFile>

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

  struct Tile {
    unsigned char elevation;
    unsigned char waterlevel;
    unsigned char temperature;
    unsigned char rainfall;
    unsigned char biome;

    friend QDataStream& operator << (QDataStream& stream, const Tile& tile) {
      return stream << tile.elevation << tile.waterlevel << tile.temperature << tile.rainfall << tile.biome;
    }

    friend QDataStream& operator >> (QDataStream& stream, Tile& tile) {
      return stream >> tile.elevation >> tile.waterlevel >> tile.temperature >> tile.rainfall >> tile.biome;
    }
  };

  template <class T>
  class Grid {
  public:
    static Grid<T> load(QDataStream& stream) {
      qint32 xbits;
      qint32 ybits;

      stream >> xbits >> ybits;
      Grid<T> Grid(xbits, ybits);
      for(int i = 0; i < Grid.area(); ++i) {
        stream >> Grid.mData[i];
      }

      return Grid;
    }

  protected:
    T*  mData;
    int mXBits;
    int mYBits;
    int mWidth;
    int mHeight;
    int mXMask;
    int mYMask;
  public:
    Grid(int xbits, int ybits) {
      mXBits  = xbits;
      mYBits  = ybits;
      mWidth  = 1 << mXBits;
      mHeight = 1 << mYBits;
      mXMask  = mWidth  - 1;
      mYMask  = mHeight - 1;
      mData   = new T[area()];
    }

    // Grid(Grid<T>&& other) {
    //   *this = other;
    // }

    // Grid(const Grid<T>& other) {
    //   *this = other;
    // }

    ~Grid() {
      delete [] mData;
    }

    int area() const {
      return mWidth * mHeight;
    }

    T& get(int x, int y) {
      return mData[((y & mYMask) << mXBits) | (x & mXMask)];
    }

    const T& get(int x, int y) const {
      return mData[((y & mYMask) << mXBits) | (x & mXMask)];
    }

    int height() const {
      return mHeight;
    }

    void save(QDataStream& stream) {
      stream << qint32(xbits()) << qint32(ybits());
      for(int i = 0; i < area(); ++i) {
        stream << mData[i];
      }
    }

    void set(int x, int y, const T& v) {
      this->get(x, y) = v;
    }

    int width() const {
      return mWidth;
    }

    int xbits() const {
      return mXBits;
    }

    int ybits() const {
      return mYBits;
    }

    int xdiff(int x1, int x2) const {
      return ((x1 - x2 + mWidth / 2) & mXMask) - mWidth / 2;
    }

    int ydiff(int y1, int y2) const {
      return ((y1 - y2 + mHeight / 2) & mYMask) - mHeight / 2;
    }

    // Grid& operator = (Grid&& other) {
    //   mXBits  = other.mXBits;
    //   mYBits  = other.mYBits;
    //   mWidth  = other.mWidth;
    //   mHeight = other.mHeight;
    //   mXMask  = other.mXMask;
    //   mYMask  = other.mYMask;

    //   std::swap(mData, other.mData);
    //   return *this;
    // }

    // Grid& operator = (const Grid& other) {
    //   if(area() != other.area()) {
    //     delete [] mData;
    //     mData = new T[other.area()];
    //   }

    //   mXBits  = other.mXBits;
    //   mYBits  = other.mYBits;
    //   mWidth  = other.mWidth;
    //   mHeight = other.mHeight;
    //   mXMask  = other.mXMask;
    //   mYMask  = other.mYMask;

    //   std::memcpy(mData, other.mData, area() * sizeof(T));
    //   return *this;
    // }

    // T& operator [] (const Point& p) {
    //   return this->get(p.x, p.y);
    // }

    // const T& operator [] (const Point& p) const {
    //   return this->get(p.x, p.y);
    // }
  };

  class Map: public Grid<Tile> {
  public:
    Map(int xbits, int ybits): Grid<Tile>(xbits, ybits) {
      // That is all.
    }
  };

  class Field: public Grid<float> {
  public:
    Field(int xbits, int ybits): Grid<float>(xbits, ybits) {
      // That is all.
    }
  };
}

#endif
