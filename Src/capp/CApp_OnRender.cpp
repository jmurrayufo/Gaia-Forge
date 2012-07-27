//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D,(&texture)[0]);

    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {

        if(!CEntity::EntityList[i]) 
            continue;

        CEntity::EntityList[i]->OnRenderGL();
   }


    
    SDL_GL_SwapBuffers();
    //SDL_Delay(1000/60);
}

//==============================================================================
