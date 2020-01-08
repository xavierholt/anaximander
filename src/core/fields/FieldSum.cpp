#include "FieldSum.h"

#include "../../Field.h"

namespace Plat
{
  FieldSum::FieldSum() {
    mFirst  = fieldParam("first");
    mSecond = fieldParam("second");
  }

  void FieldSum::generate(int xbits, int ybits) {
    FieldValue* fa = mFirst->value();
    FieldValue* fb = mSecond->value();
    fa->generate(xbits, ybits);
    fb->generate(xbits, ybits);

    mField = new Field(xbits, ybits);
    for(int x = 0; x < mField->width(); ++x) {
      for(int y = 0; y < mField->height(); ++y) {
        float a = fa->get(x, y);
        float b = fb->get(x, y);
        mField->set(x, y, a + b);
      }
    }

    fa->release();
    fb->release();
  }

  const char* FieldSum::name() const {
    return TYPENAME;
  }
}
