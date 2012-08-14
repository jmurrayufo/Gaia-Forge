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

void CChunk::SetWallTile(int x, int y, int id)
{   
    // FIXME: This causes a memory leak EVERY time we change a wall!
    // NOTE: This function only takes values inside itself. If we do x % CHUNK_X_DEM then we get to use world coords!
    ChunkWallVect[x + (y * CHUNK_X_DEM)]= new CTile(id);

}

void CChunk::SetTile(int x, int y, int id, bool collision)
{
    // FIXME: This causes a memory leak EVERY time we change a tile!
    // NOTE: This function only takes values inside itself. If we do x % CHUNK_X_DEM then we get to use world coords!
    ChunkWallVect[x + (y * CHUNK_X_DEM)]= new CTile(id, collision);
}

void CChunk::OnRenderGL(float x, float y, int x_c, int y_c)
{
    if( (x_c > CHUNK_X_DEM) || (y_c > CHUNK_Y_DEM) )
    {
        std::cerr << "Chunk::OnRenderGL chunk coordinates out of bounds! x_c="<< x_c << " y_c=" << y_c << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
        assert(0);
    }
}


