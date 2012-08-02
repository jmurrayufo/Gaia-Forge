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
        tmpTexture=new CTexture;
        tmpTexture->count++;
        tmpTexture->textureFile=std::string(File);
        CTexture::textureList.push_back(tmpTexture);
        return CTexture::textureList.back(); 
    }
    else
    {
        tmpTextureLocation->count++;
        return tmpTextureLocation;
    }
    return (CTexture*)NULL;
}

bool CTexture::DeleteTexture(void)
{
    std::vector<CTexture*>::iterator *loc;

    this->count--;

    if(count<1)
    {
        loc=GetTextureIterator(textureFile.c_str());
        textureList.erase(*loc);
        delete loc;
        delete this;
        return true;
    }
    return false;
}

int CTexture::CheckTexture(const char* File)
{
    bool foundTexture=false;
    std::string tmpFile=std::string(File);
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
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
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        if(tmpFile == (*i)->textureFile)
            foundTexture=(*i); // FIXME: I dunno if this line works yet...
    }
    return foundTexture;
}

std::vector<CTexture*>::iterator* CTexture::GetTextureIterator(const char* File)
{
    std::vector<CTexture*>::iterator *loc=NULL;
    std::string tmpFile=std::string(File);
    for (std::vector<CTexture*>::iterator i = textureList.begin(); i != textureList.end(); ++i)
    {
        if(tmpFile == (*i)->textureFile)
        {
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
