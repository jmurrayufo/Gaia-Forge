#ifndef _CMAP_H_
    #define _CMAP_H_

#include <vector>
#include <iostream>
#include <iomanip>
#include <assert.h>



#include "CChunk.h"
#include "../noise/Noise.h"

//! Units of pixels on the screen
#define CMAP_TILE_SIZE 16 

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
   float XCam;
   //! Current location in the Y direction in tiles. 
   float YCam;


   int Width;


   int Height;


   float SeaLevel;

   //! Pointers to all the CChunks in this map
   std::vector<CChunk*> Chunks;

   //! Seed that this map is based off of. All Perlin noise should use the same seed!
   int Seed;

public:
   CMap();
   ~CMap();

   // TODO: Document this function
   void OnInit();

   //! Called to load a map file.
   // TODO: Finish coding this function
   void OnLoad(const char* File);

   //! Save the map file to a given location.

   // TODO: Finish coding this function
   void OnSave(const char* File);

   //! Save the map file to it's default location

   // TODO: Finish coding this function
   void OnSave();

   //! Called every frame. This should take care of dynamic load/free of chunks.

   // TODO: Finish coding this function
   void OnLoop();

   /*! 
      Render the screen at a given tile location
      \param[in] x Lateral location in tile coords
      \param[in] y Vertial location in tile coords
      \param[in] w Width of the screen in pixels
      \param[in] h Height of the screen in pixels
   */
   // TODO: Make this function
   void OnRenderGL(float x,float y,float w=WWIDTH,float h=WHEIGHT);

   /*!
      Render the current scene. 
      The scene is drawn form the currently known location within the CMap class. 
   */
   void OnRednerGL();

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

   // TODO: Document this function
   void SetSize(int,int);

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
   /*!
      Populate a null chunk with data from the seed and current parameters. 
      TODO: We need the parameters for worlds to be saved (how do we build different works?)
      TODO: This function might need to get built into a world gen class...
   */
   bool GenerateChunk(int,int,CChunk*);
};

#endif
