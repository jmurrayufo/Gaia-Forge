#ifndef _CTEXTURE_H_
    #define _CTEXTURE_H_

#include <vector>
#include <gl/gl.h>
#include <gl/glu.h>

/*! \brief Maintain list of loaded textures

\todo Document this!
*/

class CTexture
{
// TODO: This public identifier might be a bad idea, as it will allow us to  modify things
//  that we aught not to modify.....
public: 
    //! Static vector that SHOULD contain all members of this class
    static std::vector<CTexture> textureList;

    //! String of the file that this texture was loaded from
    char *textureFile;

    //! This is a handle to our texture object
    GLuint texture;

    //! Width of the texture (pixels)
    unsigned int x;

    //! Height of the texture (pixels)
    unsigned int y;

    //! Number of copies of this object in existence. 
    signed int count;

public:
    CTexture();
    ~CTexture();

    /*! 
        \brief Initialize the given texture. 
        
        \note This function will first check to see if a texture has been loaded, and use 
            that rather then creating a NEW texture. In either case, a CTexture pointer is returned.

        \param[in] File A null terminated file name to attempt to load. 
        \return Pointer to a CTexture to use. May not be unique. Care must be taken to 
            avoid stepping on another objects texture! 

    */
    // TODO: Write this function into CTexture.cpp
    CTexture* InitTexture(const char* File);

    /*! 
        \brief Mark a given texture as unneeded. 

        \note This function will not delete the texture from graphical memory until ALL the 
            checked out entities have also run this function.

        \return True if the texture was deleted successfully. False when there was an error. 
    */
    // TODO: Write this function into CTexture.cpp
    bool DeleteTexture(void);

    /*!
        \brief Check if a given texture file has been loaded. 
    
        \param[in] File A null terminated file name to attempt to check. 

        \return Number of instances of this texture in existence. Reports 0 if none exist, 
            and returns negatives on error. 
    */
    // TODO: Should we have a GLuint version of this? 
        // TODO: Write this function into CTexture.cpp
    int CheckTexture(const char* File);

    /*!
        \brief Get the current X value.

        \return The current X value. 
    */
    // TODO: Write this function into CTexture.cpp
    unsigned int GetX(void);

    /*!
        \brief Get the current Y value.

        \return The current y value. 
    */
    // TODO: Write this function into CTexture.cpp
    unsigned int GetY(void);

    /*!
        \brief Get the current XY value.

        \param[out] x Store the current x value into the argument (it acts like a pointer)
        \param[out] y Store the current y value into the argument (it acts like a pointer)
    */
    // TODO: Write this function into CTexture.cpp
    int GetXY(int& x,int& y);

    /*!
        \brief GSet the current XY value.

        \param[in] x Set the X value.

        \return True if value was set, False on error.
    */
    // TODO: Write this function into CTexture.cpp
    bool SetX(int x);

    /*!
        \brief GSet the current XY value.

        \param[in] y Set the Y value.

        \return True if value was set, False on error.
    */
    // TODO: Write this function into CTexture.cpp
    bool SetY(int y);

    /*!
        \brief GSet the current XY value.

        \param[in] x Set the X value.
        \param[in] y Set the Y value.

        \return True if value was set, False on error.
    */
    // TODO: Write this function into CTexture.cpp
    bool SetXY(int x,int y);



};

#endif //_CTEXTURE_H_
