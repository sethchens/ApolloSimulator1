/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#pragma once


class Velocity;        // for Position::add()
class Acceleration;    // for Position::add()
class TestPosition;    // for the unit tests
class TestLander;      // for the unit tests

/*********************************************
 * POSITION
 * A single position on the screen
 *********************************************/
class Position
{
   friend TestPosition;    // for the unit tests
   friend TestLander;      // for the unit tests
   
public:
   // constructors
   Position()                     : x(0.0),        y(0.0)        { }
   Position(const Position & pos) : x(pos.getX()), y(pos.getY()) { }
   Position(double x, double y)   : x(x),          y(y)          { }

   // getters
   double getX() const { return x; }
   double getY() const { return y; }
   bool operator == (const Position & rhs) const
   {
      return (this->x == rhs.x && this->y == rhs.y);
   }
   bool operator != (const Position & rhs) const
   {
      return (this->x != rhs.x || this->y != rhs.y);
   }

   // setters
   void setX(double x) { this->x = x; }
   void setY(double y) { this->y = y; }
   void addX(double x) { this->x += x; }
   void addY(double y) { this->y += y; }
   void add (const Acceleration & a, const Velocity & v, double t);
   Position & operator = (const Position & rhs)
   {
      x = rhs.getX();
      y = rhs.getY();
      return *this;
   }

private:
   double x;           // horizontal position
   double y;           // vertical position
};

