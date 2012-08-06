#ifndef _CBUFFER_H_
    #define _CBUFFER_H_

#include <gl/gl.h>
#include <gl/glu.h>

struct Buf_GL_POINTS_struct 
{
    float x1;
    float y1;
    GLfloat color[4];
}Buf_GL_POINTS_struct;

struct Buf_GL_LINES_struct 
{
    float x1;
    float y1;
    float x2;
    float y2;
    GLfloat color[4];
}Buf_GL_LINES_struct;

// Sprite class to be done...

class CBuffer {
private:
    static std::vector<Buf_GL_POINTS_struct> Buf_GL_POINTS;
    static std::vector<Buf_GL_LINES_struct> Buf_GL_LINES;
public:
    void BufferPoint(float,float,GLfloat*);
    void BufferLine(float,float,float,float,GLfloat*);
};

#endif //_CBUFFER_H_
