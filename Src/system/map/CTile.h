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

// TODO: Document the tileset standard. 
/*
    We can use tileID as a way to find the location of the tile within a tileset store 
    into the vidmem object. We know how big the texture is, so we divide that into a grid 
    and access it with the tileID. 

    EG: 
        The texture is 64x64 pixels big. 
        We are at tileID = 4
        x = tileID * TILE_SIZE
        x = 64
        On nose! We have gone over our limit!
        We must adjust this by the grid we have. x=64 is on pixel off the edge!

        Lets try that again

        x = (tileID * TILE_SIZE) % 64
        x == 0

        Good, we know that the 4th texture is on the left side. Now lets find its row

        y = (tileID * TILE_SIZE) / 64 //intiger math plz!
        y *= 16
        y == 16
        
    This syste, only works if tileIDs map directly to their graphics. We might want to 
    have a converter to help with this as well. 

*/

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

    /*! 
        \brief The texture stored in a video management object. 
    */
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
