#include "Noise.h"


Noise::Noise()
{
    Seed=0;

    Period=1;

    Amplitude=1;

    Octaves=1;

    Persistance=1;

    InterpType=NOISE_INTERP_CUBIC;
}

void Noise::test(void)
{
    int start=SDL_GetTicks();
    int i;
    Period=100;
    Octaves=50;
    Amplitude=10;
    Persistance=2;
    InterpType=NOISE_INTERP_CUBIC;

    i=0;
    while(SDL_GetTicks() - start < 1000)
    {
        std::cout << i << "," << Perlin1d(i) << std::endl;
        i++;
    }


    return;

}

double Noise::Perlin1d(int x)
{
    double total=0;
    double p=Period;
    double a=Amplitude;
    for(int i=0;i<Octaves;i++)
    {
        //std::cout << "   " << "P:" << p << " A:" << a << std::endl;
        if(p==0 || a==0)
            break;
        switch(InterpType)
        {
        case NOISE_INTERP_LINEAR:
            double y0,y1;
            y0=FloatNoise((int)(x / p));
            y1=FloatNoise((int)(x / p) + 1);
            //std::cout << "      " << "Y0:" << y0 << " Y1:" << y1 << std::endl;
            total += InterpLin(y0,y1,fmod(x/p,1)) * a;
            break;
        case NOISE_INTERP_CUBIC:
            double n0,n1,n2,n3;
            n0=FloatNoise((int)x / p - 1);
            n1=FloatNoise((int)x / p);
            n2=FloatNoise((int)x / p + 1);
            n3=FloatNoise((int)x / p + 2);
            total += InterpCubic(n0,n1,n2,n3,fmod(x/p,1)) * a;
            break;
        }
        p = p / 2;
        a = a / Persistance;
    }
    return total;
}

double Noise::FloatNoise(float x,float y)
{
    int n = x + y * 57;
    n = (n << 13) ^ n;
    int t = (n * (n * n * 15731 + 789221) + 1376312589 * Seed * Seed) & 0x7fffffff;
    return 1.0 - double(t) * 0.931322574615478515625e-9;/// 1073741824.0); 
}          

double Noise::FloatNoiseStdlib(int x,int y)
{
    srand(Seed*Seed*98809 + 15731*x*x + 13339*y*y);
    int n=rand();
    return (double)n/RAND_MAX;
}      

double Noise::InterpLin(float a,float b,float x)
{   
    return a*(1-x)+b*x;
}

double Noise::InterpCos(float a,float b,float x)
{
    x = x * 3.14159265359;
    x = (1 - cos(x)) * 0.5;
    return a*(1-x)+b*x;

}

double Noise::InterpCubic(float v0,float v1,float v2,float v3,float x)
{
    double P = (v3 - v2) - (v0 - v1);
    return  P * x * x * x +
            ((v0 - v1) - P) * x * x +
            (v2 - v0) * x +
            v1;
}
    