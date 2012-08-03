#ifndef _CTEXTURE_STATE_H_
    #define _CTEXTURE_STATE_H_

#include <vector>
#include <map>
#include <string>
#include <stdio.h>  // Needed for debuggin

#include "VidMem.h"

/*! \brief Possible states for an entity to be in
*/
enum {
    TEXTURE_STATE_BASE,
    TEXTURE_STATE_ATTACKING,
    TEXTURE_STATE_BREAKING,
    TEXTURE_STATE_DANCING,
    TEXTURE_STATE_DIEING,
    TEXTURE_STATE_JUMPING,
    TEXTURE_STATE_MOVING,
    TEXTURE_STATE_STANDING,
    TEXTURE_STATE_TALKING
};

/*! \brief Maintain the current associated texture. 

This could be an anything drawn from an image file. CTexture holds and manages the texture
    for a parent object. 
*/
class CTexture
{
public:

    //! Associated video memory texture
    VidMem *vidMemTexture;

    //! Map of the associated states and textures
    std::map<int,VidMem*> vidTextureMap;

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

    void OnRenderGL(void);

    void OnCleanup(void);

    bool SetState(int state);

    int GetState(void);

    /*! Configure a given state for the CTexture
    \param[in] state    Set the type of state we are going to use
    \param[in] x        Top left corner pixel to use for this state
    \param[in] y        Top left corner pixel to use for this state
    \param[in] width    Width of each tile
    \param[in] height   Height of each tile
    \param[in] tiles    (optional) Number of tiles in the animation
    \param[in] cols     (optional) Number of columns for the animation
    \param[in] oscillation  (optional) Does this animation repeat back to front?
    */
    bool ConfigState(int state,int x,int y,int width,int height,int tiles=1,int cols=1,bool oscillation=false);

};

#endif //_CTEXTURE_STATE_H_
