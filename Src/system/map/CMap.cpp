#include "CMap.h"

CMap::CMap() 
{
    X=0;
    Y=0;
    for (int i = 0; i < MAP_WORLD_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_WORTH_HEIGHT; ++j)
        {
            Chunks[i][j]=NULL;
        }
    }
}

CMap::~CMap() 
{
    for (int i = 0; i < MAP_WORLD_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_WORTH_HEIGHT; ++j)
        {
            delete Chunks[i][j];
        }
    }
}

void CMap::OnLoop()
{
    // Check to make sure we have all our chunks loaded
    for (int i = 0; i < MAP_WORLD_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_WORTH_HEIGHT; ++j)
        {
            if (Chunks[i][j]==NULL)
            {
                // Generate the chunk
            }
        }
    }
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
    x.Seed=Seed; // Good place for a this-> pointer?

    if (gaia!=NULL)
        return false;

    gaia = new CChunk;

    for (int i = 0; i < CHUNK_x_DEM; ++i)
    {
        for (int j = 0; j < CHUNK_Y_DEM; ++j)
        {
            // Generate each tile with the perlin noise generated
        }
    }

    return true;

}


