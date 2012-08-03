
#include <ostream>
#include <stdio.h>
#include <SDL.h>
#include "capp/CApp.h"
#include "system/graphics/CAnimation.h"

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {

    CAnimation test;
    int x,y;

    test.SetFrameRate(1000);
    test.tiles=6;
    test.cols=2;

    while(1)
    {
        test.OnAnimate();
        test.GetCurrentFrame(x,y);
        std::cout << "Tick:" << SDL_GetTicks() << std::endl;
        std::cout << "x:" << x << " y:" << y << std::endl << std::endl;
        SDL_Delay(500);
    }

    CApp theApp;
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}
//==============================================================================
