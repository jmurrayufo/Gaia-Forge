#ifndef _CTILE_H_
    #define _CTILE_H_

#include <iostream>
#include <gl/gl.h>
#include <gl/glu.h> 
#include <assert.h>
#include <SDL.h>

#include "..\..\Define.h"
#include "..\graphics\VidMem.h"

//Tiles are defined as Square

// FIXME: Defines are global, we should use the class name as the first word in the define (CTILE_TILE_SIZE here)
//! Size in pixels of a tile
#define TILE_SIZE 16

enum {
    TILE_TYPE_NONE = 0,
    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};

class CTile {
public:
    // FIXME: member variables should be in CAPS!!!
    short int tileID;

    //! The texture stored in a video management object. 
    VidMem *Texture;
protected:

    bool collideable;
public:
    CTile();
    ~CTile();

    // TODO: Document function
    CTile(short TileID, bool Collideable = 1);
    
    /*!
        Clean up any memory associated with this CTile
    */
    void OnCleanup();

    void OnInit();


    /*!
        Get the collision value of the tile
    */
    bool Collision();

    /*! 
        Set the collide flag of tile
    */
    void SetCollision(bool Collision);

    /*!
        Render the tile to the given location on the screen. 
    */
    void OnRenderGL(float x, float y);
};

#endif
