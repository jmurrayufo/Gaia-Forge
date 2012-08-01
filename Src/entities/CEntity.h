#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <vector>
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h> // DEBUG

#include "..\lib\lodepng.h"

#include "CAnimation.h"
#include "..\system\controls\CCamera.h"
#include "..\system\controls\CFPS.h"
#include "..\system\render\GLDebug.h"

enum {
    ENTITY_TYPE_GENERIC = 0,

    ENTITY_TYPE_PLAYER
};

enum {
    ENTITY_FLAG_NONE     = 0,

    ENTITY_FLAG_GRAVITY     = 0x00000001 << 0,
    ENTITY_FLAG_GHOST       = 0x00000001 << 1,
    ENTITY_FLAG_MAPONLY     = 0x00000001 << 2
};

class CEntity {
    public:
        static std::vector<CEntity*>    EntityList;

    protected:
        //! Store the animation information to correctly draw each frame. 
        CAnimation      Anim_Control;

        SDL_Surface*    Surf_Entity; //To be removed
        GLuint          texture;         // This is a handle to our texture object

        // Texture sizes. These should eventaully be moved to the texture handling class. 
        unsigned int    tex_height;
        unsigned int    tex_width;
    public:
        float           X;
        float           Y;

        int             Width;
        int             Height;

        bool        MoveLeft;
        bool        MoveRight;

    public:
        int        Type;

        bool        Dead;
        int        Flags;

    protected:
        float        SpeedX;
        float        SpeedY;

        float        AccelX;
        float        AccelY;

    public:
        float        MaxSpeedX;
        float        MaxSpeedY;

    protected:

        int     CurrentFrameCol;
        int     CurrentFrameRow;
        int     Col_X;
        int     Col_Y;
        int     Col_Width;
        int     Col_Height;
        bool    CanJump;

   public:
      bool     Jump();
    public:
        CEntity();

        virtual ~CEntity();

    public:
        virtual bool OnLoad(const char* File, int Width, int Height, int MaxFrames);

        virtual bool OnLoadGL();

        virtual bool OnLoadGL(const char* File);

        virtual void OnLoop();

        virtual void OnRender(SDL_Surface* Surf_Display);

        virtual void OnRenderGL();

        virtual void OnCleanup();

        virtual void OnAnimate();

        virtual bool OnCollision(CEntity* Entity);

    public:
        void    OnMove(float MoveX, float MoveY);

        void     StopMove();

    public:
        bool    Collides(int oX, int oY, int oW, int oH);

    private:
        bool     PosValid(int NewX, int NewY);

        //bool     PosValidTile(CTile* Tile); // Cuurently removed becuase we dont have a tile system in place...

        bool     PosValidEntity(CEntity* Entity, int NewX, int NewY);
};

class CEntityCol {
    public:
        static std::vector<CEntityCol>    EntityColList;

    public:
        CEntity* EntityA;
        CEntity* EntityB;

    public:
        CEntityCol();
};

#endif
