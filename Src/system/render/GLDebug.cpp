//==============================================================================
#include "GLDebug.h"

// Why do we need to reinitialize static members!?
GLfloat GLDebug::lineWidth = 1;

//==============================================================================
void GLDebug::DrawLine( float x1 , float y1 , float x2 , float y2)
{

    glLineWidth(5);
    glDisable(GL_BLEND);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);

    glEnd();

}

//==============================================================================
