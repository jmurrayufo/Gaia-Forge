//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {
   SDL_FillRect(Surf_Display,NULL,0);
   CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
   for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
      if(!CEntity::EntityList[i]) continue;

      CEntity::EntityList[i]->OnRender(Surf_Display);
   }
   SDL_Flip(Surf_Display);
}

//==============================================================================
