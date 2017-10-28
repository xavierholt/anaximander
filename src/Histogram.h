#ifndef PLAT_HISTOGRAM_H
#define PLAT_HISTOGRAM_H

namespace Plat
{
  class Histogram {
  protected:
    int mData[256];
    int mCount;
    int mMaxBar;
  public:
    Histogram();

    void add(unsigned char x);
    void clear();

    int  count()         const;
    int  maxbar()        const;
    int  maxcut(float p) const;
    int  mincut(float p) const;

    int& operator [] (int index);
    int  operator [] (int index) const;
  };
}

#endif
