#ifndef _CCHUNK_H_
#define _CCHUNK_H_

/*!
\brief Maintain a given segment of map tiles. Deal with saving/loading files from the HDD. 
This class maintains a large segment of tile space in the game. It will load up, modify, 
    and save groups of tiles. 
*/

#include <math.h> // We needed fmod()
#include <iostream>
#include <vector>
#include "CTile.h"
#include <assert.h>
#define CHUNK_X_DEM 1024
#define CHUNK_Y_DEM 1024

class CChunk 
{
    // TODO: Add a container for a large number of tiles. The current plan is to have 
    //      1024 x 1024 tiles in a chunk (1,048,576 tiles total). This might be too much 
    //      or not enough, we need to decide. Smaller chunks will result in more 
    //      processor overhead, but less memory footprint. 
public:
    //Storage of tile elements 
    std::vector<CTile*> ChunkVect;
    std::vector<CTile*> ChunkWallVect;

    CChunk();
    ~CChunk();

    void OnInit();

    //sets specific tile to specified properties
    void ChangeTile(int x, int y, int id, bool collision);
    void ChangeWallTile(int x, int y, int id);


    void OnLoad(const char* File);

    void OnCleanup();

    /*!
        Render the current chunk with the given frame
    */
    void OnRenderGL(float x, float y, int x_c, int y_c);

    /*!
        Take a 4 element float vector and return true if it touches this CChunk
        \param x1[in]
        \param x2[in]
        \param y1[in]
        \param y2[in]
    */
    
};

#endif //_CCHUNK_H_
