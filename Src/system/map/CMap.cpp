#include "CMap.h"

CMap::CMap() {
    X=0;
    Y=0;
    for (int i = 0; i < MAP_WORLD_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_WORTH_HEIGHT; ++j)
        {
            Chunks[i][j]=NULL;
        }
    }
}

CMap::~CMap() {
        for (int i = 0; i < MAP_WORLD_WIDTH; ++i)
    {
        for (int j = 0; j < MAP_WORTH_HEIGHT; ++j)
        {
            delete Chunks[i][j];
        }
    }
}