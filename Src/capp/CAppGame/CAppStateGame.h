#ifndef _CAPPSTATEGAME_H_
    #define _CAPPSTATEGAME_H_
 
#include <vector>
#include <gl/gl.h>
#include <gl/glu.h>

#include "..\CAppState.h"
 
#include "..\..\entities\CEntity.h"
#include "..\..\entities\player\CPlayer.h"
#include "..\..\system\controls\CCamera.h"
#include "..\..\system\noise\Noise.h"
#include "..\..\system\render\GLDebug.h"
#include "..\..\system\render\GLFuncs.h"
 
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