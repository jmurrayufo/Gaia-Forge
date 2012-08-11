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
void CChunk::OnRenderGL(float x, float y, int w, int h)
{
    /*
        Note the complex for loop here. We want to loop through the area starting at the 
        edge of the screen and going to the right. We stop if we hit the edge of the 
        screen OR the edge of the chunk. 
    */
    std::cerr << "Entered Function" << std::endl << "    " << __FILE__ << __LINE__ << std::endl;
    std::cerr.flush();

    for (int i = 0; i < w; ++i)
    {
        float x_world = i + x - w/2;
        float x_chunk = fmod(x_world,w);
        std::cerr << "Loop(i):" << i << std::endl << "   >" << __FILE__ << __LINE__ << std::endl;
        std::cerr << "x_w:" << x_world << std::endl;
        std::cerr << "x_w(int):" << floor(x_world) << std::endl;
        std::cerr << "x_c:" << x_chunk << std::endl;

        if( (x_world < X * CHUNK_X_DEM) || (x_world > X * CHUNK_X_DEM + CHUNK_X_DEM) )
        {
            std::cerr << "SKIPED!" << std::endl;
            continue;
        }

        for (int j = 0; j < h; ++j)
        {
            float y_world = j + y - CHUNK_Y_DEM/2;
            float y_chunk = fmod(y_world,CHUNK_Y_DEM);
            std::cerr << "  Loop(j):" << j << std::endl << "     >" << __FILE__ << __LINE__ << std::endl;

            if( (x_world < Y * CHUNK_Y_DEM) || (y_world > Y * CHUNK_Y_DEM + CHUNK_Y_DEM) )
            {
                std::cerr << "SKIPED!" << std::endl;
                continue;
            }

            std::cout << "IN CHUNK!" << std::endl;            
        }
    }
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