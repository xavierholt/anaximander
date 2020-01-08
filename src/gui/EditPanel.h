#ifndef PLAT_EDITPANEL_H
#define PLAT_EDITPANEL_H

#include <QWidget>

class QSpinBox;
class QTreeView;

namespace Plat
{
  class Field;
  class WorldParam;
  class WorldValue;

  class MapWindow;

  class EditPanel: public QWidget {
    Q_OBJECT
  protected:
    QSpinBox*   mMapWidth;
    QSpinBox*   mMapHeight;

    QTreeView*  mTreeView;
    WorldParam* mRoot;
    WorldValue* mWorld;
  public:
    EditPanel(MapWindow* window);
  public slots:
    void generate();
  signals:
    void generated(const Field&);
  };
}

#endif
