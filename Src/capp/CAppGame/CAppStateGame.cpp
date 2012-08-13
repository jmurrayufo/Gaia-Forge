#include "CAppStateGame.h"
 
CAppStateGame CAppStateGame::Instance;
 
CAppStateGame::CAppStateGame() {
}
 
void CAppStateGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            offset-=1;
            //Player.MoveLeft = true;
            break;
        }
 
        case SDLK_RIGHT: {
            offset+=1;
            //Player.MoveRight = true;
            break;
        }
 
        case SDLK_SPACE: {
            //Player.Jump();
            CaptureScreenShot();
            break;
        }
 
        default: {
        }
    }
}
 
void CAppStateGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            //Player.MoveLeft = false;
            break;
        }
 
        case SDLK_RIGHT: {
            //Player.MoveRight = false;
            break;
        }
 
        default: {
        }
    }
}
 
void CAppStateGame::OnActivate() {
     // Add some test entities 
    offset=0;
    for (int i = 0; i < 2; i++)
    {
        CEntity *mule = new CEntity;
        mule->X=i*64+300;
        mule->Y=300;

        CEntity::EntityList.push_back(mule);
    }

    // Load a file into the test entities
    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        std::vector<CEntity*>::iterator CurrentEnt=CEntity::EntityList.begin()+i;

        if(!CEntity::EntityList[i]) 
            continue;
        if(CEntity::EntityList[i]->OnLoadGL("gfx\\yoshi.png")==false)
        {
            fprintf(stderr,"%s:%d\n    Failed to OnLoadGL(char) for i=%d\n",__FILE__,__LINE__,i);
            CEntity::EntityList.erase(CurrentEnt);
            i--;
        }
    }
}
 
void CAppStateGame::OnDeactivate() {
   //--------------------------------------------------------------------------
   // Entities
   //--------------------------------------------------------------------------
   for(unsigned int i = 0;i < CEntity::EntityList.size();i++)
   {
      if(!CEntity::EntityList[i]) continue;

      CEntity::EntityList[i]->OnCleanup();
   }

   CEntity::EntityList.clear();
}
 
void CAppStateGame::OnLoop() {
    // Give the entities their loop
    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }
   //Collision Events
   /*
    for(int i = 0;i < CEntityCol::EntityColList.size();i++) {
        CEntity* EntityA = CEntityCol::EntityColList[i].EntityA;
        CEntity* EntityB = CEntityCol::EntityColList[i].EntityB;

        if(EntityA == NULL || EntityB == NULL) continue;

        if(EntityA->OnCollision(EntityB)) {
         EntityB->OnCollision(EntityA);
        }
    }

    CEntityCol::EntityColList.clear();
    */
}
 
void CAppStateGame::OnRenderGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) 
    {
        if(!CEntity::EntityList[i]) 
            continue;

        CEntity::EntityList[i]->OnRenderGL();
    }


    SDL_GL_SwapBuffers();
    //SDL_Delay(1000/60);
}
 
CAppStateGame* CAppStateGame::GetInstance() {
    return &Instance;
}