/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
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
   Position pos;        // Position
   unsigned char phase; // Phase

public:
   // Constructors
   Star() : pos(), phase(0) {}
   Star(const Position& initialPos) : pos(initialPos), phase(0) {}

   // Method to draw the star with an ogstream object
   void draw(ogstream& gout) {
      gout.drawStar(pos, phase);
      // Increase the phase after drawing
      phase++;
   }
   
   void reset(double width, double height) {
      pos.setX(random(0.0, width));
      pos.setY(random(0.0, height));
      phase++;
   }

 
};
