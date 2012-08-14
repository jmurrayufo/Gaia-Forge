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

void CChunk::ChangeWallTile(int x, int y, int id)
{   
      
    ChunkWallVect[x + (y * CHUNK_X_DEM)]= new CTile(id);

}

void CChunk::ChangeTile(int x, int y, int id, bool collision)
{
    ChunkWallVect[x + (y * CHUNK_X_DEM)]= new CTile(id, collision);
}

void CChunk::OnRenderGL(float x, float y, int x_c, int y_c)
{
    if((x_c>CHUNK_X_DEM)||(y_c>CHUNK_Y_DEM))
    {
        std::cerr << "Chunk::OnRenderGL chunk coordinates out of bounds! x_c="<< x_c << " y_c=" << y_c << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
        assert(0);
    }
}


