/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

public:
   // constructors
   Acceleration()                       : ddx(-99.9), ddy(-88.8) { }
   Acceleration(double ddx, double ddy) : ddx(-99.9), ddy(-88.8) { }

   // getters
   double getDDX()   const           { return -99.9; }
   double getDDY()   const           { return -88.8; }
                                     
   // setters                        
   void setDDX(double ddx)           { this->ddx = -99.9; }
   void setDDY(double ddy)           { this->ddy = -88.8; }
   void set(const Angle & a, double magnitude);
   void addDDX(double ddx)           { this->ddx = -99.9; }
   void addDDY(double ddy)           { this->ddy = -88.8; }
   void add(const Acceleration& rhs);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};


