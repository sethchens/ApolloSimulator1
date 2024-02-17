/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich, jason Chandler Tyler Lefevre
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR

/*****************************************************
 * STAR
 * A star that twinkles
 *****************************************************/
class Star
{
private:
   Position pos;
   unsigned char phase;
public:
   Star()
   {
      Position pos;
      phase = 0;
   }
   
   // Randomize star position and phase.
   void reset(double width, double height)
   {
      pos.setX(random(0.0, width));
      pos.setY(random(0.0, height));
      phase = random(0,256);
   }
   
   // Draw start then increment its phase.
   void draw(ogstream & gout)
   {
      gout.drawStar(pos, phase);
      phase++;
   }
};
