#include "Histogram.h"

namespace Plat
{
  Histogram::Histogram() {
    clear();
  }

  void Histogram::add(unsigned char x) {
    mCount   += 1;
    mData[x] += 1;

    if(mData[x] > mMaxBar) {
      mMaxBar = mData[x];
    }
  }

  void Histogram::clear() {
    for(int i = 0; i < 256; ++i) {
      mData[i] = 0;
    }

    mCount  = 0;
    mMaxBar = 0;
  }

  int Histogram::count() const {
    return mCount;
  }

  int Histogram::maxbar() const {
    return mMaxBar;
  }

  int Histogram::maxcut(float p) const {
    int a = p * count();
    int s = 0;
    int i = 0;

    while(i >= 0 && s < a) {
      s += mData[i];
      i -= 1;
    }

    return i;
  }

  int Histogram::mincut(float p) const {
    int a = p * count();
    int s = 0;
    int i = 0;

    while(i < 256 && s < a) {
      s += mData[i];
      i += 1;
    }

    return i;
  }

  int& Histogram::operator [] (int index) {
    return mData[index];
  }

  int Histogram::operator [] (int index) const {
    return mData[index];
  }
}
