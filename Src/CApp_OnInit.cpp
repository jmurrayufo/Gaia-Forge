//==============================================================================
#include "CApp.h"
#include <stdio.h>

//==============================================================================
bool CApp::OnInit() {
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      return false;
   }

   if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
      return false;
   }

   if(CArea::AreaControl.OnLoad("./maps/1.area") == false) {
    return false;
   }

   SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

   if(Player.OnLoad("./gfx/yoshi.png", 64, 64, 8) == false) {
      return false;
   }

   if(Player2.OnLoad("./gfx/yoshi.png", 64, 64, 8) == false) {
      return false;
   }

   Player.X = 100;

   CEntity::EntityList.push_back(&Player);
   CEntity::EntityList.push_back(&Player2);

   CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
   CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);

   return true;
}

//==============================================================================
