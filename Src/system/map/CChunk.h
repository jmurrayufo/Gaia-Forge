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
// FIXME: Defines are global, we should use the class name as the first word...
#define CHUNK_X_DEM 1024
#define CHUNK_Y_DEM 1024

class CChunk 
{
    // TODO: Add a container for a large number of tiles. The current plan is to have 
    //      1024 x 1024 tiles in a chunk (1,048,576 tiles total). This might be too much 
    //      or not enough, we need to decide. Smaller chunks will result in more 
    //      processor overhead, but less memory footprint. 
public:
    //! Storage of tile elements 
    std::vector<CTile*> ChunkVect;

    //! Storage of wall elements 
    std::vector<CTile*> ChunkWallVect;

    CChunk();
    ~CChunk();

    //! Allocate the memory for a CChunk.
    void OnInit();

    //! Detect if the tile at (x,y) is solid or not. 
    // TODO: Add CChunk::IsSolid(int, int)
    bool IsSolid(int x, int y);

    //! Set tile to a specific ID, optionally being collide-able. 
    void SetTile(int x, int y, short id, bool collision);

    //! Set tile to be a background wall, with the specific ID.
    void SetWallTile(int x, int y, short id);

    /*!
        \note Unimplemented 
    */
    // TODO: Add CChunk::OnLoad(char*)
    void OnLoad(const char* File);

    //! Clean up any used memory from the CChunk.
    void OnCleanup();

    /*!
        Render a single tile to the screen. 
        \param[in] x    X location (on the screen) to render the tile too
        \param[in] y    Y location (on the screen) to render the tile too
        \param[in] x_c  x coordinate of the tile to render
        \param[in] y_c  y coordinate of the tile to render
    */
    void OnRenderGL(float x, float y, int x_c, int y_c);

};

#endif //_CCHUNK_H_
