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
        break;
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
    Noise g;
    g.Period = 100;
    g.Amplitude = 0.5;  
    g.Octaves = 1;
    g.Persistance = 2;
    g.Seed = SDL_GetTicks()/1000;
    g.InterpType = NOISE_INTERP_LINEAR;

    x.Amplitude = WHEIGHT/2;  
    float offset = SDL_GetTicks()/20.f;
    float colors[4]={1,0,0,1};
    for (int i = 0; i < WWIDTH/16; ++i)
    {
        for (int j = 0; j < WHEIGHT/16; ++j)
        {
            if( x.Perlin1d(i + offset ) + WHEIGHT/2 > j*16 )
                continue;
            colors[0]=g.Perlin2d(i*16 + offset*16,j*16)+0.5;
            DrawBox(i*16,j*16,16,16,colors);
        }
    }


    SDL_GL_SwapBuffers();
    //SDL_Delay(1000/60);
}

//==============================================================================
