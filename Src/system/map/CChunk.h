#ifndef _CCHUNK_H_
#define _CCHUNK_H_

/*!
\brief Maintain a given segment of map tiles. Deal with saving/loading files from the HDD. 
This class maintains a large segment of tile space in the game. It will load up, modify, 
    and save groups of tiles. 
*/
#include "CTile.h"

#define CHUNK_X_DEM 1024
#define CHUNK_Y_DEM 1024

class CChunk 
{




    // TODO: Add a container for a large number of tiles. The current plan is to have 
    //      1024 x 1024 tiles in a chunk (1,048,576 tiles total). This might be too much 
    //      or not enough, we need to decide. Smaller chunks will result in more 
    //      processor overhead, but less memory footprint. 
     

public:
    //! X location of chunk
    unsigned int X;
    //! Y location of chunk
    unsigned int Y;
    CTile* ChunkArray[CHUNK_X_DEM][CHUNK_Y_DEM];
    CTile* ChunkWallArray[CHUNK_Y_DEM][CHUNK_Y_DEM];


    CChunk();
    ~CChunk();

    void OnInit();

    void OnLoad(const char* File);

};

#endif //_CCHUNK_H_
