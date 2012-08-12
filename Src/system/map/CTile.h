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

//Size in pixels of a tile
#define TILE_SIZE 16

enum {
    TILE_TYPE_NONE = 0,
    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};

class CTile {
public:

    short int tileID;

    //! The texture stored in a video management object. 
    VidMem *Texture;

public:
    CTile();
    ~CTile();
    CTile(short TileID, bool Collideable = 1);
    bool Collision();

    /*!
        Clean up any memory associated with this CTile
    */
    void OnCleanup();


    void OnInit();

    /*!
        Render the tile to the given location on the screen. 
    */
    void OnRenderGL(float x, float y);
protected:

    bool collideable;
};

#endif
