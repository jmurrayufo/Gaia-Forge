#include "GLFuncs.h"

void CaptureScreenShot()
{
    using namespace std;
    std::stringstream file; 
    file << "screen-" << SDL_GetTicks() <<".png";
    CaptureScreenShot(file.str().c_str());
}


void CaptureScreenShot(const char* file)
{
    GLubyte *image = (GLubyte*) malloc(WWIDTH * WHEIGHT * 4);
    GLubyte *buffer = (GLubyte*) malloc(WWIDTH * WHEIGHT * 4);
    std::string filename(file);

    glDisable(GL_BLEND);

    glReadPixels(   0,0,
                    WWIDTH,WHEIGHT,
                    GL_RGBA,GL_UNSIGNED_BYTE,
                    buffer
                );

    // Flip the image
    for( int i = 0 ; i < WHEIGHT ; ++i )
    {
        for ( int j = 0; j < WWIDTH; ++j )
        {
            for (int k = 0; k < 4; ++k)
            {
                image[(i*WWIDTH+j)*4+k] = buffer[((WHEIGHT-i-1)*WWIDTH+j)*4+k];
            }
        }
    }
    lodepng::encode(file, image, WWIDTH, WHEIGHT);
    free(image);
    free(buffer);
}
            