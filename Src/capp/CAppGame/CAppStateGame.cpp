#include "CAppStateGame.h"
 
CAppStateGame CAppStateGame::Instance;
 
CAppStateGame::CAppStateGame() {
}
 
void CAppStateGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            //Player.MoveLeft = true;
            break;
        }
 
        case SDLK_RIGHT: {
            //Player.MoveRight = true;
            break;
        }
 
        case SDLK_SPACE: {
            //Player.Jump();
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
    // We need to handle all the OnInit stuff from the only CApp_OnInit here!
}
 
void CAppStateGame::OnDeactivate() {
    // Do all the cleanup!
}
 
void CAppStateGame::OnLoop() {
    // Give the entities their loop
    for(int i = 0;i < CEntity::EntityList.size();i++) {
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
    */
 
    //CEntityCol::EntityColList.clear();
}
 
void CAppStateGame::OnRenderGL() {
    //TODO: We need to be able to render in the game state!
}
 
CAppStateGame* CAppStateGame::GetInstance() {
    return &Instance;
}