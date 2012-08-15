#ifndef _CAPPSTATEINTRO_H_
    #define _CAPPSTATEINTRO_H_

#include <vector>
#include <gl/gl.h>
#include <gl/glu.h> 
#include <iostream>

#include "../../lib/lodepng.h"
#include "../../system/map/CTile.h"
#include "../CAppState.h"
 
class CAppStateIntro : public CAppState {
    private:
        static CAppStateIntro Instance;

        GLuint texture;
        GLuint StencilTex;

        CTile x; // DEBUG
 
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