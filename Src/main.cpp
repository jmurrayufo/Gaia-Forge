
#include <stdio.h>
#include <SDL.h>
#include "capp/CApp.h"
#include "entities/CTexture.h"

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    CTexture x;
    CTexture* y;
    std::vector<CTexture*>::iterator *tmp;


    y=x.InitTexture("Hello");
    x.InitTexture("Hello");
    x.InitTexture("World!");

    fprintf(stdout,"%s:%d\n    y->count=%d\n",__FILE__,__LINE__,y->count);

    //Lets jump through ALL of them!
    for (std::vector<CTexture*>::iterator i = CTexture::textureList.begin(); i != CTexture::textureList.end(); ++i)
    {
        fprintf(stdout,"textureFile: %s\n",(*i)->textureFile.c_str());
        fprintf(stdout,"count: %d\n",(*i)->count);
    }

    // Try to delete one!
    fprintf(stdout, "Try to delete y!!!\n");
    if(y->DeleteTexture())
        fprintf(stdout,"We deleted it!\n");
    else
        fprintf(stdout,"It still exists...\n");

    // Try to delete one!
    fprintf(stdout, "Try to delete y!!!\n");
    if(y->DeleteTexture())
        fprintf(stdout,"We deleted it!\n");
    else
        fprintf(stdout,"It still exists...\n");

    //Lets jump through ALL of them!
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
