//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {

        if(!CEntity::EntityList[i]) 
            continue;

        CEntity::EntityList[i]->OnRenderGL();
    }

    // Lets do a Sin wave test!
    Noise x;
    x.Period = 100;
    x.Amplitude = WHEIGHT/10;  
    x.Octaves = 6;
    x.Persistance = 2;
    x.Seed = 0;
    GLDebug::lineWidth = 1;
    x.InterpType = NOISE_INTERP_LINEAR;
    for (int i = 0; i < WWIDTH; ++i)
    {
        GLDebug::DrawPoint(i+0.5,x.Perlin1d(i + SDL_GetTicks()/20.f) + WHEIGHT/2);
        /*
        GLDebug::DrawPoint(i+0.5,sin(i/10.0 + SDL_GetTicks()/1000.f)*50 + WHEIGHT/2 + 0.5);
        GLDebug::DrawLine(  i,
                            sin(i/10.0 + SDL_GetTicks()/1000.f)*50 + WHEIGHT/3 + 0.5,  
                            i+1,
                            sin(i/10.0 + SDL_GetTicks()/1000.f)*50 + WHEIGHT/3 + 0.5
                            );
        */
    }


    SDL_GL_SwapBuffers();
    //SDL_Delay(1000/60);
}

//==============================================================================
