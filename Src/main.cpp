
#include <stdio.h>
#include <SDL.h>
#include "capp/CApp.h"


//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;
    printf("%s:%d\n",__FILE__,__LINE__);
    for(int i=0;i<argc;i++)
        printf("%s\n",argv[i]);
    return theApp.OnExecute();
}

//==============================================================================
