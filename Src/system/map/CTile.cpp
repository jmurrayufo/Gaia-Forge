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