#ifndef PLAT_MAPVIEWER_H
#define PLAT_MAPVIEWER_H

#include <QLabel>
#include <QScrollArea>

class QImage;
class QLabel;

namespace Plat
{
  class Map;

  class MapViewer: public QScrollArea {
  protected:
    QLabel* mLabel;
  public:
    MapViewer(QWidget* parent = 0);

    virtual void xxx(const Map& map, QImage& image) = 0;

    void clear();
    void update(const Map& map);
  };
}

#endif
