#ifndef _GLDEBUG_H_
    #define _GLDEBUG_H_

#include <gl/gl.h>
#include <gl/glu.h>

class GLDebug {
public:

    GLDebug();
    static GLfloat lineWidth;

    float colors[4];

    static void DrawLine(float x1,float y1,float x2, float y2);

};

#endif //_GLDEBUG_H_
