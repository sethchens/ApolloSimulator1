/***********************************************************************
 * Header File:
 *    User Interface Draw : put pixels on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This is the code necessary to draw on the screen. We have a collection
 *    of procedural functions here because each draw function does not
 *    retain state. In other words, they are verbs (functions), not nouns
 *    (variables) or a mixture (objects)
 ************************************************************************/

#pragma once

#include <string>     // To display text on the screen
#include <cmath>      // for M_PI, sin() and cos()
#include <algorithm>  // used for min() and max()
#include <sstream>    // for OSTRINGSTRING
#include "position.h" // Where things are drawn
using std::string;
using std::min;
using std::max;


/*************************************************************************
 * GRAPHICS STREAM
 * A graphics stream that behaves much like COUT except on a drawn screen.
 * Special methods are added to facilitate drawing simulator elements.
 *************************************************************************/
class ogstream : public std::ostringstream
{
public:
   ogstream()                    : pos()    {          }
   ogstream(const Position& pos) : pos(pos) {          }
   ~ogstream()                              { flush(); }
   
   // Methods specific to drawing text on the screen
   void flush();
   void setPosition(const Position& pos) { flush(); this->pos = pos; }
   ogstream& operator = (const Position& pos)
   {
      setPosition(pos);
      return *this;
   }
   
   // Methods specific to drawing simulator elements on the screen
   virtual void drawLander(      const Position& pos = Position(),
                                 double angle = 0.0);

   virtual void drawLanderFlames(const Position& pos = Position(),
                                 double angle = 0.0,
                                 bool bottom = false,
                                 bool left   = false,
                                 bool right  = false);

   virtual void drawStar(        const Position& pt = Position(),
                                 unsigned char phase = 0);

   virtual void drawRectangle(   const Position & posBegin,
                                 const Position & posEnd,
                                 double red    = 1.0,
                                 double green  = 1.0,
                                 double blue   = 1.0) const;

   virtual void drawLine(        const Position & posBegin,
                                 const Position & posEnd,
                                 double red   = 1.0,
                                 double green = 1.0,
                                 double blue  = 1.0) const;
protected:
   Position pos;
   
private:
   Position rotate(const Position & posOrigin, double x, double y,
                   double rotation = 0.0) const;
   
   void drawText(const Position & posTopLeft, const char * text) const;

};

/******************************************************************
 * RANDOM
 * This function generates a random number.  The user specifies
 * The parameters 
 *    INPUT:   min, max : The number of values (min <= num <= max)
 *    OUTPUT   <return> : Return the integer
 ****************************************************************/
int    random(int    min, int    max);
double random(double min, double max);

