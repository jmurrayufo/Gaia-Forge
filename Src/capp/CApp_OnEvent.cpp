//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
   CEvent::OnEvent(Event);
}

void CApp::OnExit() {
    Running = false;
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
   
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {

}
//==============================================================================
