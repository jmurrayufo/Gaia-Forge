#ifndef _VIDMEM_H_
    #define _VIDMEM_H_

#include <vector>
#include <ostream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <string>

/*! \brief Maintain list of loaded textures in video memory

\todo TODO: Document this!
*/

class VidMem
{
// TODO: This public identifier might be a bad idea, as it will allow us to  modify things
//  that we aught not to modify.....
public: 
    //! Static vector that SHOULD contain all members of this class
    static std::vector<VidMem*> textureList;

    //! String of the file that this texture was loaded from
    std::string textureFile;

    //! This is a handle to our texture object
    GLuint texture;

    //! Width of the texture (pixels)
    unsigned int x;

    //! Height of the texture (pixels)
    unsigned int y;

    //! Number of copies of this object in existence. 
    signed int count;

public:
    VidMem();
    ~VidMem();

    /*! 
        \brief Initialize the given texture. 
        
        \note This function will first check to see if a texture has been loaded, and use 
            that rather then creating a NEW texture. In either case, a VidMem pointer is returned.

        \param[in] File A null terminated file name to attempt to load. 
        \return Pointer to a VidMem to use. May not be unique. Care must be taken to 
            avoid stepping on another objects texture! 

    */
    VidMem* InitTexture(const char* File);

    /*! 
        \brief Mark a given texture as unneeded. 

        \note This function will not delete the texture from graphical memory until ALL the 
            checked out entities have also run this function.

        \return True if the texture was deleted successfully. False when there was an error. 
    */
    bool DeleteTexture(void);

    /*!
        \brief Check if a given texture file has been loaded. 
    
        \param[in] File A null terminated file name to attempt to check. 

        \return Number of instances of this texture in existence. Reports 0 if none exist, 
            and returns negatives on error. 
    */
    // TODO: Should we have a GLuint version of this? 
    int CheckTexture(const char* File);

    /*!
        \brief Find a given texture
    
        \param[in] File A null terminated file name to attempt to check. 

        \return Pointer to locationed VidMem. 
            Returns NULL if nothing is found.  
    */
    VidMem* FindTexture(const char* File);

    /*! 
        \brief Get iterator to given texture
    
        \param[in] File A null terminated file name to attempt to check. 

        \warning This function creates an iterator in memory! You will need to delete this
            iterator or you will have a MEMORY LEAK!!!

        \return Iterator to texture. Will be NULL on failure  
    */
    std::vector<VidMem*>::iterator* GetTextureIterator(const char* File);

    /*!
        \brief Get the current X value.

        \return The current X value. 
    */
    // TODO: Write this function into VidMem.cpp
    unsigned int GetX(void);

    /*!
        \brief Get the current Y value.

        \return The current y value. 
    */
    // TODO: Write this function into VidMem.cpp
    unsigned int GetY(void);

    /*!
        \brief Get the current XY value.

        \param[out] x Store the current x value into the argument (it acts like a pointer)
        \param[out] y Store the current y value into the argument (it acts like a pointer)
    */
    // TODO: Write this function into VidMem.cpp
    int GetXY(int& x,int& y);

    /*!
        \brief GSet the current XY value.

        \param[in] x Set the X value.

        \return True if value was set, False on error.
    */
    // TODO: Write this function into VidMem.cpp
    bool SetX(int x);

    /*!
        \brief GSet the current XY value.

        \param[in] y Set the Y value.

        \return True if value was set, False on error.
    */
    // TODO: Write this function into VidMem.cpp
    bool SetY(int y);

    /*!
        \brief GSet the current XY value.

        \param[in] x Set the X value.
        \param[in] y Set the Y value.

        \return True if value was set, False on error.
    */
    // TODO: Write this function into VidMem.cpp
    bool SetXY(int x,int y);



};

#endif //_VIDMEM_H_
