#ifndef PLAT_FIELDSUM_H
#define PLAT_FIELDSUM_H

#include "../FieldValue.h"
#include "../Param.h"

namespace Plat
{
  class FieldSum: public FieldValue {
  public:
    static constexpr const char* TYPENAME = "field/sum";
  protected:
    FieldParam* mFirst;
    FieldParam* mSecond;
  public:
    FieldSum();

    virtual void generate(int xbits, int ybits);
    virtual const char* name() const;
  };
}

#endif
