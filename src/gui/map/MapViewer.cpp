#include "MapViewer.h"

#include "../../map.h"

namespace Plat
{
  MapViewer::MapViewer(QWidget* parent): QScrollArea(parent) {
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setFrameStyle(QFrame::NoFrame);
    setWidget(mLabel = new QLabel);
  }

  void MapViewer::clear() {
    mLabel->setPixmap(QPixmap());
  }

  void MapViewer::update(const Map& map) {
    QImage image(map.width(), map.height(), QImage::Format_RGB32);
    xxx(map, image);
    mLabel->setPixmap(QPixmap::fromImage(image));
    mLabel->resize(map.width(), map.height());
  }
}
