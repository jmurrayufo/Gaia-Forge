//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() 
{
    GLenum Error;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*
    glLoadIdentity();
 
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
        glColor3f(1, 1, 0); glVertex3f(100, 0, 0);
        glColor3f(1, 0, 1); glVertex3f(100, 100, 0);
        glColor3f(1, 1, 1); glVertex3f(0, 100, 0);
    glEnd();
    */

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
    //glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
    if(Error=glGetError())
        fprintf(stderr,"Error: %d\n",glGetError());

    glBegin(GL_QUADS);
        glTexCoord2d(    0, 0);         glVertex2f(   100,100);
        glTexCoord2d(width, 0);         glVertex2f(width+100,100);
        glTexCoord2d(width, height);    glVertex2f(width+100,height+100);
        glTexCoord2d(    0, height);    glVertex2f(   100,height+100);
    glEnd();
    
    SDL_GL_SwapBuffers();
    if(Error=glGetError())
        fprintf(stderr,"Error: %d\n",glGetError());
    SDL_Delay(1000/60);
}

//==============================================================================
