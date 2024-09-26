/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Seth & Will
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

 /************************************
  * ANGLE : NORMALIZE
  ************************************/
double Angle::normalize(double radians) const
{
   while (radians > 2.0 * M_PI || radians < 0.0)
   {
      if (radians >= 2.0 * M_PI)
         radians -= 2.0 * M_PI;
      else if (radians < 0.0)
      {
         radians += 2.0 * M_PI;
      }
      
   }
   
   assert(0.0 <= radians && radians <= 2.0 * M_PI);
   return radians;
}



