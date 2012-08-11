#include "CMap.h"

CMap::CMap()
{
    X=0;
    Y=0;
    Chunks.reserve( MAP_WORLD_WIDTH * MAP_WORLD_HEIGHT );
    for (int i = 0; i < MAP_WORLD_WIDTH * MAP_WORLD_HEIGHT; ++i)
    {
        Chunks.push_back((CChunk*)i);
    }
}

CMap::~CMap()
{
    for( std::vector<CChunk*>::iterator i = Chunks.begin() ; i!=Chunks.end() ; ++i )
        (*i)->OnCleanup();
    Chunks.clear();
}

void CMap::OnLoad(const char* File)
{
    std::cerr << "You cannot call CMapp::OnLoad until it has been created!" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    assert(0); // This is always a failure right now
}

void CMap::OnSave(const char* File)
{
    std::cerr << "You cannot call CMapp::OnSave until it has been created!" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    assert(0); // This is always a failure right now
}

void CMap::OnSave()
{
    std::cerr << "You cannot call CMapp::OnSave until it has been created!" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    assert(0); // This is always a failure right now
}

void CMap::OnLoop()
{
    std::cerr << "You cannot call CMapp::OnLoop until it has been created!" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    assert(0); // This is always a failure right now
}

void CMap::OnRenderGL(float x,float y,float w,float h)
{
    CChunk *currentChunk=(CChunk*)-1;
    int currentChunkX;
    int currentChunkY;

    for (int j = 0; j < h; j+=16) // Tile Size
    {
        float y_world = j/16 + y - h/(2*16); // j and h must be converted to World Tile Coords
        float y_screen = (floor(y_world) - y_world) + j;
        float y_chunk = floor(y_world);
        currentChunkY = floor(y_world/CHUNK_Y_DEM);

        if(currentChunkY<0)
        {
            continue; 
        }
        if(currentChunkY>=MAP_WORLD_HEIGHT)
        {
            break;
        }

        for (int i = 0; i < w; i+=16)
        {
            float x_world = i/16 + x - w/(2*16); // j and h must be converted to World Tile Coords
            float x_screen = (floor(x_world) - x_world) + i;
            float x_chunk = floor(x_world);
            currentChunkX = floor(x_world/CHUNK_X_DEM);


            if(currentChunkX<0)
            {
                continue; 
            }
            if(currentChunkX>=MAP_WORLD_WIDTH)
            {
                break;
            }

            if(currentChunk != Chunks.at(currentChunkX + currentChunkY * MAP_WORLD_WIDTH))
            {
                currentChunk = Chunks.at(currentChunkX + currentChunkY * MAP_WORLD_WIDTH);
            }

            // currentChunk now points to the chunk we want to render on. 
            // y_world: This is the world location of the current tile
            // y_screen: This is the screen (pixel based) location of the tile!
            // y_chunk: This is the int of the chunk location in tile units
            // x_world: This is the world location of the current tile
            // x_screen: This is the screen (pixel based) location of the tile!
            // x_chunk: This is the int of the chunk location in tile units

        }
    }
        
}

void CMap::OnRednerGL()
{
    std::cerr << "You cannot call CMapp::OnRenderGL until it has been created!" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    assert(0); // This is always a failure right now
}

void CMap::OnCleanup()
{
    for( std::vector<CChunk*>::iterator i = Chunks.begin() ; i!=Chunks.end() ; ++i )
        (*i)->OnCleanup();
    Chunks.clear();
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

    // Loop through the x dimension
    for (int i = 0; i < CHUNK_X_DEM; ++i)
    {
        // Loop though the y dimension
        for (int j = 0; j < CHUNK_Y_DEM; ++j)
        {
            // Generate noise for Chunks.at(x + y*CHUNK_X_DEM)
        }
    }

    return true;

}


