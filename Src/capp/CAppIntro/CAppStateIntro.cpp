#include "CAppStateIntro.h"
 
#include "..\CAppStateManager.h"
 
CAppStateIntro CAppStateIntro::Instance;
 
CAppStateIntro::CAppStateIntro() {
    Surf_Logo = NULL;
}
 
void CAppStateIntro::OnActivate() {
    // Load Simple Logo
    // TODO: Get the logo working!
 
    StartTime = SDL_GetTicks();
}
 
void CAppStateIntro::OnDeactivate() {
    // Cleanup for a new state!
}
 
void CAppStateIntro::OnLoop() {
    if(StartTime + 3000 < SDL_GetTicks()) {
        CAppStateManager::SetActiveAppState(APPSTATE_GAME);
    }
}
 
void CAppStateIntro::OnRenderGL() {
    // Render the intro screen!
}
 
CAppStateIntro* CAppStateIntro::GetInstance() {
    return &Instance;
}