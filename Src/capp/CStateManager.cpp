#include "CStateManager.h"
 
// Refer to your Other App States Here
#include "CAppIntro\CAppStateIntro.h"
#include "CAppGame\CAppStateGame.h"
 
CAppState* CStateManager::ActiveAppState = 0;
 
void CStateManager::OnEvent(SDL_Event* EventHolder) {
    if(ActiveAppState) ActiveAppState->OnEvent(EventHolder);
}
 
void CStateManager::OnLoop() {
    if(ActiveAppState) ActiveAppState->OnLoop();
}
 
void CStateManager::OnRenderGL() {
    if(ActiveAppState) ActiveAppState->OnRenderGL();
}
 
void CStateManager::SetActiveAppState(int AppStateID) {
    if(ActiveAppState) ActiveAppState->OnDeactivate();
 
    // Also, add your App State Here so that the Manager can switch to it
    if(AppStateID == APPSTATE_NONE)        ActiveAppState = 0;
    if(AppStateID == APPSTATE_INTRO)    ActiveAppState = CAppStateIntro::GetInstance();
    if(AppStateID == APPSTATE_GAME)        ActiveAppState = CAppStateGame::GetInstance();
 
    if(ActiveAppState) ActiveAppState->OnActivate();
}
 
CAppState* CStateManager::GetActiveAppState() {
    return ActiveAppState;
}