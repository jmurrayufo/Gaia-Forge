#ifndef _CMAP_H_
    #define _CMAP_H_

#include "CChunk.h"


#define MAP_WORLD_WIDTH    8
#define MAP_WORTH_HEIGHT   2



/*!
\brief Maintain the map of a given world. Allow the system to talk to the chunks.

CMap will keep a collection of CChunks somehow, and allow the rest of the system
to access them. 
*/

/*
   TODO: We need to decide who handles the physics in the chunks. Blocks that "drop" or
      move somehow need to be dealt with when they leave a chunk. I say we give the chunk
      a OnLoop() function that somehow returns a vector of tiles that are leaving it's 
      space. 
*/

class CMap {

public:
   //! Current location in the X direction in tiles.
   float X;

   //! Current location in the Y direction in tiles. 
   float Y;

   //! Pointers to all the CChunks in this map
   CChunk* Chunks[MAP_WORLD_WIDTH][MAP_WORTH_HEIGHT];

   //! Seed that this map is based off of. Add Perlin noise should use the same seed!
   int Seed;

public:
   CMap();
   ~CMap();

   //! Called to load a map file.
   // TODO: Make this function
   void OnLoad(const char* File);

   //! Save the map file to a given location.

   // TODO: Make this function
   void OnSave(const char* File);

   //! Save the map file to it's default location

   // TODO: Make this function
   void OnSave();

   //! Called every frame. This should take care of dynamic load/free of chunks.

   // TODO: Make this function
   void OnLoop();

   /*! 
      Render the current scene. 
      This includes Background, BackgroundTiles, Tiles, and water/lava (probably in that order).
   */
   // TODO: Make this function
   void OnRenderGL(float x,float y,float w=WWIDTH,float h=WHEIGHT);

   //! This map file is no longer needed, close down. 

   // TODO: Make this function
   void OnCleanup();

   // Access Functions

   //! Determine if the location is a collide-able block. 

   // TODO: Make this function
   bool GetCollision(int,int);

   /*! Determine if the location is a collide-able block. 
      This function can be given a float value of a location in the world, it will 
         convert it to tile coords and use that value
      \sa GetCollision(int,int)
   */
   
   // TODO: Make this function
   bool GetCollision(float,float);

   /*! Set the current screen location as an int.
      \param int[in] Left most corner of screen location in tile coords.
      \param int[in] Top most corner of screen location in tiles coords.
      \param int[in] Width of screen in pixels.
      \param int[in] Height of screen in pixels.
   */
   
   // TODO: Make this function
   int SetLocation(int,int,int,int);

   /*! Set the current screen location as a float.
      \param float[in] Left most corner of screen location in tile coords.
      \param float[in] Top most corner of screen location in tiles coords.
      \param int[in] Width of screen in pixels.
      \param int[in] Height of screen in pixels.
   */
   
   // TODO: Make this function
   int SetLocation(float,float,int,int);

private:

};

#endif
