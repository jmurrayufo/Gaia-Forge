//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr,"%s:%d\n    SDL_Init call failed.\n",__FILE__,__LINE__);
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        fprintf(stderr,"%s:%d\n    SDL_SetVideoMode call failed.\n",__FILE__,__LINE__);
        return false;
    }
    for (int i = 0; i < 5; i++)
    {
        CEntity *mule = new CEntity;
        mule->X=i*128;
        mule->Y=i*128;

        CEntity::EntityList.push_back(mule);
    }

    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        std::vector<CEntity*>::iterator CurrentEnt=CEntity::EntityList.begin()+i;

        if(!CEntity::EntityList[i]) continue;
        if(CEntity::EntityList[i]->OnLoadGL("gfx\\yoshi.png")==false)
        {
            fprintf(stderr,"%s:%d\n    Failed to OnLoadGL(char) for i=%d\n",__FILE__,__LINE__,i);
            CEntity::EntityList.erase(CurrentEnt);
            i--;
        }

    }
    // fprintf(stdout,"CApp::OnInit success! Got %d elements loaded!\n",CEntity::EntityList.size()); //DEBUG code!

    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);

    glViewport(0, 0, WWIDTH, WHEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, WWIDTH, WHEIGHT, 0, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_TEXTURE_2D);

    glLoadIdentity();

    return true;
}

//==============================================================================

    // These options were suggested to use for SDL_GL stuff. Not sure if we need it?
    /*
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);
 
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,            32);
 
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);
    */