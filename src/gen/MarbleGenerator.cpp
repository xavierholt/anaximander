#include "MarbleGenerator.h"

#include "../core/FieldValue.h"
#include "../core/FloatValue.h"
#include "../core/IntValue.h"

#include "DiamondSquareGenerator.h"
#include "../core/FloatConstant.h"
#include "../core/IntConstant.h"

namespace Plat
{
  MarbleGenerator::MarbleGenerator(int xp, int yp, float turbulence) {
    // mXPeriod    = float(1 << xp);
    // mYPeriod    = float(1 << yp);
    // mTurbulence = turbulence;

    mScale   = intParam("scale");
    mXPeriod = intParam("xperiod");
    mYPeriod = intParam("yperiod");

    mNoise      = fieldParam("noise");
    mTurbulence = floatParam("turbulence");

    mScale->setValue(new IntConstant(7));
    mXPeriod->setValue(new IntConstant(xp));
    mYPeriod->setValue(new IntConstant(yp));

    mNoise->setValue(new DiamondSquareGenerator);
    mTurbulence->setValue(new FloatConstant(turbulence));
  }

  const char* MarbleGenerator::name() const {
    return MarbleGenerator::TYPENAME;
  }

  void MarbleGenerator::next(Field& map) {
    const int w = map.width();
    const int h = map.height();
    // DiamondSquareGenerator noise(4, 0.3);
    // noise.next(map);

    int   scale       = mScale->value()->get();
    float xperiod     = mXPeriod->value()->get() << scale;
    float yperiod     = mYPeriod->value()->get() << scale;
    float turbulence  = mTurbulence->value()->get();
    FieldValue* noise = mNoise->value();
    noise->generate(map.xbits(), map.ybits());

    for(int x = 0; x < w; ++x) {
      for(int y = 0; y < h; ++y) {
        float v = x / xperiod + y / yperiod;
        float t = noise->get(x, y) * turbulence;
        map.set(x, y, abs(sin((v + t) * M_PI)));
        // map.set(x, y, sin((v + t) * M_PI));
      }
    }

    // mNoise->release();
  }
}
