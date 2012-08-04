
#include <iostream>
#include <string>
#include <stdio.h>
#include <SDL.h>
#include "capp/CApp.h"

using namespace std;

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    std::cerr << "test" << std::endl;
    std::cerr << __FILE__ << __LINE__ << std::endl << "    GetTextureIterator returned a NULL! This is VERY bad..." << std::endl;

    CApp theApp;
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}
//==============================================================================
