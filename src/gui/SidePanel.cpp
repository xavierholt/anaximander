#include "SidePanel.h"

#include "EditPanel.h"
#include "StatPanel.h"

#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>

namespace Plat
{
  SidePanel::SidePanel(MapWindow* window) {
    QVBoxLayout* layout = new QVBoxLayout;
    QTabWidget*  tabs   = new QTabWidget;

    tabs->addTab(mEditPanel = new EditPanel(window), "Generation");
    tabs->addTab(mStatPanel = new StatPanel(window), "Statistics");

    mGenerate = new QPushButton("Generate");
    connect(mGenerate, SIGNAL(clicked()), mEditPanel, SLOT(generate()));

    layout->addWidget(tabs);
    layout->addWidget(mGenerate);
    // layout->setContentsMargins(0, 0, 0, 0);
    // setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
  }
}
