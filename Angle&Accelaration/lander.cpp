/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "lander.h"
#include "acceleration.h"

 /***************************************************************
  * RESET
  * Reset the lander and its position to start the game over
  ***************************************************************/
void Lander :: reset(const Position & posUpperRight)
{
   status = PLAYING;
   angle.setRadians(0.0);
   pos.setX(99.0);
   fuel = 5000.0;
   velocity.setDX(random(-10.0, -4.0));
   velocity.setDY(random(-2.0, 2.0));
   pos.setX(99.0);
   pos.setY(random(75.0, 95.0));
}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander :: draw(const Thrust & thrust, ogstream & gout) const
{
   gout.drawLander(pos, angle.getRadians());
   if (status == DEAD)
      gout.drawLanderFlames(pos, angle.getRadians());
   
}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander :: input(const Thrust& thrust, double gravity)
{
   Acceleration accelaration;
   accelaration.setDDX((thrust.isMain() ? thrust.mainEngineThrust() : 0.0) * (angle.getRadians() != 0.0 ? cos(angle.getRadians()) : 1.0)          );
   accelaration.setDDY((thrust.isMain() ? thrust.mainEngineThrust() : 0.0) * (angle.getRadians() != 0.0 ? sin(angle.getRadians()) : 1.0) + gravity);
   fuel -= (thrust.isMain() ? 10.0 : 0.0);
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

