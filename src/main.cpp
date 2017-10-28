#include "gui/MapWindow.h"

#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Plat::MapWindow window;
  window.showMaximized();

  return app.exec();
}
