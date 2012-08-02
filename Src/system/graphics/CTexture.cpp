#include "CTexture.h"

// We must declare static members someplace, here works!
std::vector<CTexture*> CTexture::textureList;

CTexture::CTexture()
{
    textureFile="";
    texture=NULL;
    x=0;
    y=0;
    count=0;
    //Void
}

CTexture::~CTexture()
{
    //Void
}

CTexture* CTexture::InitTexture(const char* File)
{
    // To CTexture pointers. On to hold the pointer we look for, the other is a mule.
    CTexture *tmpTexture,*tmpTextureLocation;

    // Attempt to find the texture with FindTexture()
    if((tmpTextureLocation=FindTexture(File))==NULL)
    {

        //We did NOT find the texture, create a new one!
        tmpTexture=new CTexture;

        // Initialize it
        tmpTexture->count++;
        tmpTexture->textureFile=std::string(File);

        //Push the texture onto the back of the vector and return a pointer to it. 
        CTexture::textureList.push_back(tmpTexture);
        return CTexture::textureList.back(); 
    }
    else
    {
        //We did find the texture, add one to its counter and return it. 
        tmpTextureLocation->count++;
        return tmpTextureLocation;
    }
    //This should never be reached, and keeps the compiler happy. 
    return (CTexture*)NULL;
}

bool CTexture::DeleteTexture(void)
{
    // Pointer to use with the GetTextureIterator. This function mallocs memory that we MUST free. 
    std::vector<CTexture*>::iterator *loc;

    // Decrement the counter, as one last thing now points to it. 
    this->count--;

    // Determine if we were the lass texture to be deleted. 
    if(count<1)
    {
        loc=GetTextureIterator(textureFile.c_str());
        textureList.erase(*loc);
        delete loc;

        // LOL! We tell the object to DELETE IT SELF!!!
        delete this;

        // We were the last object!
        return true;
    }
    // We weren't the last object.... 
    return false;
}

int CTexture::CheckTexture(const char* File)
{
    // Search through the vector
    std::string tmpFile=std::string(File);
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        // Compare the strings. They function as the id for the object and should be unique. 
        if(tmpFile == (*i)->textureFile)
            return true;
    }
    // We iterated through the entire vector and did not find anything, return false.
    return false;
}

CTexture* CTexture::FindTexture(const char* File)
{
    // Search through the vector
    std::string tmpFile=std::string(File);
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        // Compare the strings. They function as the id for the object and should be unique. 
        if(tmpFile == (*i)->textureFile)
            return (*i);
    }
    // We iterated though the entire vector, and did not find the texture. 
    return NULL;
}

std::vector<CTexture*>::iterator* CTexture::GetTextureIterator(const char* File)
{    
    // Search through the vector
    std::vector<CTexture*>::iterator *loc=NULL;
    std::string tmpFile=std::string(File);
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        if(tmpFile == (*i)->textureFile)
        {
            // We found the texture! Return a new iterator to it. 
            // BE AWARE! This new iterator needs to be cleaned at some point!
            // This iterator MAY become invalid if the vector is reallocated as things are 
            //  added and removed. 
            loc=new std::vector<CTexture*>::iterator(i);
            break;
        }
    }

    return loc;
}


unsigned int CTexture::GetX(void)
{
    return 0;
}

unsigned int CTexture::GetY(void)
{
    return 0; 
}

int CTexture::GetXY(int& x,int& y)
{
    return 0;
}

bool CTexture::SetX(int x)
{
    return false;
}

bool CTexture::SetY(int y)
{
    return false;
}

bool CTexture::SetXY(int x,int y)
{
    return false;
}
