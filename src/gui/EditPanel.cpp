#include "EditPanel.h"

#include "MapWindow.h"
#include "tree/TreeDelegate.h"
#include "tree/TreeModel.h"

#include "../core/Param.h"
#include "../core/FieldValue.h"
#include "../core/WorldValue.h"

#include "../Field.h"

#include <QFormLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QTreeView>
#include <QVBoxLayout>

namespace Plat
{
  EditPanel::EditPanel(MapWindow* window) {
    QVBoxLayout* layout = new QVBoxLayout;
    QFormLayout* mapdim = new QFormLayout;

    mMapWidth = new QSpinBox;
    mMapWidth->setMinimum(3);
    mMapWidth->setMaximum(11);
    mMapWidth->setValue(9);

    mMapHeight = new QSpinBox;
    mMapHeight->setMinimum(3);
    mMapHeight->setMaximum(11);
    mMapHeight->setValue(9);

    mWorld = new WorldValue;
    mRoot = new WorldParam(nullptr, "ROOT");
    mRoot->setValue(mWorld);

    mTreeView = new QTreeView;
    mTreeView->setModel(new TreeModel(mRoot));
    mTreeView->setItemDelegate(new TreeDelegate);
    mTreeView->setRootIsDecorated(true);
    // mTreeView->setEditTriggers(QAbstractItemView::AllEditTriggers);

    mapdim->addRow("Map Width",  mMapWidth);
    mapdim->addRow("Map Height", mMapHeight);

    layout->addLayout(mapdim);
    layout->addWidget(mTreeView);
    // layout->addStretch(1);
    setLayout(layout);

    connect(mTreeView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), mTreeView, SLOT(expand(QModelIndex)));
    connect(this, SIGNAL(generated(Field)), window, SLOT(setElevation(Field)));

  }

  void EditPanel::generate() {
    int xbits = mMapWidth->value();
    int ybits = mMapHeight->value();

    mWorld->prepare();
    mWorld->generate(xbits, ybits);
    Field* field = mWorld->elevation()->take();

    emit(generated(*field));
    mWorld->release();
    delete field;
  }
}
