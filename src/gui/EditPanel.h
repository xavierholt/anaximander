#ifndef PLAT_EDITPANEL_H
#define PLAT_EDITPANEL_H

#include <QWidget>

class QPushButton;
class QSpinBox;

namespace Plat
{
  class MapWindow;

  class EditPanel: public QWidget {
    Q_OBJECT
  protected:
    MapWindow*   mWindow;
    QSpinBox*    mMapWidth;
    QSpinBox*    mMapHeight;
    QPushButton* mGenerate;
  public:
    EditPanel(MapWindow* window);
  public slots:
    void generate();
  };
}

#endif
