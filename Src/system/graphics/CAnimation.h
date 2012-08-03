#ifndef _CANIMATION_H_
    #define _CANIMATION_H_

#include <SDL.h>

// TODO: We need a "Speed Factor" here. This should allow us to set a given speed of an
//      animation in meters/second and have it speed up/slow down WITH the entity. COOL!

class CAnimation {
    private:
        int CurrentFrame;
        int FrameInc;

    private:
        //! Rate for frames to render. This is in Frames/s 
        //! \note This might be easier to store as ms/frame in text, as these numbers give a good range and are easier then a float to process. 
        float   FrameRate;

        //! Speed of the animation in M/S
        float   DefaultSpeed;

        //! Last time we called the frame
        long    OldTime;

    public:
        //! Total frames in the animation
        int MaxFrames;

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
                            int cols=1);

        void SetFrameRate(int Rate);

        void SetSpeed(int Speed);

        void SetCurrentFrame(int Frame);

        int GetCurrentFrame();

        int GetCurrentFrame(int& x,int& y);
};

#endif
