#ifndef _CMAP_H_
    #define _CMAP_H_


/*!
\brief Maintain the map of a given world. Allow the system to talk to the chunks.

CMap will keep a collection of CChunks somehow, and allow the rest of the system
to accesss them. 
*/

class CMap {

   public:
      CMap();
      ~CMap();
};

#endif
