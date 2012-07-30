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
        int     FrameRate; //Milliseconds

        //! Speed of the animation in M/S
        int     SpeedFactor;

        long    OldTime;

    public:
        int    MaxFrames;

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
