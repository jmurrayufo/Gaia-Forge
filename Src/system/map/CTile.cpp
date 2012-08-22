#include "CTile.h"

CTile::CTile()
{
    Texture=NULL;
    tileID = 0;
    collideable = false;
}

CTile::~CTile()
{
    OnCleanup();
}

CTile::CTile(short TileID, bool Collideable)
{
    tileID = TileID;
    collideable = Collideable;
}

void CTile::OnInit()
{
    VidMem::InitTexture(Texture,"gfx/tiles2x2.png");
}

void CTile::OnCleanup()
{
    //Texture->DeleteTexture();
}


bool CTile::Collision()
{
    return collideable;
}
void CTile::SetCollision(bool Collision)
{
    collideable = Collision;
}


void CTile::OnRenderGL(float x, float y)
{
    glBindTexture(GL_TEXTURE_2D,Texture->texture);
    //I'm going to draw stuff state machine call
    glBegin(GL_QUADS);                                   
        glTexCoord2d( 0, 0 );    glVertex2f( x,     y );
        glTexCoord2d( 0, 1 );    glVertex2f( x,     y+16 );
        glTexCoord2d( 1, 1 );    glVertex2f( x+16, y+16 );
        glTexCoord2d( 1, 0 );    glVertex2f( x+16, y );
    glEnd();
    return;
}