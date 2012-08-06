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
    x.Amplitude = 80;
    x.Octaves = 6;
    x.Persistance = 2;
    x.InterpType = NOISE_INTERP_CUBIC;
    for (int i = 0; i < WWIDTH; ++i)
    {
        GLDebug::DrawPoint(i+0.01,x.Perlin1d(i + SDL_GetTicks()/20.f) + WHEIGHT/2);
    }

    SDL_GL_SwapBuffers();
    SDL_Delay(1000/60);
}

//==============================================================================
