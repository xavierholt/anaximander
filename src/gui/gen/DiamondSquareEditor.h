#ifndef PLAT_DIAMONDSQUAREEDITOR_H
#define PLAT_DIAMONDSQUAREEDITOR_H

#include "GeneratorEditor.h"

class QSpinBox;
class QDoubleSpinBox;

namespace Plat
{
  class DiamondSquareEditor: public GeneratorEditor {
  protected:
    QSpinBox*       mSize;
    QDoubleSpinBox* mNoise;
  public:
    DiamondSquareEditor();
    void next(Field& map);
  };
}

#endif
