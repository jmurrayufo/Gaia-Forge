#ifndef _CSTATEMANAGER_H_
    #define _CSTATEMANAGER_H_

#include "CAppState.h"

enum {
// Add your Other App States Here
    APPSTATE_NONE,
    APPSTATE_INTRO,
    APPSTATE_GAME,
    APPSTATE_DEBUG
};

class CStateManager {
private:
    static CAppState* ActiveAppState;

public:
    static void OnEvent(SDL_Event* Event);

    static void OnLoop();

    static void OnRenderGL();

public:
    static void SetActiveAppState(int AppStateID);

    static CAppState* GetActiveAppState();
};

#endif //_CSTATEMANAGER_H_