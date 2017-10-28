#ifndef PLAT_GENERATOREDITOR_H
#define PLAT_GENERATOREDITOR_H

#include "../../map.h"
#include <QWidget>

namespace Plat
{
  class GeneratorEditor: public QWidget {
    Q_OBJECT
  public slots:
    virtual void next(Field& map) = 0;
  };
}

#endif
