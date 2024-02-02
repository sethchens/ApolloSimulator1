/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
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
   Angle()                 : radians(-99.9)  {}
   Angle(const Angle& rhs) : radians(-99.9)  {}
   Angle(double degrees)   : radians(-99.9)  {}

   // Getters
   double getDegrees() const { return -99.9; }
   double getRadians() const { return -99.9; }

   // Setters
   void setDegrees(double degrees) { }
   void setRadians(double radians) { }
   void setUp()                    { }
   void setDown()                  { }
   void setRight()                 { }
   void setLeft()                  { }
   void reverse()                  { }
   Angle& add(double delta) { radians = -99.9; return *this; }

private:
   double normalize(double radians) const;

   double radians;   // 360 degrees equals 2 PI radians
};

