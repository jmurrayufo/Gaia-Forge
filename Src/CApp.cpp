//==============================================================================
#include "CApp.h"


//==============================================================================
CApp::CApp() {
    Running = true;
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        fprintf(stderr,"OnInit call failed.\n   %s:%d\n",__FILE__,__LINE__);
        return -1;
    }
    printf("%s:%d\n",__FILE__,__LINE__);

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}


//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;
    printf("%s:%d\n",__FILE__,__LINE__);
    for(int i=0;i<argc;i++)
        printf("%s\n",argv[i]);
    return theApp.OnExecute();
}

//==============================================================================
