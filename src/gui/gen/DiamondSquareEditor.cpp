#include "DiamondSquareEditor.h"
#include "../../gen/DiamondSquareGenerator.h"

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QSpinBox>

namespace Plat
{
  DiamondSquareEditor::DiamondSquareEditor() {
    mSize  = addi("Size",  0,   6, 12,    1);
    mNoise = addf("Noise", 0, 0.5,  1, 0.05);
  }

  void DiamondSquareEditor::next(Field& map) {
    int   size  = mSize->value();
    float decay = mNoise->value();
    DiamondSquareGenerator gen(size, decay);
    gen.next(map);
  }
}
