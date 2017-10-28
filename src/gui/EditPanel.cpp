#include "EditPanel.h"

#include "MapWindow.h"

#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

namespace Plat
{
  EditPanel::EditPanel(MapWindow* window) {
    mWindow = window;
    // QVBoxLayout* layout = new QVBoxLayout;
    QFormLayout* mapdim = new QFormLayout;

    mMapWidth = new QSpinBox;
    mMapWidth->setMinimum(3);
    mMapWidth->setMaximum(11);
    mMapWidth->setValue(8);

    mMapHeight = new QSpinBox;
    mMapHeight->setMinimum(3);
    mMapHeight->setMaximum(11);
    mMapHeight->setValue(8);

    mGenerate = new QPushButton("Generate");

    mapdim->addRow("Map Width",  mMapWidth);
    mapdim->addRow("Map Height", mMapHeight);
    mapdim->addRow(mGenerate);

    // layout->addLayout(mapdim);
    setLayout(mapdim);

    connect(mGenerate, SIGNAL(clicked()), this, SLOT(generate()));
  }

  void EditPanel::generate() {
    int xbits = mMapWidth->value();
    int ybits = mMapHeight->value();
    mWindow->generate(xbits, ybits);
  }
}
