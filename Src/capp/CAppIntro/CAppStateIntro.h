#ifndef _CAPPSTATEINTRO_H_
    #define _CAPPSTATEINTRO_H_
 
#include "CAppState.h"
 
class CAppStateIntro : public CAppState {
    private:
        static CAppStateIntro Instance;
 
        int StartTime;
 
    private:
        CAppStateIntro();
 
    public:
        void OnActivate();
 
        void OnDeactivate();
 
        void OnLoop();
 
        void OnRenderGL();
 
    public:
        static CAppStateIntro* GetInstance();
};
 
#endif //_CAPPSTATEINTRO_H_