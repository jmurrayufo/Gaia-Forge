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
    CTexture *tmpTexture,*tmpTextureLocation;


    if((tmpTextureLocation=FindTexture(File))==NULL)
    {
        fprintf(stdout,"NEW FILE!\n");

        tmpTexture=new CTexture;

        tmpTexture->count++;
        tmpTexture->textureFile=std::string(File);
        CTexture::textureList.push_back(tmpTexture);

        // Get the iterator (.end())
        // Dereference it into a CTexture
        // Reference the address and return
        return *(CTexture::textureList.end()); 
    }
    else
    {
        fprintf(stdout,"OLD FILE!\n");

        tmpTextureLocation->count++;

        return tmpTextureLocation;
    }

    return (CTexture*)NULL;
}

bool CTexture::DeleteTexture(void)
{
    return false;
}

int CTexture::CheckTexture(const char* File)
{
    bool foundTexture=false;
    std::string tmpFile=std::string(File);
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != CTexture::textureList.end(); ++i)
    {
        if(tmpFile == (*i)->textureFile)
            foundTexture=true;
    }
    return foundTexture;
}

CTexture* CTexture::FindTexture(const char* File)
{
    CTexture* foundTexture=NULL;
    std::string tmpFile=std::string(File);
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != CTexture::textureList.end(); ++i)
    {
        if(tmpFile == (*i)->textureFile)
            foundTexture=(*i); // FIXME: I dunno if this line works yet...
    }
    return foundTexture;
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
