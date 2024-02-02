/***********************************************************************
 * Source File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>

/*********************************************
 * ACCELERATION : ADD
 *  a += a
 *********************************************/
void Acceleration::add(const Acceleration& acceleration)
{
   ddx = -99.9;
   ddy = -88.8;
}

/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle & angle, double magnitude)
{
   ddx = -99.9;
   ddy = -88.8;
}
