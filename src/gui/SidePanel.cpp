#include "SidePanel.h"

#include "EditPanel.h"
#include "StatPanel.h"

namespace Plat
{
  SidePanel::SidePanel(MapWindow* window) {
    addTab(mEditPanel = new EditPanel(window), "Generation");
    addTab(mStatPanel = new StatPanel(window), "Statistics");
  }
}
