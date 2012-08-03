#include "CAnimation.h"

CAnimation::CAnimation() 
{
   currentFrame=0;
   frameInc=true;
   frameRate=1000;
   defaultSpeed=10;
   oldTime=0;
   x=0;
   y=0;
   tiles=1;
   cols=1;
   oscillate=false;
}

void CAnimation::OnAnimate() 
{
   // Check to see if enough time has passed to update the animation
   if((Uint32)oldTime + frameRate > SDL_GetTicks()) 
   {
      return;
   }

   // New frame! Save the time
   oldTime = SDL_GetTicks();
   currentFrame += frameInc ? 1 : -1 ; // Any chance to use the ternary is fun!

   if(oscillate) 
   {
      if(currentFrame == tiles || currentFrame == 0) 
      {
         frameInc = !frameInc;
      }
   } else {
      if(currentFrame == tiles) 
      {
         currentFrame = 0;
      }
   }
}

void CAnimation::SetFrameRate(int Rate) 
{
   frameRate = Rate;
}

void CAnimation::SetCurrentFrame(int Frame) 
{
   if(Frame < 0 || Frame >= tiles) return;

   currentFrame = Frame;
}

int CAnimation::GetCurrentFrame() 
{
   assert(cols==1); // We should NEVER call this function if we have columns! 
   return currentFrame;
}

int CAnimation::GetCurrentFrame(int& X,int& Y)
{
   X = x + currentFrame % cols;
   Y = y + currentFrame / cols;
}
