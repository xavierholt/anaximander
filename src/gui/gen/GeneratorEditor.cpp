#include "GeneratorEditor.h"

#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QSpinBox>

namespace Plat
{
  GeneratorEditor::GeneratorEditor() {
    mLayout = new QFormLayout;
    setLayout(mLayout);
  }

  QDoubleSpinBox* GeneratorEditor::addf(QString text, float min, float val, float max, float inc) {
    QDoubleSpinBox* spinbox = new QDoubleSpinBox;
    spinbox->setSingleStep(inc);
    spinbox->setMinimum(min);
    spinbox->setMaximum(max);
    spinbox->setValue(val);

    mLayout->addRow(text, spinbox);
    return spinbox;
  }

  QSpinBox* GeneratorEditor::addi(QString text, int min, int val, int max, int inc) {
    QSpinBox* spinbox = new QSpinBox;
    spinbox->setSingleStep(inc);
    spinbox->setMinimum(min);
    spinbox->setMaximum(max);
    spinbox->setValue(val);

    mLayout->addRow(text, spinbox);
    return spinbox;
  }
}
