#include "SurfaceViewer.h"
#include "../Map.h"

#include <QMouseEvent>
#include <QWheelEvent>

namespace Plat
{
  SurfaceViewer::SurfaceViewer(QWidget* parent): QGLWidget(parent) {
    mAltitude  = 45.0;
    mAzimuth   = 45.0;
    mDistance  =  2.0;

    mTriangles = 0;
    mVertices  = nullptr;
    mIndices   = nullptr;
    mColors    = nullptr;
  }

  SurfaceViewer::~SurfaceViewer() {
    delete [] mVertices;
    delete [] mIndices;
    delete [] mColors;
  }

  void SurfaceViewer::initializeGL() {

    qDebug("%s", glGetString(GL_VERSION));
    glClearColor(255, 255, 255, 0);

    glEnable(GL_DEPTH_TEST);
  //  glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glEnable(GL_COLOR_MATERIAL);
  //   glEnable(GL_LIGHTING);
  //   glEnable(GL_LIGHT0);
  // //  glEnable(GL_MULTISAMPLE);
  //   static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
  //   glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // mShaders = new QOpenGLShaderProgram;
    // mShaders->addShaderFromSourceCode(QOpenGLShader::Geometry,
    //   // "#version 3.30\n"
    //   "layout(triangles) in;\n"
    //   "layout(triangle_strip, max_vertices=3) out;\n"
    //   "\n"
    //   "out vec3 normal;\n"
    //   "\n"
    //   "void main(void) {\n"
    //   "  vec3 a = (gl_in[1].gl_Position - gl_in[0].gl_Position).xyz;\n"
    //   "  vec3 b = (gl_in[2].gl_Position - gl_in[0].gl_Position).xyz;\n"
    //   "  vec3 N = normalize(cross(b, a));\n"
    //   "\n"
    //   "  for(int i = 0; i < gl_in.length(); ++i) {\n"
    //   "    gl_Position = gl_in[i].gl_Position;\n"
    //   "    normal = N;\n"
    //   "    EmitVertex();\n"
    //   "  }\n"
    //   "\n"
    //   "  EndPrimitive();\n"
    //   "}\n"
    // );

    // mShaders->addShaderFromSourceCode(QOpenGLShader::Vertex,
    //   // "#version 3.30\n"
    //   "attribute vec4 vertex;\n"
    //   "uniform   mat4 matrix;\n"
    //   "\n"
    //   "void main(void) {\n"
    //   "  gl_Position = matrix * vertex;\n"
    //   "}\n"
    // );

    // mShaders->addShaderFromSourceCode(QOpenGLShader::Fragment,
    //   // "#version 3.30\n"
    //   "uniform vec4 color;\n"
    //   "\n"
    //   "void main(void) {\n"
    //   "  gl_FragColor = color;\n"
    //   "}\n"
    // );
  }

  void SurfaceViewer::mouseMoveEvent(QMouseEvent* e) {
    mAltitude += (e->y() - mMouseY);
    mAzimuth  += (e->x() - mMouseX);
    mousePressEvent(e);
    updateGL();
  }

  void SurfaceViewer::mousePressEvent(QMouseEvent* e) {
    mMouseX = e->x();
    mMouseY = e->y();
  }

  void SurfaceViewer::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -mDistance);
    glRotatef(mAltitude, 1.0, 0.0, 0.0);
    glRotatef(mAzimuth,  0.0, 1.0, 0.0);

    // glDisable(GL_LIGHTING);
    // glBegin(GL_LINES);
    // {
    //   glColor3f(0.9, 0.7, 0.7);
    //   glVertex3f(+1, 0, 0);
    //   glVertex3f(-1, 0, 0);

    //   glColor3f(0.7, 0.9, 0.7);
    //   glVertex3f(0, +1, 0);
    //   glVertex3f(0, -1, 0);

    //   glColor3f(0.7, 0.7, 0.9);
    //   glVertex3f(0, 0, +1);
    //   glVertex3f(0, 0, -1);

    //   glColor3f(0.5, 0.5, 0.5);
    // }
    // glEnd();

    // glEnable(GL_LIGHTING);

    // Draw stuff here!
    if(mTriangles > 0) {
      // mShaders->bind();
      glEnableClientState(GL_COLOR_ARRAY);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3, GL_FLOAT, 0, mVertices);
      glColorPointer(3, GL_UNSIGNED_BYTE, 0, mColors);
      glDrawElements(GL_TRIANGLES, mTriangles * 3, GL_UNSIGNED_INT, mIndices);
      glDisableClientState(GL_VERTEX_ARRAY);
      glDisableClientState(GL_COLOR_ARRAY);
      // mShaders->release();

      glBegin(GL_QUADS);
      {
        glColor4f(0, 0, 1, 0.4);
        glVertex3f(+1, 0, -1);
        glVertex3f(+1, 0, +1);
        glVertex3f(-1, 0, +1);
        glVertex3f(-1, 0, -1);
      }
      glEnd();
    }
  }

  void SurfaceViewer::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);

    float r = (float) w / (float) h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float v = 0.1;
    glFrustum(-r*v, +r*v, -v, +v, v, 7);
    glMatrixMode(GL_MODELVIEW);
  }

  void SurfaceViewer::update(const Map& map) {
    delete [] mVertices;
    delete [] mIndices;

    int w = map.width();
    int h = map.height();

    mTriangles = (w - 1) * (h - 1) * 2;
    mVertices  = new GLfloat[map.area() * 3];
    mIndices   = new GLuint[mTriangles * 3];
    mColors    = new GLubyte[mTriangles * 3];

    int index = 0;
    for(int x = 0; x < w; ++x) {
      for(int y = 0; y < h; ++y) {
        mVertices[index + 0] = float(x - w/2) / 256;
        mVertices[index + 1] = float(map.get(x, y).elevation - 128) / 2550;
        mVertices[index + 2] = float(y - h/2) / 256;

        mColors[index + 0] = map.get(x, y).elevation;
        mColors[index + 1] = map.get(x, y).elevation;
        mColors[index + 2] = map.get(x, y).elevation;

        index += 3;
      }
    }

    index = 0;
    for(int x = 1; x < w; ++x) {
      for(int y = 1; y < h; ++y) {
        int i = h * x + y;
        mIndices[index + 0] = i;
        mIndices[index + 1] = i - 1;
        mIndices[index + 2] = i - h - 1;
        mIndices[index + 3] = i - h - 1;
        mIndices[index + 4] = i - h;
        mIndices[index + 5] = i;
        index += 6;
      }
    }

    updateGL();
  }

  void SurfaceViewer::wheelEvent(QWheelEvent* e) {
    QPoint point = e->angleDelta();
    mDistance *= 1.0f + point.y() / 1200.0f;
    updateGL();
  }
}
