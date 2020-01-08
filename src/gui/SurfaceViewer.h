#ifndef PLAT_SURFACEVIEWER_H
#define PLAT_SURFACEVIEWER_H

#include <QGLWidget>
#include <QOpenGLShaderProgram>

namespace Plat
{
  class Map;

  class SurfaceViewer : public QGLWidget {
    Q_OBJECT
  protected:
    int    mMouseX;
    int    mMouseY;
    float  mAltitude;
    float  mAzimuth;
    float  mDistance;

    QOpenGLShaderProgram* mShaders;
    int      mTriangles;
    GLfloat* mVertices;
    GLuint*  mIndices;
    GLubyte* mColors;

  protected:
    void initializeGL();
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void paintGL();
    void resizeGL(int w, int h);
    void wheelEvent(QWheelEvent* e);

  public:
    SurfaceViewer(QWidget* parent = 0);
    ~SurfaceViewer();

  public slots:
    void update(const Map& map);
  };
}

#endif

