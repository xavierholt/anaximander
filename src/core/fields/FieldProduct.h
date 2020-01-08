#ifndef PLAT_FIELDPRODUCT_H
#define PLAT_FIELDPRODUCT_H

#include "../FieldValue.h"
#include "../Param.h"

namespace Plat
{
  class FieldProduct: public FieldValue {
  public:
    static constexpr const char* TYPENAME = "field/product";
  protected:
    FieldParam* mFirst;
    FieldParam* mSecond;
  public:
    FieldProduct();

    virtual void generate(int xbits, int ybits);
    virtual const char* name() const;
  };
}

#endif
