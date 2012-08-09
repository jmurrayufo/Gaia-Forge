
#include "stdlib.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <iostream>
#include <sstream>
#include <SDL.h>
#include <string>

#include "../../Define.h"
#include "../../lib/lodepng.h"

void CaptureScreenShot();

//void CaptureScreenShot(string file);

void CaptureScreenShot(const char* file);

// Draw a box to the screen 
void DrawBox(int,int,float,float,float*);