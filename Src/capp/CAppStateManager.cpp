#include "CAppStateManager.h"
 
// Refer to your Other App States Here
#include "CAppIntro\CAppStateIntro.h"
#include "CAppGame\CAppStateGame.h"
 
CAppState* CAppStateManager::ActiveAppState = 0;
 
void CAppStateManager::OnEvent(SDL_Event* EventHolder) {
    if(ActiveAppState) ActiveAppState->OnEvent(EventHolder);
}
 
void CAppStateManager::OnLoop() {
    if(ActiveAppState) ActiveAppState->OnLoop();
}
 
void CAppStateManager::OnRenderGL() {
    if(ActiveAppState) ActiveAppState->OnRenderGL();
}
 
void CAppStateManager::SetActiveAppState(int AppStateID) {
    if(ActiveAppState) ActiveAppState->OnDeactivate();
 
    // Also, add your App State Here so that the Manager can switch to it
    if(AppStateID == APPSTATE_NONE)     ActiveAppState = 0;
    if(AppStateID == APPSTATE_INTRO)    ActiveAppState = CAppStateIntro::GetInstance();
    if(AppStateID == APPSTATE_GAME)     ActiveAppState = CAppStateGame::GetInstance();
 
    if(ActiveAppState) ActiveAppState->OnActivate();
}
 
CAppState* CAppStateManager::GetActiveAppState() {
    return ActiveAppState;
}