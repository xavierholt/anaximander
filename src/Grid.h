#ifndef PLAT_GRID_H
#define PLAT_GRID_H

#include <QDataStream>
#include <QFile>

namespace Plat
{
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

    int xdiff(int a, int b) const {
      return ((b - a + mWidth / 2) & mXMask) - mWidth / 2;
    }

    int ybits() const {
      return mYBits;
    }

    int ydiff(int a, int b) const {
      return ((b - a + mHeight / 2) & mYMask) - mHeight / 2;
    }
  };
}

#endif
