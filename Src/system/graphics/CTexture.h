#ifndef _CTEXTURE_STATE_H_
    #define _CTEXTURE_STATE_H_

#include <vector>
#include <map>
#include <string>
#include <stdio.h>  // Needed for debuggin
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

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

enum {
    CTEXTURE_FILE_TYPE_PNG,
    CTEXTURE_FILE_TYPE_JSON,
    CTEXTURE_FILE_TYPE_INVALID
};

/*! \brief Maintain the current associated texture. 

This could be an anything drawn from an image file. CTexture holds and manages the texture
    for a parent object. The texture may or may not use animations.
*/
class CTexture
{
public:

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

    /*! 
        \brief Load a complete texture file from a JSON texture information file or just a PNG.
    */
    bool OnLoad(const char* File);

    /*! 
        \brief Load a complete texture file from a JSON texture information file or just a PNG.
    */
    bool OnLoad(std::string File);

    /*!
        \brief Advance the animation frame forward if needed. 

        \note Speed is assumed to be 1
    */
    void OnLoop(void);

    /*!
        \brief Advance the animation frame forward if needed. 
    */
    void OnLoop(int speed);

    /*!
        \brief Render to a given screen location
    */
    void OnRenderGL(int x, int y);

    /*!
        \brief Clean out all memory and return to a freshly initialized 
    */
    void OnCleanup(void);

    /*!
        \brief Check if this CTexture needs to be put into states. Some might not!
    */
    bool GetHasState(void);

    /*!
        \brief Get the current state of the CTexture object. 
    */
    int GetState(void);

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
private:
    int DetermineFileType(const char* File);

    bool LoadFromJson(const char* File);
};

#endif //_CTEXTURE_STATE_H_
