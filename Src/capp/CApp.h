//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <gl/gl.h>
#include <gl/glu.h>
#include <iostream>
#include <math.h>
#include <SDL.h>
#include <sstream>
#include <stdio.h>
#include <string>

#include "..\lib\lodepng.h"

#include "..\define.h"
#include "..\entities\CEntity.h"
#include "..\entities\player\CPlayer.h"
#include "..\system\controls\CCamera.h"
#include "..\system\controls\CEvent.h"
#include "..\system\graphics\CAnimation.h"
#include "CAppStateManager.h"

/*!
   Primary class to run all aspect of the game from load to close. 
*/

//==============================================================================
class CApp : public CEvent {
   private:
      bool  Running;

      SDL_Surface*   Surf_Display;

   public:
      CApp();

      int OnExecute();

   public:
      bool OnInit();

      void OnEvent(SDL_Event* Event);

         void OnExit();

      void OnLoop();

      void OnRender();

      void OnCleanup();
};

//==============================================================================

#endif
