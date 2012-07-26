//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include <stdio.h>

#include "..\entities\CEntity.h"
#include "..\system\controls\CEvent.h"
#include "..\system\map\CSurface.h"
#include "..\entities\CAnimation.h"
#include "..\define.h"
#include "..\system\map\CArea.h"
#include "..\system\controls\CCamera.h"
#include "..\entities\player\CPlayer.h"

//==============================================================================
class CApp : public CEvent {
   private:
      bool  Running;

      CPlayer  Player;
      CPlayer  Player2;

      SDL_Surface*   Surf_Display;

   public:
      CApp();

      int OnExecute();

   public:
      bool OnInit();

      void OnEvent(SDL_Event* Event);

         void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

         void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

         void OnExit();

      void OnLoop();

      void OnRender();

      void OnCleanup();
};

//==============================================================================

#endif