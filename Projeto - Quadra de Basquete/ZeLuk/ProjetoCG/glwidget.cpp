#include "glwidget.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <vector>
#include <utility>
#include <bresenham.h>
#include "defines.h"


float _color[3] = {0,0,0};
int _tam = 1;
int _eqRetaOrBresenham = EQRETA;


GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));//updateGL() chama a paintGL() pra atualizar
    timer.start(50);
}

void GLWidget::initializeGL() {
    glClearColor(0.2, 0.2, 0.2, 0.0);
   // glMatrixMode(GL_PROJECTION);
   // glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glViewport(0, 0, WIDTH, HEIGHT);
   // glMatrixMode(GL_MODELVIEW);

}

void GLWidget::paintGL() {
    //float f = (float)(c++%10)/10;
    //glClearColor(0, f, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(_color[0], _color[1], _color[2]);
    glPointSize(_tam);
    if(_eqRetaOrBresenham == EQRETA){
        for(int i = 0; i < secondPoint.size(); i++ ){
            bresenham(firstPoint[i].first,firstPoint[i].second,secondPoint[i].first,secondPoint[i].second); //mudar pra equação da reta
        }
    } else if (_eqRetaOrBresenham == BRESENHAM){
        for(int i = 0; i < secondPoint.size(); i++ ){
            bresenham(firstPoint[i].first,firstPoint[i].second,secondPoint[i].first,secondPoint[i].second);
        }
    }



    glFlush();

}

void GLWidget::resizeGL(int w, int h){

}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    std::pair<int,int> point;
    point.first = event->x();
    point.second = 399-event->y();
    if(firstClick) {
        firstPoint.push_back(point);
        firstClick = false;
    } else {
        secondPoint.push_back(point);
        firstClick = true;
    }
    updateGL();
   // QMessageBox::information(this,"Tittle","x="+QString::number(point.first)+"\ny="+QString::number(point.second));
   // QMessageBox::information(this,"tam",QString::number(secondPoint.size()));
}


