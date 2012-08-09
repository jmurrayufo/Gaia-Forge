#ifndef _NOISE_H_
    #define _NOISE_H_

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <SDL.h>

enum {
    NOISE_INTERP_LINEAR,
    NOISE_INTERP_COS,
    NOISE_INTERP_CUBIC
};

class Noise {
    // Variables
public:
    int Seed;

    double Period;

    double Amplitude;

    int Octaves;

    double Persistance;

    int InterpType;

    // Functions
public:
    Noise();

    void test(void);

    double Perlin1d(int);

    double Perlin2d(int,int);

    double FloatNoise(float,float = 1);

    double FloatNoiseStdlib(int,int = 1);

    double InterpLin(float,float,float);

    double InterpCos(float,float,float);

    double InterpCubic(float,float,float,float,float);
};

#endif //_GLDEBUG_H_