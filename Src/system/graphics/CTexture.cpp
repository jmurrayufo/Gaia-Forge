#include "CTexture.h"


CTexture::CTexture()
{

}

CTexture::~CTexture()
{
    //Void
}

bool CTexture::OnLoad(const char* File)
{
    int tmp = DetermineFileType(File);
    if(tmp == CTEXTURE_FILE_TYPE_PNG)
    {
        // Load the PNG directly
    }
    else if(tmp == CTEXTURE_FILE_TYPE_JSON)
    {
        // Load the file from a JSON object
    }
    return tmp;
}

bool CTexture::OnLoad(std::string File)
{
    // Cal the OnLoad(const Char* File) function
}

void CTexture::OnLoop(void)
{

}

void CTexture::OnLoop(int speed)
{

}

void CTexture::OnRenderGL(int x, int y)
{

}

void CTexture::OnCleanup(void)
{

}

bool CTexture::GetHasState(void)
{

}

int CTexture::GetState(void)
{

}

bool CTexture::SetState(int state)
{

}

bool CTexture::ConfigState( int state,
                            int x,
                            int y,
                            int tiles,
                            bool oscillation,
                            int cols)
{

}


int CTexture::DetermineFileType(const char* File)
{
    std::string FileString(File);
    int extentionPosition;

    // Locate the last "." in the file name, we assume that the extension comes after this. 
    extentionPosition = FileString.find_last_of(".");

    // If we didn't find ANY "." then we have an invalid file type.
    if(extentionPosition==std::string::npos)
        return CTEXTURE_FILE_TYPE_INVALID;

    FileString = FileString.substr(extentionPosition+1);

    // These if's could be a switch case?
    if(FileString == "png")
    {
        return CTEXTURE_FILE_TYPE_PNG;
    }
        

    if(FileString == "json")
    {
        return CTEXTURE_FILE_TYPE_JSON;
    }

    // If we didn't find it, just return invalid. 
    return CTEXTURE_FILE_TYPE_INVALID;
}