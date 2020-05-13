#ifndef SPHERE_AND_CONUS_H
#define SPHERE_AND_CONUS_H

#include <QVector>
#include <QVector3D>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QtMath>
#include <QOpenGLShaderProgram>


class Sphere_and_conus:protected QOpenGLFunctions
{
public:
    Sphere_and_conus();

    void drawObj(QOpenGLShaderProgram* m_program, GLenum type);
    void setSphereResX(int res);
    void setSphereResY(int res);

    void setConusRes(int res);

private:
    QVector<QVector3D> sphere_points;
    QVector<uint> indices;
    QVector<QVector3D> sphere_normals;
    QVector3D center;
    uint stackCount, sectorCount;
    uint rad_sphere;

    QVector<QVector3D> conus_points;
    QVector<QVector3D> conus_normals;
    uint res_conus;
    float rad_conus;

    void initSpherePoints();
    void initConusPoints();

    void drawSphere(QOpenGLShaderProgram* m_program);
    void drawConus(QOpenGLShaderProgram* m_program);
    QVector3D SphereFun(float u, float v);
};

#endif // SPHERE_AND_CONUS_H
