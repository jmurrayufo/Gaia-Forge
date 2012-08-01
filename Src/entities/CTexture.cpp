#include "CTexture.h"

// We must declare static members someplace, here works!
std::vector<CTexture> CTexture::textureList;

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
    CTexture tmpTexture;

    if(CheckTexture(File)==0)
    {
        fprintf(stdout,"NEW FILE!\n");
        tmpTexture.count++;
        tmpTexture.textureFile=std::string(File);
        CTexture::textureList.push_back(tmpTexture);

        // Get the iterator (.end())
        // Dereference it into a CTexture
        // Reference the address and return
        return &(*(CTexture::textureList.end())); 
    }
    else
    {
        fprintf(stdout,"OLD FILE!\n");
        fprintf(stdout,"   Got: %d\n",CheckTexture(File));
        // We don't yet FIND the old texture.... CheckTexture might need to get changed!
        // Maybe we need a FindTexture function that returns a pointer to a found texture?
        return (CTexture*)NULL;
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
    for (std::vector<CTexture>::iterator i = textureList.begin(); i != CTexture::textureList.end(); ++i)
    {
        if(tmpFile == i->textureFile)
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
