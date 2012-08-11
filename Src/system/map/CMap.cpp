#include "CMap.h"

CMap::CMap() 
{
    X=0;
    Y=0;
    Chunks.reserve( MAP_WORLD_WIDTH * MAP_WORLD_HEIGHT );
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
    // The screen is CENTERED on x,y right now. We need to draw around this point
    // First, we figure out what chunks we are hitting
    float x_min;
    float x_max;
    float y_min;
    float y_max;

    x_min = x - w/2; // Left most Coord to render
    x_max = x + w/2; // Right most Coord to render
    x_min = y - h/2; // Top most Coord to render
    x_max = y + h/2; // Bottom most Coord to render
    
    // Loop through CCHunks and add ones that we care about to the RenderList
    for (int i = 0; i < MAP_WORLD_WIDTH; ++i)
    {
        // Loop though the y dimension
        for (int j = 0; j < MAP_WORLD_HEIGHT; ++j)
        {
            // Determine if chunk hits the range
            CChunk* tmp = Chunks.at(i + j*CHUNK_X_DEM);
            if(tmp->IsInRect(x_min,x_max,y_min,y_max))
            {
                tmp->OnRenderGL(x,y,w,h);
            } // (if(IsInRect))
        } // For(j)
    } // For(i)
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


