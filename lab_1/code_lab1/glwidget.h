#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
private:
    QString ComboBox_type="GL_POINTS";
public:
    explicit GLWidget(QWidget *parent = nullptr);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private slots:
    void changeShapePicture(QString type);
};

#endif // GLWIDGET_H
