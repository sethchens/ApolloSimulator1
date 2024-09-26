/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Seth & Will
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "lander.h"
#include "acceleration.h"
#include <iostream>
using namespace std;

 /***************************************************************
  * RESET
  * Reset the lander and its position to start the game over
  ***************************************************************/
void Lander :: reset(const Position & posUpperRight)
{
   status = PLAYING;
   angle.setRadians(0.0);
   fuel = 5000.0;   
   velocity.setDX(random(-10.0, -4.0));
   velocity.setDY(random(-2.0, 2.0));
   pos.setX(posUpperRight.getX() - 1);
   pos.setY(random(posUpperRight.getY() * .75, posUpperRight.getY() * .95));
}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander :: draw(const Thrust & thrust, ogstream & gout) const
{
   if (thrust.isMain())
   {
      gout.drawLander(pos, angle.getRadians());
      gout.drawLanderFlames(pos, angle.getRadians(), thrust.isMain(), thrust.isClock(), thrust.isCounter());
   }
   else
      gout.drawLander(pos, angle.getRadians());
   
}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander :: input(const Thrust& thrust, double gravity)
{
   Acceleration accelaration;
   
   accelaration.set(angle, (fuel >= 10.0 ? (thrust.isMain() ? thrust.mainEngineThrust() : 0.0) : 0.0));
   accelaration.setDDX(accelaration.getDDX() * -1.0);
   accelaration.addDDY(gravity);
   
   fuel -= (fuel >= 10.0 ? (thrust.isMain() ? 10.0 : 0.0) : 0.0);
   fuel -= (fuel >= 1.0 ? (thrust.isClock() ? 1.0 : 0.0) : 0);
   fuel -= (fuel >= 1.0 ? (thrust.isCounter() ? 1.0 : 0.0) : 0.0);
   angle.setRadians(angle.getRadians() + thrust.rotation());
   
   return accelaration;
}

/******************************************************************
 * COAST
 * What happens when we coast?
 *******************************************************************/
void Lander :: coast(Acceleration & acceleration, double time)
{
   velocity.addDX(acceleration.getDDX() * time);
   velocity.addDY(acceleration.getDDY() * time);
   pos.setX(pos.getX() + velocity.getDX() * time + acceleration.getDDX() * 0.5 * (time * time));
   pos.setY(pos.getY() + velocity.getDY() * time + acceleration.getDDY() * 0.5 * (time * time));
}

