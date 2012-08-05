#ifndef _CMAP_H_
    #define _CMAP_H_


/*!
\brief Maintain the map of a given world. Allow the system to talk to the chunks.

CMap will keep a collection of CChunks somehow, and allow the rest of the system
to access them. 
*/

class CMap {

   public:
      CMap();
      ~CMap();

      //! Called to load a map file.
      void OnLoad(const char* File);

      //! Save the map file to a given location.
      void OnSave(const char* File);

      //! Save the map file to it's default location
      void OnSave();

      //! Called every frame. This should take care of dynamic load/free of chunks.
      void OnLoop();

      //! Render the current scene. 
      //! This includes Background, BackgroundTiles, Tiles, and water/lava (probably in that order).
      void OnRenderGL();

      //! This map file is no longer needed, close down. 
      void OnCleanup();
};

#endif
