#ifndef PLAT_SIDEPANEL_H
#define PLAT_SIDEPANEL_H

#include <QWidget>

class QPushButton;

namespace Plat
{
  class Map;
  class MapWindow;
  class EditPanel;
  class StatPanel;

  class SidePanel: public QWidget {
    Q_OBJECT
  protected:
    EditPanel*   mEditPanel;
    StatPanel*   mStatPanel;
    QPushButton* mGenerate;
  public:
    SidePanel(MapWindow* window);
  };
}

#endif
