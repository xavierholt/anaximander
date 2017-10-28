#ifndef PLAT_SIDEPANEL_H
#define PLAT_SIDEPANEL_H

#include <QTabWidget>

namespace Plat
{
  class Map;
  class MapWindow;
  class EditPanel;
  class StatPanel;

  class SidePanel: public QTabWidget {
    Q_OBJECT
  protected:
    EditPanel* mEditPanel;
    StatPanel* mStatPanel;
  public:
    SidePanel(MapWindow* window);
  };
}

#endif
