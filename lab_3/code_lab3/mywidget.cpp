#include "mywidget.h"
#include "math.h"

const double PI = 3.141592653589793;

MyWidget::MyWidget(QWidget *parent) // конструктор
    : QGLWidget(parent)
{
    canMove=false;
    iter=0;
    start=QPointF(0.0,0.0);
}


void MyWidget::initializeGL()
{
    qglClearColor(Qt::black); // заполняем экран белым цветом
    glShadeModel(GL_SMOOTH);
}


void MyWidget::resizeGL(int nWidth, int nHeight)
{
    glViewport(0, 0, nWidth, nHeight); // установка точки обзора
    glMatrixMode(GL_PROJECTION); // установка режима матрицы
    //glLoadIdentity(); // загрузка матрицы////////////
    glOrtho(0,nWidth,0,nHeight,-10.0,1.0);
}

void MyWidget::paintGL() // рисование
{
    glClear ( GL_COLOR_BUFFER_BIT );

    //рисуем окружность
    float x0 = 270.0;
    float y0 = 270.0;
    float rad = 240.0;
    int amountSegments = 30;
    Triangle(x0, y0, rad, amountSegments, this->iter); //iter=0
}

//рисует окружность
void MyWidget::Circle(int x0, int y0, int rad, int amountSegments){
    glColor3f(0.0, 0.0, 1.0); //зеленый цвет
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < amountSegments; i++)
    {
        float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);
        float dx0 = rad * cosf(angle);
        float dy0 = rad * sinf(angle);
        glVertex2f(x0 + dx0, y0 + dy0);
    }
    glEnd();
}


void MyWidget::Triangle(int x0, int y0, int rad, int amountSegments, int level){
    if (level > 0) {
        Circle(x0, y0, rad, amountSegments);

        int f, g, xi, yi;
        int c = 3;
        int b = 6;
        f = round(rad/c);
        g = round(rad*(c-1)/c);
        Circle(x0, y0, f, amountSegments);
        for (int s=0; s<6; s++)
        {
            xi = x0 - round(g*sin(2*PI/b*s ));
            yi = y0 + round(g*cos(2*PI/b*s)), f, 30;
            Triangle(x0, y0, f, amountSegments, level-1);
            Triangle(xi, yi, f, amountSegments, level-1);
        }
    }
    else{
        Circle(x0, y0, rad, amountSegments);
    }
}


void MyWidget::setIter(int iter){
    this->iter=iter;
}


void MyWidget::wheelEvent(QWheelEvent *event){
    qDebug()<<event->pos()<<' '<<event->delta();
    glTranslatef(event->pos().x(),(event->pos().y()-520)*(-1),0);
    if(event->delta()>0){
        glScalef(1.1,1.1,0); // масштабирование
    } else if(event->delta()<0){
        glScalef(0.9,0.9,0);
    }
    glTranslatef(event->pos().x()*(-1),(event->pos().y()-520),0);
    updateGL();
}


void MyWidget::mousePressEvent(QMouseEvent *event){
    canMove=true;
    start=QPointF(event->x(),event->y());
}


void MyWidget::mouseReleaseEvent(QMouseEvent *event){
    canMove=false;
}


void MyWidget::mouseMoveEvent(QMouseEvent *event){
    start.setX(event->x()-start.x());
    start.setY(event->y()-start.y());
    qDebug()<<start;
    glTranslatef(start.x()/10,-start.y()/10,0.0f);
    start=event->pos();
    updateGL();
}

