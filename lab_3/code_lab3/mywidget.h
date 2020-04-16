#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QDebug>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPointF>
#pragma comment( lib, "OpenGL32.lib" )

class MyWidget : public QGLWidget
{
public:
    MyWidget(QWidget *parent = 0);
    void fract();
    void traf(double xA, double yA, double xB, double yB, int r);
    void setIter(int iter);
    void setBones(bool);


protected:
   void initializeGL();
   void resizeGL(int nWidth, int nHeight);
   void paintGL();
   void wheelEvent(QWheelEvent* event);
   void mousePressEvent(QMouseEvent* event);
   void mouseMoveEvent(QMouseEvent* event);
   void mouseReleaseEvent(QMouseEvent* event);

private:
   QPointF start;
    bool canMove;
    int iter;
    void Circle(int x0, int y0, int rad, int amountSegments);
    void Triangle(int x0, int y0, int rad, int amountSegments, int level);
};

#endif // WIDGET_H
