
#include <stdio.h>
#include <SDL.h>
#include "capp/CApp.h"
#include "entities/CTexture.h"

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    CTexture x;

    x.InitTexture("Hello");
    x.InitTexture("World!");
    x.InitTexture("World!");
    x.InitTexture("World!");
    x.InitTexture("World!");

    for (std::vector<CTexture*>::iterator i = CTexture::textureList.begin(); i != CTexture::textureList.end(); ++i)
    {
        fprintf(stdout,"textureFile: %s\n",(*i)->textureFile.c_str());
        fprintf(stdout,"count: %d\n",(*i)->count);
    }

    return 0;

    CApp theApp;
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}
//==============================================================================
