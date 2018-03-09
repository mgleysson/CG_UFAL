#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <algorithm>


extern float _color[3];
extern int _tam;
extern int _eqRetaOrBresenham;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);

private:
    QTimer timer;
    int xAtPress, yAtPress;
    std::vector<std::pair<int,int>> firstPoint;
    std::vector<std::pair<int,int>> secondPoint;
    bool firstClick = true;
};

#endif // GLWIDGET_H
