#include "CChunk.h"

CChunk::CChunk()
{
    for(int i = 0; i < CHUNK_X_DEM; ++i)
    {
        for(int j = 0; j < CHUNK_Y_DEM; ++i)
        {
            ChunkArray[i][j] = 0;
        }
    }
}


CChunk::~CChunk() 
{
    for(int i = 0; i < CHUNK_X_DEM; ++i)
    {
        for(int j = 0; j < CHUNK_Y_DEM; ++i)
        {
            delete ChunkArray[i][j];
        }

    }
    
}

void CChunk::OnCleanup()
{
    // Make this clean up stuff!
}