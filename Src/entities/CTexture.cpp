#include "CTexture.h"

// We must declare static members someplace, here works!
std::vector<CTexture> textureList;

CTexture::CTexture()
{
    //Void
}

CTexture::~CTexture()
{
    //Void
}

CTexture* CTexture::InitTexture(const char* File)
{
    CTexture *tmpTexture=NULL;

    return tmpTexture;
}

bool CTexture::DeleteTexture(void)
{
    return false;
}

int CTexture::CheckTexture(const char* File)
{
    bool foundTexture=false;
    for (std::vector<CTexture>::iterator i = CTexture::textureList.begin(); i != CTexture::textureList.end(); ++i)
    {
        if(memcmp(File,i->textureFile,256)!=0)
            foundTexture=true;
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
