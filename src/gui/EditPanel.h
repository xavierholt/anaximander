#ifndef PLAT_EDITPANEL_H
#define PLAT_EDITPANEL_H

#include <QWidget>

class QSpinBox;

namespace Plat
{
  class Field;
  class MapWindow;
  class GeneratorEditor;

  class EditPanel: public QWidget {
    Q_OBJECT
  protected:
    QSpinBox*        mMapWidth;
    QSpinBox*        mMapHeight;
    GeneratorEditor* mGenEditor;
  public:
    EditPanel(MapWindow* window);
  public slots:
    void generate();
  signals:
    void generated(const Field&);
  };
}

#endif
