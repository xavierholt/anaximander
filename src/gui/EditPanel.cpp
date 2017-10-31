#include "EditPanel.h"

#include "MapWindow.h"
#include "gen/DiamondSquareEditor.h"
#include "../gen/DiamondSquareGenerator.h"

#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

namespace Plat
{
  EditPanel::EditPanel(MapWindow* window) {
    QVBoxLayout* layout = new QVBoxLayout;
    QFormLayout* mapdim = new QFormLayout;

    mMapWidth = new QSpinBox;
    mMapWidth->setMinimum(3);
    mMapWidth->setMaximum(11);
    mMapWidth->setValue(8);

    mMapHeight = new QSpinBox;
    mMapHeight->setMinimum(3);
    mMapHeight->setMaximum(11);
    mMapHeight->setValue(8);

    mGenEditor = new DiamondSquareEditor;

    mapdim->addRow("Map Width",  mMapWidth);
    mapdim->addRow("Map Height", mMapHeight);

    layout->addLayout(mapdim);
    layout->addWidget(mGenEditor);
    layout->addStretch(1);
    setLayout(layout);

    connect(this, SIGNAL(generated(Field)), window, SLOT(setElevation(Field)));
  }

  void EditPanel::generate() {
    int xbits = mMapWidth->value();
    int ybits = mMapHeight->value();

    Field field(xbits, ybits);
    mGenEditor->next(field);
    emit(generated(field));
  }
}
