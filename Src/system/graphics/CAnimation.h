#ifndef _CANIMATION_H_
    #define _CANIMATION_H_

#include <SDL.h>
#include <assert.h>

/*!
    \brief Maintain a counter for animation. 
*/

class CAnimation 
{
public:
    //! Current frame index
    int currentFrame;

    //! Frame increment. If false, frames will count down instead. 
    bool frameInc;

    //! Rate for frames to render. This is in ms/frame
    float   frameRate;

    //! Speed of the animation in M/S
    float   defaultSpeed;

    //! Last time we called the frame
    long    oldTime;

// Sub Texture Details
public:
    //! Left most pixel of this animation
    int x;

    //! Top most pixel of this animation
    int y;

    //! Number of tiles in the entire animation
    int tiles;

    //! Number of columns in the animation 
    int cols;

    //! Is this animation playable forward and backward?
    bool oscillate;

public:
    CAnimation();

    void OnAnimate();

public:
    bool ConfigState(   int x,
                        int y,
                        int tiles=1,
                        bool oscillation=false,
                        int cols=1
                    );

    void SetFrameRate(int Rate);

    // Unimplemented
    void SetSpeed(int Speed);

    void SetCurrentFrame(int Frame);

    int GetCurrentFrame();

    int GetCurrentFrame(int& X,int& Y);
};

#endif
