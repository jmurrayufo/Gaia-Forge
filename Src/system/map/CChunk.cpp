#include "CChunk.h"

CChunk::CChunk()
{   
    //reserves memory for CTile pointer elements
    ChunkVect.reserve(CHUNK_X_DEM * CHUNK_Y_DEM);
    ChunkWallVect.reserve(CHUNK_X_DEM * CHUNK_Y_DEM);

    //Creates null Pointer CTile elements
    for (int i = 0 ; i<(CHUNK_X_DEM * CHUNK_Y_DEM) ; ++i)
    {
        ChunkVect.push_back(NULL);
        ChunkWallVect.push_back(NULL);
    }
}

CChunk::~CChunk() 
{
    OnCleanup();
}

void CChunk::OnCleanup()
{
    for (int i = 0 ; i<(CHUNK_X_DEM * CHUNK_Y_DEM) ; ++i)
    {
        if(ChunkVect[i]!=NULL)
            delete ChunkVect[i];
        if(ChunkWallVect[i]!=NULL)
            delete ChunkWallVect[i];
    }
    ChunkVect.clear();
    ChunkWallVect.clear();
}

void CChunk::SetWallTile(int x, int y, short id)
{   
    // FIXME: This causes a memory leak EVERY time we change a wall! FIXED: needs to be tested
    // NOTE: This function only takes values inside itself. If we do x % CHUNK_X_DEM then we get to use world coords!

    if ( ChunkWallVect[x + (y * CHUNK_X_DEM)] == NULL )
    {
        ChunkWallVect[x + (y * CHUNK_X_DEM)]= new CTile(id);
    }
    else
    {
         ChunkWallVect[x + (y * CHUNK_X_DEM)]->tileID = id;
    }
}

void CChunk::SetTile(int x, int y, short id, bool collision)
{
    // FIXME: This causes a memory leak EVERY time we change a tile! FIXED: needs to be tested
    // NOTE: This function only takes values inside itself. If we do x % CHUNK_X_DEM then we get to use world coords!

    if ( ChunkVect[x + (y * CHUNK_X_DEM)] == NULL )
    {
        ChunkVect[x + (y * CHUNK_X_DEM)]= new CTile(id, collision);
    }
    else
    {
         ChunkVect[x + (y * CHUNK_X_DEM)]->tileID = id;
         ChunkVect[x + (y * CHUNK_X_DEM)]->SetCollision(collision);
    }
}

void CChunk::OnRenderGL(float x, float y, int x_c, int y_c)
{
    if( (x_c > CHUNK_X_DEM) || (y_c > CHUNK_Y_DEM) )
    {
        std::cerr << "Chunk::OnRenderGL chunk coordinates out of bounds! x_c="<< x_c << " y_c=" << y_c << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
        assert(0);
    }
}


