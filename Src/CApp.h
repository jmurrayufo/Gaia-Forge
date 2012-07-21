//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>

#include "CEntity.h"
#include "CEvent.h"
#include "CSurface.h"
#include "CAnimation.h"
#include "Define.h"
#include "CArea.h"
#include "CCamera.h"
#include "CPlayer.h"

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
