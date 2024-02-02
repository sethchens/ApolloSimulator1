/***********************************************************************
 * Header File:
 *    GROUND
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Where the ground is located and where the landing pad is located
 ************************************************************************/

#pragma once

#include "position.h"   // for Point
#include "uiDraw.h"  // for ogstream


 /***********************************************************
  * GROUND
  * The ground class
  ***********************************************************/
class Ground
{
public:
   // the constructor generates the ground
   Ground(const Position & posUpperRight);

   // reset the game
   void reset();

   // draw the ground on the screen
   void draw(ogstream & gout) const;

   // determine how high the Point is off the ground
   double getElevation(const Position & pos) const
   {
      if (pos.getX() >= 0.0 && pos.getX() < posUpperRight.getX())
         return pos.getY() - ground[(int)pos.getX()];
      else
         return 0.0;
   }

   // on the platform
   bool onPlatform(const Position& position, int landerWidth) const;

   // hit the ground
   bool hitGround(const Position& position, int landerWidth) const;

private:
   double * ground;               // the ground array, expressed in elevation 
   long    iLZ;                   // the left-most location of the landing zone (LZ)
   Position posUpperRight;        // the width and height of the world
};
