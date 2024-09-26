/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Seth & Will
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
* ANGLE
************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;
   
   // Constructors
   Angle()                 : radians(0.0)  {}
   Angle(const Angle& rhs) : radians(rhs.getRadians())  {}
   Angle(double degrees)   : radians(0.0)  {}

   // Getters
   double getDegrees() const { return radians * (180.0 / M_PI); }
   double getRadians() const { return radians; }

   // Setters
   void   setDegrees(double degrees) { radians = normalize(degrees * (M_PI / 180.0)); }
   void   setRadians(double radians) { this->radians = normalize(radians); }
   void   setUp()                    { radians = 0.00; }
   void   setDown()                  { radians = M_PI; }
   void   setRight()                 { radians = M_PI_2; }
   void   setLeft()                  { radians = M_PI + M_PI_2; }
   void   reverse()                  { radians = M_PI_2 + M_PI; }
   Angle& add(double delta)          { radians += normalize(delta); return *this; }

private:
   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

