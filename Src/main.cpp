
#include <stdio.h>
#include <SDL.h>
#include "capp/CApp.h"

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {

    CApp theApp;
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}
//==============================================================================
