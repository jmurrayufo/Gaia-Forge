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
        if(CEntity::EntityList[i]->OnLoadGL("gfx\\yoshi2.png")==false)
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
        break; // SKIP THIS LOOP    
        //GLDebug::DrawPoint(i+0.5,x.Perlin1d(i + SDL_GetTicks()/20.f) + WHEIGHT/2-16);
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
    g.Seed = 0;
    g.InterpType = NOISE_INTERP_LINEAR;

    x.Amplitude = WHEIGHT/2;  
    float colors[4]={1,0,0,1};
    int boxSize=16;
    for (int i = 0; i < WWIDTH/boxSize; ++i)
    {
        for (int j = 0; j < WHEIGHT/boxSize; ++j)
        {
            if( x.Perlin1d( i + offset ) + WHEIGHT / 2 > j * boxSize )
                continue;
            colors[0]=g.Perlin2d( (i + offset) * boxSize, j * boxSize ) + 0.5;
            /*
            if(colors[0] > 0.5)
                colors[0]=1;
            else
                colors[0]=0;
            */
            colors[3]=colors[2]=colors[1]=colors[0];
            DrawBox( i * boxSize, j * boxSize, boxSize, boxSize, colors);
        }
    }

    SDL_GL_SwapBuffers();
    //SDL_Delay(1000/60);
}
 
CAppStateGame* CAppStateGame::GetInstance() {
    return &Instance;
}