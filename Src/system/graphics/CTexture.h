#ifndef _CTEXTURE_STATE_H_
    #define _CTEXTURE_STATE_H_

#include <vector>
#include <map>
#include <string>
#include <stdio.h>  // Needed for debuggin

#include "VidMem.h"
#include "CAnimation.h"

/*! \brief Possible states for an entity to be in
*/
enum {
    CTEXTURE_STATE_BASE,
    CTEXTURE_STATE_ATTACKING,
    CTEXTURE_STATE_BREAKING,
    CTEXTURE_STATE_DANCING,
    CTEXTURE_STATE_DIEING,
    CTEXTURE_STATE_JUMPING,
    CTEXTURE_STATE_MOVING,
    CTEXTURE_STATE_STANDING,
    CTEXTURE_STATE_TALKING
};


//! Unimplemented 
struct Pointer_group {
    VidMem*     VidMemTexture;
    CAnimation* Animation;
}Pointer_group;

/*! \brief Maintain the current associated texture. 

This could be an anything drawn from an image file. CTexture holds and manages the texture
    for a parent object. The texture may or may not use animations.
*/
class CTexture
{
public:

    //TODO: Decide how we are going to manage these...
    //! Associated video memory texture
    VidMem *vidMemTexture;

    //! Map of the associated states and textures
    std::map<int,VidMem*> vidTextureMap;

    //! Map of the associated states and animations
    std::map<int,CAnimation*> animationMap;

    //! What heading does the creature have?
    //! \note This has differnet meanings depending on the value in laterialTexture. If 
    //!     true, this will function as a boolean value. True will flip a texture, false 
    //!     will leave the texture facing the normal way. When laterialTexture is false,
    //!     facing will set the literal facing of an object in degrees. 
    int facing;

    //! Will this creature always face left/right?
    bool laterialTexture;

    //! Track the current state of the object. 
    int state;


public:
    CTexture();
    ~CTexture();

    bool OnLoad(const char* File);

    bool OnLoad(std::string File);

    void OnLoop(void);

    void OnLoop(int speed);

    void OnRenderGL(void);

    void OnCleanup(void);

    bool GetHasState(void);



    int GetState(void);

    GLuint GetTexture();

    bool SetState(int state);

    /*! Configure a given state for the CTexture
    \param[in] state    Set the type of state we are going to use
    \param[in] x        Top left corner pixel to use for this state
    \param[in] y        Top left corner pixel to use for this state
    \param[in] tiles    (optional) Number of tiles in the animation
    \param[in] cols     (optional) Number of columns for the animation
    \param[in] oscillation  (optional) Does this animation repeat back to front?
    */
    bool ConfigState(   int state,
                        int x,
                        int y,
                        int tiles=1,
                        bool oscillation=false,
                        int cols=1);

};

#endif //_CTEXTURE_STATE_H_
