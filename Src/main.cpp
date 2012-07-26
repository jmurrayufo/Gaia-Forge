
#include <stdio.h>
#include <SDL.h>
#include "capp/CApp.h"


//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;
        fprintf(stderr,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}

//==============================================================================
