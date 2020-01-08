#ifndef PLAT_XORSHIFTGENERATOR_H
#define PLAT_XORSHIFTGENERATOR_H

// Based on generator "xorshift64star32b" from:
// https://gist.github.com/imneme/9b769cefccac1f2bd728596da3a856dd

#include <cstdint>

namespace Plat
{
  class XorShiftGenerator {
    uint64_t mState;
  public:
    XorShiftGenerator() {
      mState = 0xc1f651c67c62c6e0ULL;
    }

    XorShiftGenerator(uint64_t seed) {
      mState = seed;
    }

    void seed(uint64_t seed) {
      mState = seed;
    }

    uint64_t state() const {
      return mState;
    }

    float f() {
      return float(i()) / (1U << 31);
    }

    int32_t i() {
      mState ^= mState >> 11;
      mState ^= mState << 29;
      mState ^= mState >> 14;
      return (mState * 0xd70ca3edf74bcc9dULL) >> 32;
    }

    uint32_t u() {
      return i();
    }
  };
}

#endif
