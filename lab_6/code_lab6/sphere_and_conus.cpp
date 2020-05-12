#include "sphere_and_conus.h"

Sphere_and_conus::Sphere_and_conus():sectorCount(40),stackCount(40),center({1.5f,1.5f,1.5f}),rad_sphere(1),res_conus(10),rad_conus(2.5)
{
    initSpherePoints();
    initConusPoints();
}

void Sphere_and_conus::drawObj(QOpenGLShaderProgram *m_program, GLenum type)
{
    glPolygonMode(GL_FRONT_AND_BACK,type);
    drawSphere(m_program);
    drawConus(m_program);
}

void Sphere_and_conus::setSphereResX(int res)
{
    sectorCount=res;
    initSpherePoints();
}

void Sphere_and_conus::setSphereResY(int res)
{
    stackCount=res;
    initSpherePoints();
}

void Sphere_and_conus::setConusRes(int res)
{
    res_conus=res;
    initConusPoints();
}

void Sphere_and_conus::initSpherePoints()
{
    sphere_points.clear();
    sphere_normals.clear();
    indices.clear();
    float x, y, z, xy;                              // vertex position

    float sectorStep = 2 * M_PI / sectorCount;
    float stackStep = M_PI / stackCount;
    float sectorAngle, stackAngle;

    for(uint i = 0; i <= stackCount; ++i)
    {
        stackAngle = M_PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = rad_sphere * cosf(stackAngle);             // r * cos(u)
        z = rad_sphere * sinf(stackAngle);              // r * sin(u)

        // add (sectorCount+1) vertices per stack
        // the first and last vertices have same position and normal, but different tex coords
        for(uint j = 0; j <= sectorCount; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            sphere_points.append(center+QVector3D{x,y,z});
            sphere_normals.append(QVector3D{x,y,z});
        }
    }

    int k1, k2;
    for(uint i = 0; i < stackCount; ++i)
    {
        k1 = i * (sectorCount + 1);
        k2 = k1 + sectorCount + 1;

        for(uint j = 0; j < sectorCount; ++j, ++k1, ++k2)
        {

            if(i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (stackCount-1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }
}

void Sphere_and_conus::initConusPoints()
{
    conus_points.clear();
    float step=2*M_PI/res_conus;

    conus_points.append(QVector3D(0.0f,3.5f,0.0f));
    for(float i=0.0f;i<=M_PI*2;i+=step){
        conus_points.append(QVector3D(rad_conus*cosf(i),0.0f,rad_conus*sinf(i)));
    }
    conus_points.append(conus_points[1]);
    conus_normals=conus_points;
}

void Sphere_and_conus::drawSphere(QOpenGLShaderProgram *m_program)
{
    initializeOpenGLFunctions();

    m_program->bind();

    m_program->setAttributeArray(0, sphere_points.data());
    m_program->setAttributeArray(2,sphere_normals.data());
    m_program->setAttributeValue("colorAttr",{0.1f,0.8f,0.1f,0.1f});

    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(2);

    glFrontFace(GL_CW);
    glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,indices.data());

    m_program->disableAttributeArray( 0);
    m_program->disableAttributeArray(2);
    m_program->release();
}

void Sphere_and_conus::drawConus(QOpenGLShaderProgram *m_program)
{
    initializeOpenGLFunctions();

    m_program->bind();

    m_program->setAttributeArray(0, conus_points.data());
    m_program->setAttributeArray(2,conus_normals.data());
    m_program->setAttributeValue("colorAttr",{0.1f,0.8f,0.1f,0.1f});



    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(2);

    glFrontFace(GL_CW);

    glDrawArrays(GL_POLYGON ,1,conus_points.size()-1);
    glFrontFace(GL_CCW);
    glDrawArrays(GL_TRIANGLE_FAN ,0,conus_points.size());

    m_program->disableAttributeArray( 0);
    m_program->disableAttributeArray(2);
    m_program->release();
}

QVector3D Sphere_and_conus::SphereFun(float u, float v)
{
    return {rad_sphere*sinf(u)*sinf(v),rad_sphere*sinf(u)*cosf(v),rad_sphere*cosf(v)};
}
