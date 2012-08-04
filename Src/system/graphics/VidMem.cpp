#include "VidMem.h"

// We must declare static members someplace, here works!
std::vector<VidMem*> VidMem::textureList;

VidMem::VidMem()
{
    textureFile="";
    texture=0;
    x=0;
    y=0;
    count=0;
    //Void
}

VidMem::~VidMem()
{
    //Void
}

VidMem* VidMem::InitTexture(const char* File)
{
    // To VidMem pointers. On to hold the pointer we look for, the other is a mule.
    VidMem *tmpTexture,*tmpTextureLocation;

    // Attempt to find the texture with FindTexture()
    if((tmpTextureLocation=FindTexture(File))==NULL)
    {

        //We did NOT find the texture, create a new one!
        tmpTexture=new VidMem;

        // Initialize it
        tmpTexture->count++;
        tmpTexture->textureFile=std::string(File);

        //Push the texture onto the back of the vector and return a pointer to it. 
        VidMem::textureList.push_back(tmpTexture);
        return VidMem::textureList.back(); 
    }
    else
    {
        //We did find the texture, add one to its counter and return it. 
        tmpTextureLocation->count++;
        return tmpTextureLocation;
    }
    //This should never be reached, and keeps the compiler happy. 
    return (VidMem*)NULL;
}

bool VidMem::DeleteTexture(void)
{
    // Pointer to use with the GetTextureIterator. This function mallocs memory that we MUST free. 
    std::vector<VidMem*>::iterator *loc;

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

int VidMem::CheckTexture(const char* File)
{
    // Search through the vector
    std::string tmpFile=std::string(File);
    for (std::vector<VidMem*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        // Compare the strings. They function as the id for the object and should be unique. 
        if(tmpFile == (*i)->textureFile)
            return true;
    }
    // We iterated through the entire vector and did not find anything, return false.
    return false;
}

VidMem* VidMem::FindTexture(const char* File)
{
    // Search through the vector
    std::string tmpFile=std::string(File);
    for (std::vector<VidMem*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        // Compare the strings. They function as the id for the object and should be unique. 
        if(tmpFile == (*i)->textureFile)
            return (*i);
    }
    // We iterated though the entire vector, and did not find the texture. 
    return NULL;
}

std::vector<VidMem*>::iterator* VidMem::GetTextureIterator(const char* File)
{    
    // Search through the vector
    std::vector<VidMem*>::iterator *loc=NULL;
    std::string tmpFile=std::string(File);
    for (std::vector<VidMem*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        if(tmpFile == (*i)->textureFile)
        {
            // We found the texture! Return a new iterator to it. 
            // BE AWARE! This new iterator needs to be cleaned at some point!
            // This iterator MAY become invalid if the vector is reallocated as things are 
            //  added and removed. 
            loc=new std::vector<VidMem*>::iterator(i);
            break;
        }
    }

    return loc;
}


unsigned int VidMem::GetX(void)
{
    return 0;
}

unsigned int VidMem::GetY(void)
{
    return 0; 
}

int VidMem::GetXY(int& x,int& y)
{
    return 0;
}

bool VidMem::SetX(int x)
{
    return false;
}

bool VidMem::SetY(int y)
{
    return false;
}

bool VidMem::SetXY(int x,int y)
{
    return false;
}
