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
    CChunk *currentChunk=NULL;
    // Locate the first chunk we want to use
    int currentChunkX = floor(x-w/2)/CHUNK_X_DEM;
    int currentChunkY = floor(y-h/2)/CHUNK_Y_DEM;
    currentChunk = Chunks.at(currentChunkX + currentChunkY * MAP_WORLD_WIDTH);

    for (int j = 0; j < h; ++j)
    {
        float y_world = j + y - h/2;
        float y_screen = (int)y_world - y_world + j;
        float y_chunk = floor(y_world);
        std::cerr << "Loop(j):" << j << std::endl << "  >" << __FILE__ << __LINE__ << std::endl;
        std::cerr << " y_w:" << y_world << std::endl;
        std::cerr << " y_w(int):" << floor(y_world) << std::endl;
        std::cerr << " y_screen:" << y_screen << std::endl;
        std::cerr << " y_c:" << y_chunk << std::endl;

        for (int i = 0; i < w; ++i)
        {
            float x_world = i + x - w/2;
            float x_screen = (int)x_world - x_world + i;
            float x_chunk = floor(x_world);
            std::cerr << "  Loop(i):" << i << std::endl << "    >" << __FILE__ << __LINE__ << std::endl;
            std::cerr << "   x_w:" << x_world << std::endl;
            std::cerr << "   x_w(int):" << floor(x_world) << std::endl;
            std::cerr << "   x_screen:" << x_screen << std::endl;
            std::cerr << "   x_c:" << x_chunk << std::endl;

            // Recalculate the current chunk in the X axis
            currentChunkX = floor(x_world)/CHUNK_X_DEM;
            currentChunkY = floor(y_world)/CHUNK_Y_DEM;
            std::cerr << "   At:" << currentChunkX << "," << currentChunkY << std::endl;
            if(currentChunk != Chunks.at(currentChunkX + currentChunkY * MAP_WORLD_WIDTH))
            {
                std::cerr << "   New Chunk!" << std::endl;
                std::cerr << "   Now at:" << currentChunkX << "," << currentChunkY << std::endl;
                currentChunk = Chunks.at(currentChunkX + currentChunkY * MAP_WORLD_WIDTH);
            }


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


