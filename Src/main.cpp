
#include <iostream>
#include <string>
#include <SDL.h>

#include "capp/CApp.h"

using namespace std;


//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    std::cout << "Booted Main" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    std::cout.flush();
    CApp theApp;
    return theApp.OnExecute();
}
//==============================================================================