//==============================================================================
#include "GLDebug.h"

// Why do we need to reinitialize static members!?
GLfloat GLDebug::lineWidth=5;
GLfloat GLDebug::colors[4];

//==============================================================================

void GLDebug::Init()
{
    lineWidth=1;

    for (int i = 0; i < 4; ++i)
    {
        colors[i]=1;
    }

}

void GLDebug::DrawLine( float x1 , float y1 , float x2 , float y2)
{
    GLDebug::DrawLine(x1,y1,x2, y2,colors);
}


void GLDebug::DrawLine(float x1,float y1,float x2, float y2,GLfloat *funcColors)
{
    glDisable(GL_TEXTURE_2D);
    glLineWidth(lineWidth);
    glColor4f(funcColors[0],funcColors[1],funcColors[2],funcColors[3]);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
}

void GLDebug::DrawPoint(float x1,float y1)
{
    GLDebug::DrawPoint(x1,y1,colors);
}

 
void GLDebug::DrawPoint(float x1,float y1,GLfloat* funcColors)
{
    glDisable(GL_TEXTURE_2D);
    glColor4f(funcColors[0],funcColors[1],funcColors[2],funcColors[3]);
    glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
    glPointSize(lineWidth);
    glBegin(GL_POINTS);
        glVertex2f(x1, y1);
    glEnd();
}
//==============================================================================
