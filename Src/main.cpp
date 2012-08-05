
#include <iostream>
#include <string>
#include <SDL.h>

#include "capp/CApp.h"
#include "system/noise/Noise.h"

using namespace std;

//Johns Test comment
//==============================================================================
int main(int argc, char* argv[]) {
    Noise x;

    x.test();

    return(0);

    CApp theApp;
    fprintf(stdout,"Booted main()\n   %s:%d\n",__FILE__,__LINE__);
    return theApp.OnExecute();
}
//==============================================================================

// TODO: Move this to a template or notes folder...
/*
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
void print(boost::property_tree::ptree const& pt,int indent)
{
    using boost::property_tree::ptree;
    ptree::const_iterator end = pt.end();
    for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
        for(int i = 0;i<indent;i++)
            cout << "    ";
        std::cout << it->first << ": " << it->second.get_value<std::string>() << std::endl;
        print(it->second,indent+1);
    }
}
*/

/*
    
    double ground[10];
    double y,y0,y1,y2,y3;
    double t;

    for (int i = 0; i < 10; ++i)
    {
        cout << i << "," << x.Perlin1d(i) << endl;
    }

    cout << "\nINTERP TIME!\n" << endl;
    for (int i = 0; i < 1024; ++i)
    {
        y=(int)i/102.4;
        y0=x.Perlin1d(y-1);
        y1=x.Perlin1d(y);
        y2=x.Perlin1d(y+1);
        y3=x.Perlin1d(y+2);
        t=fmod(i/102.4,1.f);
        cout    << i 
                << "," << x.InterpLin(y1,y2,t) 
                << "," << x.InterpCos(y1,y2,t) 
                << "," << x.InterpCubic(y0,y1,y2,y3,t) 
                << endl;
    }
    */