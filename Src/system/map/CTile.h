#ifndef _CTILE_H_
#define _CTILE_H_

#include "..\..\Define.h"

enum {
    TILE_TYPE_NONE = 0,

    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK,
};

class CTile {
public:

    short int tileID;

public:
    CTile();
    CTile(short TileID, bool Collideable = 1);
    bool Collision();

    /*
        Render the tile to the given location on the screen. 
    */
    void OnRenderGL(float x, float y);
protected:

    bool collideable;
};

#endif
