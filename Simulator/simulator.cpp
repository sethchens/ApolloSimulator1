
/**********************************************************************
 * LAB 06
 * Author:  Seth and Will
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "acceleration.h"// for ACCELERATION
#include "lander.h"      // for LANDER
#include "star.h"        // for STAR
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
using namespace std;


#define DURATION 0.1           // Duration per frame
#define GRAVITY -1.625         // Acceleration caused by gravity
#define NUM_STARS 50           // Number of stars on the screen
#define SIMULATOR_WIDTH 400.0  // Simulator width
#define SIMULATOR_HEIGHT 400.0 // Simulator height

/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight) : ground(posUpperRight), lander(posUpperRight), posUpperRight(posUpperRight)
   {
      // Create and initialize stars
      for (int i = 0; i < NUM_STARS; i ++)
      {
         Star star;
         star.reset(posUpperRight.getX(), posUpperRight.getY());
         stars.push_back(star);
      }
      
      // reset everything so everything is ready to go
      reset(posUpperRight);
   }
   
   // Reset everything when crashed
   void reset         (const Position &posUpperRight       );
   
   // Turns user inputs into Thrust object
   void input(const Interface &pUI, Thrust &thrust         );
   
   // Draw Star, Lander, and Ground
   void display       (const Thrust &thrust                );
   
   // Display status of Lander
   void displayStatus (const Lander &lander, ogstream &gout);
   
   // Handle collision
   void collide       (                                    );
   
   // Get Lander object
   Lander getLander   () { return lander; }
   
private:
   // Vector to store stars
   vector<Star> stars;
   Lander lander;
   Ground ground;
   ogstream gout;
   Position posUpperRight;
};

/*****************************************
 * DISPLAY
 * Draw lander, ground, stars, status, and message on the screen
 * *************************************************************/
void Simulator::display(const Thrust &thrust)
{
   // Draw stars
   for (auto& star : stars)
      star.draw(gout);
   
   // Draw ground
   ground.draw(gout);
   
   // Draw lander
   lander.draw(thrust, gout);
   
   // Display fuel, altitude, and speed
   Position textPosition(SIMULATOR_WIDTH * 0.025, SIMULATOR_HEIGHT * 0.95);
   gout.setPosition(textPosition);
   gout << "fuel:     " << to_string(lander.getFuel()) << endl
        << "altitude: " << to_string(int(ground.getElevation(lander.getPosition()))) << endl
        << "speed:    " << to_string(int(lander.getSpeed()));
   
   // Display message based on lander status
   Position messagePosition(SIMULATOR_WIDTH * 0.375, SIMULATOR_HEIGHT * 0.75);
   gout.setPosition(messagePosition);
   if (lander.isDead())
      gout << "Armstrong you suck!" << endl;
   else if (lander.isLanded())
      gout << "Armstrong your arm's strong!" << endl;
}

/*****************************************
 * INPUT
 *  turn input into acceleration and apply to the lander
 * *************************************************************/
void Simulator::input(const Interface &pUI, Thrust &thrust)
{
   // Set the thrust based on user input
   thrust.set(&pUI);
   
   // Get acceleration based on thrust and gravity
   Acceleration a = lander.input(thrust, GRAVITY);
   
   // Apply acceleration to the lander
   lander.coast(a, DURATION);
}

/*****************************************
 * RESET
 * restart simulator
 * *************************************************************/
void Simulator::reset(const Position &posUpperRight)
{
   // Reset stars, lander, and ground
   for (auto& star: stars)
      star.reset(posUpperRight.getX(), posUpperRight.getY());
   lander.reset(posUpperRight);
   ground.reset();
}

/*****************************************
 * COLLIDE
 * handle the collision situation
 * *************************************************************/
void Simulator::collide()
{
   // Check if lander has hit the ground or landed on platform
   if (ground.hitGround(lander.getPosition(), lander.getWidth()))
   {
      lander.crash();
   }
   else if (ground.onPlatform(lander.getPosition(), lander.getWidth()))
      lander.getSpeed() <= 4 ? lander.land() : lander.crash();
      
}

/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // Cast the void pointer to a Simulator object
   Simulator * pSimulator = (Simulator *)p;
   
   // Create Thrust object
   Thrust thrust;
   
   // Initiate posUpperRight
   Position position(400, 400);

   // Handle collision
   pSimulator->collide();
   
   // If lander is flying, get user input and draw everything
   if (pSimulator->getLander().isFlying())
   {
      pSimulator->input(*pUI, thrust);
      pSimulator->display(thrust);
   }
   // If lander is dead, display everything
   else if (pSimulator->getLander().isDead())
   {
      pSimulator->display(thrust);
      if (pUI->isSpace())
         pSimulator->reset(position);
      else if (pUI->isQ())
         exit(0);
   }
   // Otherwise, display everything
   else
      pSimulator->display(thrust);
      if (pUI->isSpace())
         pSimulator->reset(position);
   else if (pUI->isQ())
      exit(0);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my LM type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char** argv)
{
   // Run unit tests
   testRunner();
   
   // Initialize OpenGL
   Position posUpperRight(400, 400);
   Interface ui("Lunar Lander", posUpperRight);
   
   // Initialize Simulator object
   Simulator simulator(posUpperRight);

   // Run the simulator
   ui.run(callBack, (void *)&simulator);

   return 0;
}
