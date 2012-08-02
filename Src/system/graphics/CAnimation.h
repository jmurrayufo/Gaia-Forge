#ifndef _CANIMATION_H_
    #define _CANIMATION_H_

#include <SDL.h>

// TODO: We need a "Speed Factor" here. This should allow us to set a given speed of an
//      animation in meters/second and have it speed up/slow down WITH the entity. COOL!

class CAnimation {
    private:
        int    CurrentFrame;

        int     FrameInc;

    private:
        //! Rate for frames to render. This is in Frames/s 
        //! \note This might be easier to store as ms/frame in text, as these numbers give a good range and are easier then a float to process. 
        float     FrameRate;

        //! Speed of the animation in M/S
        float     SpeedFactor;

        //! Last time we called the frame
        long    OldTime;

    public:
        //! Total frames in the animation
        int    MaxFrames;

        //! Is this animation playable forward and backward?
        bool    Oscillate;

    public:
        CAnimation();

        void OnAnimate();

    public:
        void SetFrameRate(int Rate);

        void SetCurrentFrame(int Frame);

        int GetCurrentFrame();
};

#endif
