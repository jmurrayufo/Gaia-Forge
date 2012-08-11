
#include <iostream>
#include <string>
#include <SDL.h>

#include "capp/CApp.h"

#include "system/map/CChunk.h"

using namespace std;

// 1000 Crash
// 500 Pass
// 750 Crash
// 625 Pass
// 688 Pass
// 719 Pass
// 735 Crash
// 727 Crash
// 723 Crash
// 721 Pass
// 722 Crash
#define DIM 722

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    CChunk x;
    int y[DIM][DIM];

    x.X=0;
    x.Y=0;

    x.OnRenderGL(0+1/16.f,2.5,5,5);
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    CApp theApp;
    return theApp.OnExecute();
}
//==============================================================================