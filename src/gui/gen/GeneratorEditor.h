#ifndef PLAT_GENERATOREDITOR_H
#define PLAT_GENERATOREDITOR_H

#include <QWidget>

class QDoubleSpinBox;
class QFormLayout;
class QSpinBox;

namespace Plat
{
  class Field;

  class GeneratorEditor: public QWidget {
    Q_OBJECT
  protected:
    QFormLayout* mLayout;
  protected:
    QDoubleSpinBox* addf(QString text, float min, float val, float max, float inc = 0.1);
    QSpinBox*       addi(QString text, int   min, int   val, int   max, int   inc =   1);
  public:
    GeneratorEditor();
  public slots:
    virtual void next(Field& map) = 0;
  };
}

#endif
