#ifndef _CCHUNK_H_
    #define _CCHUNK_H_

/*!
\brief Maintain a given segment of map tiles. Deal with saving/loading files from the HDD. 
This class maintains a large segment of tile space in the game. It will load up, modify, 
    and save groups of tiles. 
*/
#include "CTile.h"


class CChunk {

    // TODO: What does X and Y represent? Lower/upper, left/right corner? This should NOT 
    //      be the middle of the chunk as this would add lots more math to worry about. 

    //! X location of chunk
    unsigned int X;    

    //! Y location of chunk
    unsigned int Y;

    // TODO: Add a container for a large number of tiles. The current plan is to have 
    //      1024 x 1024 tiles in a chunk (1,048,576 tiles total). This might be too much 
    //      or not enough, we need to decide. Smaller chunks will result in more 
    //      processor overhead, but less memory footprint. 

    public:
        CChunk();
        ~CChunk();
};

#endif //_CCHUNK_H_
