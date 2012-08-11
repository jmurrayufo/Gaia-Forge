
#include <iostream>
#include <string>
#include <SDL.h>

#include "capp/CApp.h"

#include "system/map/CMap.h"

using namespace std;


//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    std::cerr << "Booted Main" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    std::cerr.flush();
    CApp theApp;
    return theApp.OnExecute();
}
//==============================================================================