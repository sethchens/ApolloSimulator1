/***********************************************************************
 * Header File:
 *    TEST LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for LANDER
 ************************************************************************/

#pragma once


#include "lander.h"
#include "position.h"
#include "acceleration.h"

/*******************************
 * TEST LANDER
 * A friend class for Lander which contains the Lander unit tests
 ********************************/
class TestLander : public UnitTest
{
public:
   void run()
   {
      
      // getters
      isDead_dead();
      isDead_alive();
      isLanded_landed();
      isLanded_flying();
      isFlying_landed();
      isFlying_flying();
      getFuel_empty();
      getFuel_some();
      getWidth();
      getMaxSpeed();
      getPosition_zero();
      getPosition_middle();
      getSpeed_zero();
      getSpeed_left();
      getSpeed_right();
      getSpeed_up();
      getSpeed_down();
      getSpeed_diagonal();

      // setters
      land_flying();
      land_crashed();
      land_landed();
      crash_flying();
      crash_crashed();
      crash_landed();
      reset_empty();
      reset_full();
      
      // move it
      coast_zero();
      coast_noTime();
      coast_noAcceleration();
      coast_noVelocity();
      coast_all();

      // input
      input_none();
      input_mainDown();
      input_mainLeft();
      input_mainDiagonal();
      input_coastClockwise();
      input_coastCounterClockwise();
      input_noFuel();
      
      report("Lander");
   }

private:
   Position p;
   

   
   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    IS DEAD while DEAD
    * input:   status=DEAD
    * output:  true
    *********************************************/
   void isDead_dead()
   {  // setup
      Lander l(p);
      l.status = DEAD;
      bool b;
      
      // exercise
      b = l.isDead();
      
      // verify
      assertUnit(b == true);
      assertUnit(l.status == DEAD);
   }  // teardown

   /*********************************************
    * name:    IS DEAD while SAFE
    * input:   status=SAFE
    * output:  false
    *********************************************/
   void isDead_alive()
   {  // setup
      Lander l(p);
      l.status = SAFE;
      bool b;
      
      // exercise
      b = l.isDead();
      
      // verify
      assertUnit(b == false);
      assertUnit(l.status == SAFE);
   }  // teardown
   
   /*********************************************
    * name:    IS LANDED while SAFE
    * input:   status=SAFE
    * output:  true
    *********************************************/
   void isLanded_landed()
   {  // setup
      Lander l(p);
      l.status = SAFE;
      bool b;
      
      // exercise
      b = l.isLanded();
      
      // verify
      assertUnit(b == true);
      assertUnit(l.status == SAFE);
   }  // teardown

   /*********************************************
    * name:    IS LANDED while FLYING
    * input:   status=PLAYING
    * output:  true
    *********************************************/
   void isLanded_flying()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      bool b;
      
      // exercise
      b = l.isFlying();
      
      // verify
      assertUnit(b == true);
      assertUnit(l.status == PLAYING);
   }  // teardown
   
   /*********************************************
    * name:    IS FLYING while LANDED
    * input:   status=SAFE
    * output:  false
    *********************************************/
   void isFlying_landed()
   {  // setup
      Lander l(p);
      l.status = SAFE;
      bool b;
      
      // exercise
      b = l.isFlying();
      
      // verify
      assertUnit(b == false);
      assertUnit(l.status == SAFE);
   }  // teardown

   /*********************************************
    * name:    IS FLYING while FLYING
    * input:   status=PLAYING
    * output:  false
    *********************************************/
   void isFlying_flying()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      bool b;
      
      // exercise
      b = l.isFlying();
      
      // verify
      assertUnit(b == true);
      assertUnit(l.status == PLAYING);
   }  // teardown
   
   /*********************************************
    * name:    GET FUEL while EMPTY
    * input:   fuel=0.0
    * output:  0.0
    *********************************************/
   void getFuel_empty()
   {  // setup
      Lander l(p);
      l.fuel = 0.0;
      int f = 9;
      
      // exercise
      f = l.getFuel();
      
      // verify
      assertUnit(f == 0);
      assertEquals(l.fuel, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    GET FUEL while has some
    * input:   fuel=555.5
    * output:  555.5
    *********************************************/
   void getFuel_some()
   {  // setup
      Lander l(p);
      l.fuel = 555.5;
      int f = 9;
      
      // exercise
      f = l.getFuel();
      
      // verify
      assertUnit(f == 555);
      assertEquals(l.fuel, 555.5);
   }  // teardown
   
   /*********************************************
    * name:    GET WIDTH
    * input:   none
    * output:  20
    *********************************************/
   void getWidth()
   {  // setup
      Lander l(p);
      int w = 9;
      
      // exercise
      w = l.getWidth();
      
      // verify
      assertUnit(w == 20);
   }  // teardown
   
   /*********************************************
    * name:    GET MAX SPEED
    * input:   none
    * output:  4.0
    *********************************************/
   void getMaxSpeed()
   {  // setup
      Lander l(p);
      double s = 99.9;
      
      // exercise
      s = l.getMaxSpeed();
      
      // verify
      assertEquals(s, 4.0);
   }  // teardown
   
   /*********************************************
    * name:    GET POSITION while at ZERO
    * input:   pos=(0.0, 0.0)
    * output:  pos=(0.0, 0.0)
    *********************************************/
   void getPosition_zero()
   {  // setup
      Lander l(p);
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      Position pos;
      
      // exercise
      pos = l.getPosition();
      
      // verify
      assertEquals(pos.x, 0.0);
      assertEquals(pos.y, 0.0);
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
   }
   
   /*********************************************
    * name:    GET POSITION while at MIDDLE of screen
    * input:   pos=(55.5, 66.6)
    * output:  pos=(55.5, 66.6)
    *********************************************/
   void getPosition_middle()
   {  // setup
      Lander l(p);
      l.pos.x = 55.5;
      l.pos.y = 66.6;
      Position pos;
      
      // exercise
      pos = l.getPosition();
      
      // verify
      assertEquals(pos.x, 55.5);
      assertEquals(pos.y, 66.6);
      assertEquals(l.pos.x, 55.5);
      assertEquals(l.pos.y, 66.6);
   }  // teardown
   
   
   /*********************************************
    * name:    GET SPEED while STATIONARY
    * input:   v=(0.0, 0.0)
    * output:  0.0
    *********************************************/
   void getSpeed_zero()
   {  // setup
      Lander l(p);
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      double s;
      
      // exercise
      s = l.getSpeed();
      
      // verify
      assertEquals(s, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    GET SPEED while flying RIGHT
    * input:   v=(11.11, 0.0)
    * output:  11.11
    *********************************************/
   void getSpeed_right()
   {  // setup
      Lander l(p);
      l.velocity.dx = 11.11;
      l.velocity.dy = 0.0;
      double s;
      
      // exercise
      s = l.getSpeed();
      
      // verify
      assertEquals(s, 11.11);
      assertEquals(l.velocity.dx, 11.11);
      assertEquals(l.velocity.dy, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    GET SPEED while flying LEFT
    * input:   v=(-11.11, 0.0)
    * output:  11.11
    *********************************************/
   void getSpeed_left()
   {  // setup
      Lander l(p);
      l.velocity.dx = -11.11;
      l.velocity.dy = 0.0;
      double s;
      
      // exercise
      s = l.getSpeed();
      
      // verify
      assertEquals(s, 11.11);
      assertEquals(l.velocity.dx, -11.11);
      assertEquals(l.velocity.dy, 0.0);
   }  // teardown
   
   /*********************************************
    * name:    GET SPEED while flying UP
    * input:   v=(0.0, 22.2)
    * output:  22.2
    *********************************************/
   void getSpeed_up()
   {  // setup
      Lander l(p);
      l.velocity.dx = 0.0;
      l.velocity.dy = 22.22;
      double s;
      
      // exercise
      s = l.getSpeed();
      
      // verify
      assertEquals(s, 22.22);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 22.22);
   }  // teardown
   
   /*********************************************
    * name:    GET SPEED while flying DOWN
    * input:   v=(0.0, -22.2)
    * output:  22.2
    *********************************************/
   void getSpeed_down()
   {  // setup
      Lander l(p);
      l.velocity.dx = 0.0;
      l.velocity.dy = -22.22;
      double s;
      
      // exercise
      s = l.getSpeed();
      
      // verify
      assertEquals(s, 22.22);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, -22.22);
   }  // teardown
   
   /*********************************************
    * name:    GET SPEED while flying DIAGONAL
    * input:   v=(30.0, 40.0)
    * output:  50.0
    *********************************************/
   void getSpeed_diagonal()
   {  // setup
      Lander l(p);
      l.velocity.dx = 30.0;
      l.velocity.dy = 40.0;
      double s;
      
      // exercise
      s = l.getSpeed();
      
      // verify
      assertEquals(s, 50.0);
      assertEquals(l.velocity.dx, 30.0);
      assertEquals(l.velocity.dy, 40.0);
   }

   
   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    LAND WHILE FLYING
    * input:   a=9.9, status=PLAYING
    * output:  a=0 degrees, status=SAFE
    *********************************************/
   void land_flying()
   {  // setup
      Lander l(p);
      l.angle.radians = 9.9;
      l.status = PLAYING;
      
      // exercise
      l.land();
      
      // verify
      assertEquals(l.angle.radians, 0.0);
      assertUnit(l.status == SAFE);
   }  // teardown
   
   /*********************************************
    * name:    LAND WHILE CRASHED
    * input:   a=9.9, status=DEAD
    * output:  a=0 degrees, status=SAFE
    *********************************************/
   void land_crashed()
   {  // setup
      Lander l(p);
      l.angle.radians = 9.9;
      l.status = DEAD;
      
      // exercise
      l.land();
      
      // verify
      assertEquals(l.angle.radians, 0.0);
      assertUnit(l.status == SAFE);
   }  // teardown
   
   /*********************************************
    * name:    LAND WHILE LANDED
    * input:   a=9.9, status=SAFE
    * output:  a=0 degrees, status=SAFE
    *********************************************/
   void land_landed()
   {  // setup
      Lander l(p);
      l.angle.radians = 9.9;
      l.status = SAFE;
      
      // exercise
      l.land();
      
      // verify
      assertEquals(l.angle.radians, 0.0);
      assertUnit(l.status == SAFE);
   }  // teardown
   
   /*********************************************
    * name:    CRASH WHILE FLYING
    * input:   a=9.9, status=PLAYING
    * output:  a=180 degrees, status=DEAD
    *********************************************/
   void crash_flying()
   {  // setup
      Lander l(p);
      l.angle.radians = 9.9;
      l.status = PLAYING;
      
      // exercise
      l.crash();
      
      // verify
      assertEquals(l.angle.radians, M_PI);
      assertUnit(l.status == DEAD);
   }  // teardown
   
   /*********************************************
    * name:    CRASH WHILE CRASHED
    * input:   a=9.9, status=DEAD
    * output:  a=180 degrees, status=DEAD
    *********************************************/
   void crash_crashed()
   {  // setup
      Lander l(p);
      l.angle.radians = 9.9;
      l.status = DEAD;
      
      // exercise
      l.crash();
      
      // verify
      assertEquals(l.angle.radians, M_PI);
      assertUnit(l.status == DEAD);
   }  // teardown
      
   /*********************************************
    * name:    CRASH WHILE LANDED
    * input:   a=9.9, status=SAFE
    * output:  a=180 degrees, status=DEAD
    *********************************************/
   void crash_landed()
   {  // setup
      Lander l(p);
      l.angle.radians = 9.9;
      l.status = SAFE;
      
      // exercise
      l.crash();
      
      // verify
      assertEquals(l.angle.radians, M_PI);
      assertUnit(l.status == DEAD);
   }  // teardown
   
   /*********************************************
    * name:    RESET FROM NORMAL POSITION
    * input:   angle=90degrees status=DEAD,   pos=(-10,-10), v=(100,100)
    * output:  angle=0degrees  status=PLAYING pos=(99,75..95), v=(-2..2, -2..2)
    *********************************************/
   void reset_empty()
   {  // setup
      Lander l(p);
      l.angle.radians = 1.57079632679; // PI/2 = 90degrees
      l.pos.x = -10.0;
      l.pos.y = -10.0;
      l.velocity.dx = 100.0;
      l.velocity.dy = 100.0;
      l.status = DEAD;
      Position posUpperRight;
      posUpperRight.x = 100.0;
      posUpperRight.y = 100.0;

      // exercise
      l.reset(posUpperRight);

      // verify
      assertEquals(l.angle.radians, 0.0);
      assertEquals(l.pos.x, 99.0);
      assertUnit(75.0 <= l.pos.y && l.pos.y <= 95.0);
      assertUnit(-10.0 <= l.velocity.dx && l.velocity.dx <= -4.0);
      assertUnit(-2.0 <= l.velocity.dy && l.velocity.dy <= 2.0);
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 5000.0);
   }  // teardown

   /*********************************************
    * name:    RESET AFTER HAS JUST BEEN RESET
    * input:   angle=0degrees  status=PLAYING, pos=(99,90), v=(1,-1)
    * output:  angle=0degrees  status=PLAYING  pos=(99,75..95), v=(-2..2, -2..2)
    *********************************************/
   void reset_full()
   {  // setup
      Lander l(p);
      l.angle.radians = 0.0; 
      l.pos.x = 99.0;
      l.pos.y = 90.0;
      l.velocity.dx = 1.0;
      l.velocity.dy = -1.0;
      l.status = PLAYING;
      Position posUpperRight;
      posUpperRight.x = 100.0;
      posUpperRight.y = 100.0;

      // exercise
      l.reset(posUpperRight);

      // verify
      assertEquals(l.angle.radians, 0.0);
      assertEquals(l.pos.x, 99.0);
      assertUnit(75.0 <= l.pos.y && l.pos.y <= 95.0);
      assertUnit(-10.0 <= l.velocity.dx && l.velocity.dx <= -4.0);
      assertUnit(-2.0 <= l.velocity.dy && l.velocity.dy <= 2.0);
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 5000.0);
   }  // teardown

   /*****************************************************************
    *****************************************************************
    * COAST
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    COAST WHILE NOT MOVING
    * input:   pos=(100, 200), v=(0, 0), a=(0,0) t=1.0
    * output:  pos=(100, 200), v=(0, 0)
    *********************************************/
   void coast_zero()
   {  // setup
      Lander l(p);
      l.pos.x = 100.0;
      l.pos.y = 200.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      double t = 1.0;
      
      // exercise
      l.coast(a, t);
      
      // verify
      assertEquals(l.pos.x, 100.0);
      assertEquals(l.pos.y, 200.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    COAST WITH ZERO TIME
    * input:   pos=(100, 200), v=(30, 40), a=(5, 6) t=0.0
    * output:  pos=(100, 200), v=(30, 40)
    *********************************************/
   void coast_noTime()
   {  // setup
      Lander l(p);
      l.pos.x = 100.0;
      l.pos.y = 200.0;
      l.velocity.dx = 30.0;
      l.velocity.dy = 40.0;
      Acceleration a;
      a.ddx = 5.0;
      a.ddy = 6.0;
      double t = 0.0;
      
      // exercise
      l.coast(a, t);
      
      // verify
      assertEquals(l.pos.x, 100.0);
      assertEquals(l.pos.y, 200.0);
      assertEquals(l.velocity.dx, 30.0);
      assertEquals(l.velocity.dy, 40.0);
      assertEquals(a.ddx, 5.0);
      assertEquals(a.ddy, 6.0);
      assertEquals(t, 0.0);
   }  // teardown

   /*********************************************
    * name:    COAST WITH VELOCITY NO ACCELERATION
    * input:   pos=(100, 200), v=(30, 40), a=(0, 0) t=2.0
    * output:  pos=(160, 280), v=(30, 40)
    *********************************************/
   void coast_noAcceleration()
   {  // setup
      Lander l(p);
      l.pos.x = 100.0;
      l.pos.y = 200.0;
      l.velocity.dx = 30.0;
      l.velocity.dy = 40.0;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      double t = 2.0;
      
      // exercise
      l.coast(a, t);
      
      // verify
      assertEquals(l.pos.x, 160.0); // 100 + 30*2
      assertEquals(l.pos.y, 280.0); // 200 + 40*2
      assertEquals(l.velocity.dx, 30.0);
      assertEquals(l.velocity.dy, 40.0);
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(t, 2.0);
   }  // teardown
   
   /*********************************************
    * name:    COAST WITH NO VELOCITY BUT ACCELERATION
    * input:   pos=(100, 200), v=(0, 0), a=(5, 6) t=2.0
    * output:  pos=(130, 236), v=(10, 12)
    *********************************************/
   void coast_noVelocity()
   {  // setup
      Lander l(p);
      l.pos.x = 100.0;
      l.pos.y = 200.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      Acceleration a;
      a.ddx = 5.0;
      a.ddy = 6.0;
      double t = 2.0;
      
      // exercise
      l.coast(a, t);
      
      // verify
      assertEquals(l.pos.x, 130.0); // 100 + 10*2 + .5*5*4
      assertEquals(l.pos.y, 236.0); // 200 + 12*2 + .5*6*4
      assertEquals(l.velocity.dx, 10.0);  // 0 + 5*2
      assertEquals(l.velocity.dy, 12.0);  // 0 + 6*2
      assertEquals(a.ddx, 5.0);
      assertEquals(a.ddy, 6.0);
      assertEquals(t, 2.0);
   }  // teardown

   /*********************************************
    * name:    COAST WITH VELOCITY, ACCELERATION, AND TIME
    * input:   pos=(100, 200), v=(30, 40), a=(5, 6) t=2.0
    * output:  pos=(190, 316), v=(40, 52)
    *********************************************/   
   void coast_all()
   {  // setup
      Lander l(p);
      l.pos.x = 100.0;
      l.pos.y = 200.0;
      l.velocity.dx = 30.0;
      l.velocity.dy = 40.0;
      Acceleration a;
      a.ddx = 5.0;
      a.ddy = 6.0;
      double t = 2.0;
      
      // exercise
      l.coast(a, t);
      
      // verify
      assertEquals(l.pos.x, 190.0); // 100 + 40*2 + .5*5*4
      assertEquals(l.pos.y, 316.0); // 200 + 52*2 + .5*6*4
      assertEquals(l.velocity.dx, 40.0);  // 30 + 5*2
      assertEquals(l.velocity.dy, 52.0);  // 40 + 6*2
      assertEquals(a.ddx, 5.0);
      assertEquals(a.ddy, 6.0);
      assertEquals(t, 2.0);
   }  // teardown
   
   /*****************************************************************
    *****************************************************************
    * INPUT
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    INPUT NOTHING
    * input:   v=(0, 0), t=(f, f, f) a=0deg
    * output:  a=(0, -1.0)
    *********************************************/
   void input_none()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      l.angle.radians = 0.0;
      l.fuel = 100.0;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = false;
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -99.9;
      double gravity = -1.0; // gravity
      
      // exercise
      a = l.input(t, gravity);
      
      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, -1.0);     // gravity
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 100.0);
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == false);
      assertEquals(gravity, -1.0);
   }  // teardown
   
   /*********************************************
    * name:    INPUT MAIN ENGINE POINTING DOWN
    * input:   v=(0, 0), t=(f, f, t) a=0deg
    * output:  a=(0, 1.9795404)
    *********************************************/
   void input_mainDown()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      l.angle.radians = 0.0;
      l.fuel = 100.0;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = true;     // main engine on
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -99.9;
      double gravity = -1.0; // gravity
      
      // exercise
      a = l.input(t, gravity);
      
      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, -1.0 + 2.9795404);     // gravity + thrust
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 90.0);                // 10 units of fuel
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertEquals(l.angle.radians, 0.0);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == true);
      assertEquals(gravity, -1.0);
   }  // teardown
   
   /*********************************************
    * name:    INPUT MAIN ENGINE POINTING LEFT
    * input:   v=(0, 0), t=(f, f, t) a=270deg
    * output:  a=(2.9795404, -1.0)
    *********************************************/
   void input_mainLeft()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      l.angle.radians = 4.71239; // 270 degrees to the left
      l.fuel = 100.0;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = true;     // main engine on
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -99.9;
      double gravity = -1.0; // gravity
      
      // exercise
      a = l.input(t, gravity);
      
      // verify
      assertEquals(a.ddx, 2.9795404);  // thrust
      assertEquals(a.ddy, -1.0);       // gravity
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 90.0);      // 10 units of fuel
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertEquals(l.angle.radians, 4.71239);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == true);
      assertEquals(gravity, -1.0);
   }  // teardown
   
   /*********************************************
    * name:    INPUT MAIN ENGINE POINTING DIAGONAL
    * input:   v=(0, 0), t=(f, f, t) a=30deg
    * output:  a=(-1.4897, 1.580357)
    *********************************************/
   void input_mainDiagonal()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      l.angle.radians = 0.523599; // 30 degrees to the right
      l.fuel = 100.0;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = false;
      t.mainEngine = true;     // main engine on
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -99.9;
      double gravity = -1.0; // gravity
      
      // exercise
      a = l.input(t, gravity);
      
      // verify
      assertEquals(a.ddx, -1.4897702);            // thrust: -2.9795404 / 2
      assertEquals(a.ddy, -1.0 + 2.58035734368);  // gravity + sin(30) * 2.9795404
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 90.0);                 // 10 units of fuel
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertEquals(l.angle.radians, 0.523599);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == true);
      assertEquals(gravity, -1.0);
   }  // teardown
   
   /*********************************************
    * name:    INPUT COAST CLOCKWISE
    * input:   v=(0, 0), t=(t, f, f) a=0deg
    * output:  a=(0, -1.0)
    *********************************************/
   void input_coastClockwise()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      l.angle.radians = 0.0;
      l.fuel = 100.0;
      Thrust t;
      t.clockwise = true;
      t.counterClockwise = false;
      t.mainEngine = false;
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -99.9;
      double gravity = -1.0; // gravity
      
      // exercise
      a = l.input(t, gravity);
      
      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, -1.0);              // gravity
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 99.0);             // small amount of fuel
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertEquals(l.angle.radians, 0.1); // clockwise
      assertUnit(t.clockwise == true);
      assertUnit(t.counterClockwise == false);
      assertUnit(t.mainEngine == false);
      assertEquals(gravity, -1.0);
   }  // teardown
   
   /*********************************************
    * name:    INPUT COAST COUNTERCLOCKWISE
    * input:   v=(0, 0), t=(t, f, f) a=.4rad
    * output:  a=(0, -1.0)
    *********************************************/
   void input_coastCounterClockwise()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      l.angle.radians = 0.4;
      l.fuel = 100.0;
      Thrust t;
      t.clockwise = false;
      t.counterClockwise = true;
      t.mainEngine = false;
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -99.9;
      double gravity = -1.0; // gravity
      
      // exercise
      a = l.input(t, gravity);
      
      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, -1.0);              // gravity
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 99.0);             // small amount of fuel
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertEquals(l.angle.radians, 0.3);    // counter clockwise
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == true);
      assertUnit(t.mainEngine == false);
      assertEquals(gravity, -1.0);
   }  // teardown
   
   /*********************************************
    * name:    INPUT NO FUEL
    * input:   v=(0, 0), t=(f, f, f) a=0deg
    * output:  a=(0, -1.0)
    *********************************************/
   void input_noFuel()
   {  // setup
      Lander l(p);
      l.status = PLAYING;
      l.pos.x = 0.0;
      l.pos.y = 0.0;
      l.velocity.dx = 0.0;
      l.velocity.dy = 0.0;
      l.angle.radians = 2.0;
      l.fuel = 0.0;
      Thrust t;
      t.clockwise = true;
      t.counterClockwise = true;
      t.mainEngine = true;
      Acceleration a;
      a.ddx = -99.9;
      a.ddy = -99.9;
      double gravity = -1.0; // gravity
      
      // exercise
      a = l.input(t, gravity);

      // verify
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, -1.0);     // gravity
      assertUnit(l.status == PLAYING);
      assertEquals(l.fuel, 0.0);
      assertEquals(l.pos.x, 0.0);
      assertEquals(l.pos.y, 0.0);
      assertEquals(l.velocity.dx, 0.0);
      assertEquals(l.velocity.dy, 0.0);
      assertEquals(l.angle.radians, 2.0);    // counter clockwise
      assertUnit(t.clockwise == true);
      assertUnit(t.counterClockwise == true);
      assertUnit(t.mainEngine == true);
      assertEquals(gravity, -1.0);
   }  // teardown
   
   
};

