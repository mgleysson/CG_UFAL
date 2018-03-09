#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <algorithm>


extern float _color[3];
extern int _tam;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void drawScene();
    void mouse(int btn, int state, int x, int y);
private:
    QTimer timer;
};

#endif // GLWIDGET_H
