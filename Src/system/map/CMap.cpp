#include "CMap.h"

CMap::CMap() 
{
    X=0;
    Y=0;
    Chunks.reserve( MAP_WORLD_WIDTH * MAP_WORTH_HEIGHT );
}

CMap::~CMap() 
{
    for( std::vector<CChunk*>::iterator i = Chunks.begin() ; i!=Chunks.end() ; ++i )
        (*i)->OnCleanup();
}

void CMap::OnLoop()
{

}

bool CMap::GenerateChunk( int x, int y, CChunk* gaia )
{
    //Determine offset for both x and y
    int offset_x = x * CHUNK_X_DEM;
    int offset_y = y * CHUNK_Y_DEM;
    // TODO: It would be nice to have a good means to break up mineral types in world gen. 
    // Maybe with a property tree?
    Noise ground;
    Noise dirt;
    Noise rock;

    if (gaia!=NULL)
        return false;

    gaia = new CChunk;

    for (int i = 0; i < CHUNK_X_DEM; ++i)
    {
        for (int j = 0; j < CHUNK_Y_DEM; ++j)
        {
            // Generate each tile with the perlin noise generated
        }
    }

    return true;

}


