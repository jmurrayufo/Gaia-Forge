//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>
#include <iostream>

#include "..\lib\lodepng.h"

#include "..\entities\CEntity.h"
#include "..\system\controls\CEvent.h"
#include "..\system\graphics\CAnimation.h"
#include "..\define.h"
#include "..\system\controls\CCamera.h"
#include "..\entities\player\CPlayer.h"

//==============================================================================
class CApp : public CEvent {
   private:
      bool  Running;
      std::vector<unsigned char> image;
      unsigned int width,height;
      GLuint texture;         // This is a handle to our texture object

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
