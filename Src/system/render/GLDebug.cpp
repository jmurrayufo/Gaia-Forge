//==============================================================================
#include "GLDebug.h"

// Why do we need to reinitialize static members!?
GLfloat GLDebug::lineWidth=5;
GLfloat GLDebug::colors[4];

//==============================================================================




void GLDebug::DrawLine( float x1 , float y1 , float x2 , float y2)
{
    colors[0]=0;
    colors[1]=0;
    colors[2]=1;
    colors[3]=1;
    glDisable(GL_TEXTURE_2D);
    glLineWidth(lineWidth);
    glColor4f(colors[0],colors[1],colors[2],colors[3]);
    glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();

}

//==============================================================================
