#ifndef _CPLAYER_H_
    #define _CPLAYER_H_

#include "..\CEntity.h"

class CPlayer : public CEntity {
    public:
        CPlayer();

        bool OnLoad(const char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);
};

#endif
