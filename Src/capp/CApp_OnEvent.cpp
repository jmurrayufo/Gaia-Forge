//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
   CEvent::OnEvent(Event);
}

void CApp::OnExit() {
    Running = false;
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
   switch(sym) {
        case SDLK_SPACE:
            std::cout << "Got space!" << std::endl;
            GLubyte *image = (GLubyte*) malloc(WWIDTH * WHEIGHT * 4);
            std::stringstream tmp;
            std::string filename;

            glDisable(GL_BLEND);

            glReadPixels(   0,0,
                            WWIDTH,WHEIGHT,
                            GL_RGBA,GL_UNSIGNED_BYTE,
                            image);

            tmp << "screen_" << SDL_GetTicks() << ".png";

            tmp >> filename;

            lodepng::encode(filename, image, WWIDTH, WHEIGHT);
            free(image);
            break;
    }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {

}
//==============================================================================
