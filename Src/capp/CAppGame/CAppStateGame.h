#ifndef _CAPPSTATEGAME_H_
    #define _CAPPSTATEGAME_H_
 
#include "..\CAppState.h"
 
#include "..\..\system\controls\CCamera.h"
#include "..\..\entities\CEntity.h"
 
#include "..\..\entities\CPlayer\CPlayer.h"
 
class CAppStateGame : public CAppState {
    private:
        static CAppStateGame Instance;
 
        CPlayer    Player;
        CPlayer    Player2;
 
    private:
        CAppStateGame();
 
    public:
        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
 
        void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
 
    public:
        void OnActivate();
 
        void OnDeactivate();
 
        void OnLoop();
 
        void OnRenderGL();
 
    public:
        static CAppStateGame* GetInstance();
};
 
#endif