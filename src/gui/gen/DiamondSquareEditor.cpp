#include "DiamondSquareEditor.h"
#include "../../gen/DiamondSquareGenerator.h"

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QSpinBox>

namespace Plat
{
  DiamondSquareEditor::DiamondSquareEditor() {
    mSize = new QSpinBox;
    mSize->setMinimum(0);
    mSize->setMaximum(9);

    mNoise = new QDoubleSpinBox;
    mNoise->setMinimum(0);
    mNoise->setMaximum(1);

    QFormLayout* layout = new QFormLayout;
    layout->addRow("Size",  mSize);
    layout->addRow("Noise", mNoise);
    this->setLayout(layout);
  }

  void DiamondSquareEditor::next(Field& map) {
    int   size  = mSize->value();
    float noise = mNoise->value();
    DiamondSquareGenerator gen(size, noise);
    gen.next(map);
  }
}
