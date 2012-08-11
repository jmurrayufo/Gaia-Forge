#include "CTile.h"

CTile::CTile()
{
    tileID = 0;
    collideable = false;
}

CTile::CTile(short TileID, bool Collideable)
{
    tileID = TileID;
    collideable = Collideable;
}


bool CTile::Collision()
{
    return collideable;
}


void CTile::OnRenderGL(float x, float y)
{
    std::cout << "print tile to screen at x y coords";

    //TODO:  write function to draw tile to screen here
    return;
}