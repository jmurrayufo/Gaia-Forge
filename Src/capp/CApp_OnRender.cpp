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

    for (int i = 0; i < WWIDTH; ++i)
    {
        float y=0;
        y=sin((float)i/10.f+SDL_GetTicks()/1000.f) * 50.f + WHEIGHT / 2.f;
        GLDebug::DrawPoint(i , y);
    }

    
    SDL_GL_SwapBuffers();
    //SDL_Delay(1000/60);
}

//==============================================================================
