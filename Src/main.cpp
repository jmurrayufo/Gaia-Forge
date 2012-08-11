
#include <iostream>
#include <string>
#include <SDL.h>

#include "capp/CApp.h"

#include "system/map/CChunk.h"

using namespace std;

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    CChunk x;

    x.X=0;
    x.Y=0;

    x.OnRenderGL(0+1/16.f,2.5,5,5);
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    CApp theApp;
    return theApp.OnExecute();
}
//==============================================================================