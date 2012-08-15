#include "CAppStateIntro.h"
 
#include "..\CAppStateManager.h"
 
CAppStateIntro CAppStateIntro::Instance;
 
CAppStateIntro::CAppStateIntro() {
}
 
void CAppStateIntro::OnActivate() {
    

    x.OnInit();

    unsigned tex_width,tex_height;

    std::vector<unsigned char> image;

    unsigned error = lodepng::decode(image,tex_width,tex_height,"gfx/tiles2x2.png");

    if(error)
    {
        fprintf(stderr,"lodepng::decode error: %s\n",lodepng_error_text(error));
        return;
    }
    glGenTextures( 1, &texture );
    glBindTexture(GL_TEXTURE_2D,(&texture)[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, 4, tex_width, tex_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    image.clear();

    // Load the stencil texture

    error = lodepng::decode(image,tex_width,tex_height,"gfx/StencilTest.png");

    if(error)
    {
        fprintf(stderr,"lodepng::decode error: %s\n",lodepng_error_text(error));
        return;
    }
    glGenTextures( 1, &StencilTex );
    glBindTexture(GL_TEXTURE_2D,(&StencilTex)[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, 4, tex_width, tex_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    image.clear();

    StartTime = SDL_GetTicks();
}
 
void CAppStateIntro::OnDeactivate() {
    glDeleteTextures(1,&texture);
}
 
void CAppStateIntro::OnLoop() {
    if(StartTime + 3000 < SDL_GetTicks()) {
        CAppStateManager::SetActiveAppState(APPSTATE_GAME);
    }
}
 
void CAppStateIntro::OnRenderGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // // Enable use of textures
    glEnable(GL_TEXTURE_2D);
    
    // Disable writing to any of the color fields
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_TRUE);
    glStencilOp(GL_KEEP, GL_KEEP, GL_INCR); 

    glAlphaFunc(GL_GREATER, 0.05);
    glStencilFunc(GL_ALWAYS, 0, 0);
    
    glEnable(GL_STENCIL_TEST);
    glEnable(GL_ALPHA_TEST);

    glBindTexture(GL_TEXTURE_2D,(&StencilTex)[0]);

    // Draw our blocking poly
    glBegin(GL_POLYGON);                                   
        glTexCoord2d( 0, 0 );    glVertex2f( 50,     50 );
        glTexCoord2d( 0, 1 );    glVertex2f( 50,     50+128 );
        glTexCoord2d( 1, 1 );    glVertex2f( 50+128, 50+128 );
        glTexCoord2d( 1, 0 );    glVertex2f( 50+128, 50 );
    glEnd();
    glDisable(GL_ALPHA_TEST);


    // Re enable drawing of colors
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

    glStencilFunc(GL_LESS, 0, -1);

    // Bind desired texture for drawing
    glBindTexture(GL_TEXTURE_2D,(&texture)[0]);

    // Draw the box with colors
    glBegin(GL_QUADS);                                   
        glTexCoord2d( 0, 0 );    glVertex2f( 50,     50 );
        glTexCoord2d( 0, 1 );    glVertex2f( 50,     50+128 );
        glTexCoord2d( 1, 1 );    glVertex2f( 50+128, 50+128 );
        glTexCoord2d( 1, 0 );    glVertex2f( 50+128, 50 );
    glEnd();
    glDisable(GL_STENCIL_TEST);


    // Swap buffers and display!
    SDL_GL_SwapBuffers();
}
 
CAppStateIntro* CAppStateIntro::GetInstance() {
    return &Instance;
}