#ifndef _CAPPSTATE_H_
    #define _CAPPSTATE_H_
 
#include "..\system\controls\CEvent.h"

/*!
    \brief Pure virtual class to template out game states. 

    All game states MUST implement these functions. This class is empty otherwise
*/
 
class CAppState : public CEvent {
    public:
        CAppState();
 
    public:
        virtual void OnActivate() = 0;
 
        virtual void OnDeactivate() = 0;
 
        virtual void OnLoop() = 0;
 
        virtual void OnRenderGL() = 0;
};
 
#endif