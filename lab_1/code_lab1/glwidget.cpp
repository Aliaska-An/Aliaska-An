#include "glwidget.h"



GLWidget::GLWidget(QWidget *parent): QGLWidget(parent) {}

void GLWidget::initializeGL()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glLineWidth(5.0f);
    glPointSize(5.0f);

}

void drawPicture(QString type)
{
    if(type == "GL_POINTS")
    {

        glBegin(GL_POINTS);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_LINES")
    {

        glBegin(GL_LINES);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_LINE_STRIP")
    {

        glBegin(GL_LINE_STRIP);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_LINE_LOOP")
    {

        glBegin(GL_LINE_LOOP);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_TRIANGLES")
    {
        glBegin(GL_TRIANGLES);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_TRIANGLE_STRIP")
    {
        glBegin(GL_TRIANGLE_STRIP);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_TRIANGLE_FAN")
    {
        glBegin(GL_TRIANGLE_FAN);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_QUADS")
    {
        glBegin(GL_QUADS);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_QUAD_STRIP")
    {
        glBegin(GL_QUAD_STRIP);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }
    if(type == "GL_POLYGON")
    {
        glBegin(GL_POLYGON);

        glColor3f(0.5f, 0.3f, 0.2f);
        glVertex2f(-0.6f, -0.9f);

        glColor3f(0.0f, 0.9f, 0.3f);
        glVertex2f(-0.3f, -0.8f);

        glColor3f(0.4f, 0.3f, 0.9f);
        glVertex2f(-0.2f, -0.5f);

        glColor3f(1.0f, 1.0f, 0.9f);
        glVertex2f(-0.1f, 0.1f);

        glColor3f(0.7f, 0.7f, 0.2f);
        glVertex2f(-0.4f, -0.1f);

        glColor3f(0.7f, 0.5f, 0.5f);
        glVertex2f(-0.7f, 0.0f);

        glColor3f(0.3f, 0.9f, 0.5f);
        glVertex2f(-0.8f, -0.5f);

        glColor3f(0.8f, 0.1f, 0.9f);
        glVertex2f(-0.8f, -0.8f);

        glEnd();
        return;
    }

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawPicture(this->ComboBox_type);
}

void GLWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void GLWidget::changeShapePicture(QString type)
{
    this->ComboBox_type = type;
    glClear(GL_COLOR_BUFFER_BIT);
    this->updateGL();
}


