#include "glwidget.h"


float _color[3] = {1,0,0};
int _tam = 1;
int c=0;


GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(50);
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 0.0);
}

void GLWidget::paintGL() {
    float f = (float)(c++%10)/10;
    glClearColor(f, 0, 0, 0);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    int i;

        glPointSize(1);
        glBegin(GL_POINTS);
        for(i=0;i<=500;i++){
            glVertex2f(i, i);
            glVertex2f(250, i);
        }
        glEnd();

    glFlush();

}

void GLWidget::resizeGL(int w, int h){
    w=500;
    h=500;
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glViewport(0, 0, w, h);
   // qreal aspectRatio = qreal(w) / qreal(h);
    //glOrtho(-1 * aspectRatio, 1 * aspectRatio, -1, 1, 1, -1);
}




