#ifndef _GLDEBUG_H_
    #define _GLDEBUG_H_

#include <gl/gl.h>
#include <gl/glu.h>

class GLDebug {
public:

    static GLfloat lineWidth;

    static GLfloat colors[4];

    static void Init(void);

    //! Draw a line with the system colors
    static void DrawLine(float x1,float y1,float x2, float y2);

    //! Draw a line with the given colors
    static void DrawLine(float x1,float y1,float x2, float y2,GLfloat*);

    //! Draw a point on the screen. Line Width matters here!
    //! \note This will use the currently set colors
    static void DrawPoint(float x1,float y1);

    //! Draw a point on the screen with a specific color. 
    static void DrawPoint(float x1,float y1,GLfloat*);

};

#endif //_GLDEBUG_H_
