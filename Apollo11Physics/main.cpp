/*************************************************************
 * 1. Name:
 *      Seth Chen, Will Chen
 * 2. Assignment Name:
 *      Practice 02: Physics simulator
 * 3. Assignment Description:
 *      Compute how the Apollo lander will move across the screen
 * 4. What was the hardest part? Be as specific as possible.
 *      No difficult so far. This assignment gets us a chance
 *      to be familiar with the syntax and small tricks in C++
 * 5. How long did it take for you to complete the assignment?
 *      4 hrs
 **************************************************************/

#include <iostream>  // for CIN and COUT
#include <cmath> // for suqare root and M_PI
#include <cassert> // for assertion
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
double computeDistance(double s, double v, double a, double t)
{
   // Calculate new position.
   return s + (v * t) + (.5 * a * (t * t));
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
double computeAcceleration(double f, double m)
{
   assert (m != 0.0);
    return f / m;
}

/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
double computeVelocity(double v, double a, double t)
{
      // Calculate new velocity.
   return v + (a * t);
}


/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
double computeVericalComponent(double a, double total)
{
   return cos(a) * total;
}

/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |      /
 *   y |    / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the horizontal component of the total
 ***********************************************/
double computeHorizontalComponent(double a, double total)
{
   // Calculate the vertical component of the total.
   return sin(a) * total;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |    /
 *   y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double computeTotalComponent(double x, double y)
{
   double total = sqrt((x * x) + (y * y));
   assert(total >= 0);
   return total;
}


/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double radiansFromDegrees(double d)
{
   // Calculate radians from 0 to 2pi.
   return (d / 360) * (2 * M_PI);
}

/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
double prompt(string message)
{
   // Prompt the mesage to user and get their rresponse.
   double response;
   cout << message << endl;
   cin >> response;
   return response;
}

/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
    // Prompt for input and variables to be computed.
    double dx =       prompt("What is your horizontal velocity (m/s)? ");
    double dy =       prompt("What is your vertical velocity (m/s)? ");
    double y =        prompt("What is your altitude (m)? ");
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double x =        0.0;
    double t =        1.0;
    double aRadians;            // Angle in radians
    double accelerationThrust;  // Acceleration due to thrust
    double ddxThrust;           // Horizontal acceleration due to thrust
    double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double v;                   // Total velocity
   
    // Compute accelleration
    aRadians = radiansFromDegrees(aDegrees);
    accelerationThrust = computeAcceleration(THRUST, WEIGHT); // Calculate the initial acceleration
    ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);
    ddyThrust = computeVericalComponent(aRadians, accelerationThrust);
    ddx = ddxThrust;
    ddy = ddyThrust + GRAVITY;
   
    // Go through the simulator five times
   for (int i = 1; i < 11; i ++)
   {
      if (i == 6)
      {
         aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
         
         // Compute accelleration
         aRadians = radiansFromDegrees(aDegrees);
         accelerationThrust = computeAcceleration(THRUST, WEIGHT); // Calculate the initial acceleration
         ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);
         ddyThrust = computeVericalComponent(aRadians, accelerationThrust);
         ddx = ddxThrust;
         ddy = ddyThrust + GRAVITY;
      }
      
      // Compute things
      dx = computeVelocity(dx, ddx, t);
      dy = computeVelocity(dy, ddy, t);
      
      x = computeDistance(x, dx, ddx, t);
      y = computeDistance(y, dy, ddy, t);
      v = computeTotalComponent(dx, dy);
      
      // Output
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(2);
      cout << i << "s - x, y: (" << x << ", " << y << ")m/s ";
      cout << "dx, dy: (" << dx << ", " << dy << ")m/s ";
      cout << "speed: " << v << "m/s ";
      cout << "angle: " << aDegrees << "deg" << endl;
   }


      return 0;
}
