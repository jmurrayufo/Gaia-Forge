#include "CTile.h"

CTile::CTile()
{
    tileID = 0;
    collideable = false;
}

CTile::CTile(short TileID, bool Collideable = 1)
{
    tileID = TileID;
    collideable = Collideable;
}


CTile::Collision()
{
    return collideable;
}