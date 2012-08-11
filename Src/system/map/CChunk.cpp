#include "CChunk.h"

CChunk::CChunk()
{   
    return;
    for(int i = 0; i < CHUNK_X_DEM; ++i)
    {
        for(int j = 0; j < CHUNK_Y_DEM; ++i)
        {
            //ChunkArray[i][j] = (CTile*)0;
        }
    }   
}


CChunk::~CChunk() 
{
    for(int i = 0; i < CHUNK_X_DEM; ++i)
    {
        for(int j = 0; j < CHUNK_Y_DEM; ++j)
        {
            //delete ChunkArray[i][j];
        }
    }
}

void CChunk::OnCleanup()
{
    // Make this clean up stuff!
}
void CChunk::OnRenderGL(float x, float y, int x_c, int y_c)
{

}

bool CChunk::IsInRect( float x1, float x2, float y1, float y2 )
{
    if(             X > x2 && 
        X+CHUNK_X_DEM < x1 && 
                    Y > y2 &&
        Y+CHUNK_Y_DEM < y1)
        return false;
    else
        return true;
}