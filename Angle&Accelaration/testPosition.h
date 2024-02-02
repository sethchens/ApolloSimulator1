/***********************************************************************
 * Header File:
 *    TEST POSITION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Unit tests for the Position class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

/*********************************************
 * TEST POSITION
 * Unit tests for Position
 *********************************************/
class TestPosition : public UnitTest
{
public:
   void run()
   {
      // Ticket 3: Without Add
      constructor_default();
      constructor_nonDefault();
      constructor_copy();
      getX();
      getY();
      equals_equals();
      equals_xDifferent();
      equals_yDifferent();
      notEquals_equals();
      notEquals_xDifferent();
      notEquals_yDifferent();

      // Ticket 4: Add
      addX_zero();
      addX_value();
      addY_zero();
      addY_value();
      add_stationary();
      add_noTime();
      add_moving1Second();
      add_moving4Seconds();
      add_accelerating1Second();
      add_accelerating4Seconds();
      add_1Second();
      add_4Seconds();

      report("Position");
   }

private:
   
   /*****************************************************************
    *****************************************************************
    * CONSTRUCTOR
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    DEFAULT CONSTRUCTOR
    * input:   nothing
    * output:  (0.0, 0.0)
    *********************************************/
   void constructor_default()
   {  // setup
      // exercise
      Position pos;

      // verify
      assertEquals(pos.x, 0.0);
      assertEquals(pos.y, 0.0);
   }  // teardown
      
   /*********************************************
    * name:    NON DEFAULT CONSTRUCTOR
    * input:   2.3, 4.5
    * output:  (2.3, 4.5)
    *********************************************/
   void constructor_nonDefault()
   {  // setup
      double x = 2.3;
      double y = 4.5;
      
      // exercise
      Position pos(x, y);

      // verify
      assertEquals(pos.x, 2.3);
      assertEquals(pos.y, 4.5);
      assertEquals(x, 2.3);
      assertEquals(y, 4.5);
   }  // teardown

   /*********************************************
    * name:    COPY CONSTRUCTOR
    * input:   posRHS=(2.3, 4.5)
    * output:  (2.3, 4.5)
    *********************************************/
   void constructor_copy()
   {  // setup
      Position posRHS;
      posRHS.x = 2.3;
      posRHS.y = 4.5;

      // exercise
      Position posLHS(posRHS);

      // verify
      assertEquals(posLHS.x, 2.3);
      assertEquals(posLHS.y, 4.5);
      assertEquals(posRHS.x, 2.3);
      assertEquals(posRHS.y, 4.5);
   }  // teardown

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/
   
   /*********************************************
    * name:    GET X
    * input:   (2.3, 4.5)
    * output:  2.3
    *********************************************/
   void getX()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      double x = 99.9;

      // exercise
      x = pos.getX();

      // verify
      assertEquals(pos.x, 2.3);
      assertEquals(pos.y, 4.5);
      assertEquals(x, 2.3);
   }  // teardown

   /*********************************************
    * name:    GET Y
    * input:   (2.3, 4.5)
    * output:  4.5
    *********************************************/
   void getY()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      double y = 99.9;

      // exercise
      y = pos.getY();

      // verify
      assertEquals(pos.x, 2.3);
      assertEquals(pos.y, 4.5);
      assertEquals(y, 4.5);
   }  // teardown

   /*****************************************************************
    *****************************************************************
    * COMPARISION
    *****************************************************************
    *****************************************************************/
 
   /*********************************************
    * name:    EQUALS - SAME
    * input:   posRHS=(2.3, 4.5) posLHS=(2.3, 4.5)
    * output:  true
    *********************************************/
   void equals_equals()
   {  // setup
      Position posRHS;
      posRHS.x = 2.3;
      posRHS.y = 4.5;
      Position posLHS;
      posLHS.x = 2.3;
      posLHS.y = 4.5;
      bool result = false;

      // exercise
      result = (posLHS == posRHS);

      // verify
      assertUnit(result == true);
      assertEquals(posRHS.x, 2.3);
      assertEquals(posRHS.y, 4.5);
      assertEquals(posLHS.x, 2.3);
      assertEquals(posLHS.y, 4.5);
   }  // teardown

   /*********************************************
    * name:    EQUALS - X IS DIFFERENT
    * input:   posRHS=(99.9, 4.5) posLHS=(2.3, 4.5)
    * output:  false
    *********************************************/
   void equals_xDifferent()
   {  // setup
      Position posRHS;
      posRHS.x = 99.99;
      posRHS.y = 4.5;
      Position posLHS;
      posLHS.x = 2.3;
      posLHS.y = 4.5;
      bool result = true;

      // exercise
      result = (posLHS == posRHS);

      // verify
      assertUnit(result == false);
      assertEquals(posRHS.x, 99.99);
      assertEquals(posRHS.y, 4.5);
      assertEquals(posLHS.x, 2.3);
      assertEquals(posLHS.y, 4.5);
   }  // teardown

   /*********************************************
    * name:    EQUALS - Y IS DIFFERENT
    * input:   posRHS=(2.3, 99.9) posLHS=(2.3, 4.5)
    * output:  false
    *********************************************/
   void equals_yDifferent()
   {  // setup
      Position posRHS;
      posRHS.x = 2.3;
      posRHS.y = 99.99;
      Position posLHS;
      posLHS.x = 2.3;
      posLHS.y = 4.5;
      bool result = true;

      // exercise
      result = (posLHS == posRHS);

      // verify
      assertUnit(result == false);
      assertEquals(posRHS.x, 2.3);
      assertEquals(posRHS.y, 99.99);
      assertEquals(posLHS.x, 2.3);
      assertEquals(posLHS.y, 4.5);
   }  // teardown

   /*********************************************
    * name:    NOT EQUALS - SAME
    * input:   posRHS=(2.3, 4.5) posLHS=(2.3, 4.5)
    * output:  false
    *********************************************/
   void notEquals_equals()
   {  // setup
      Position posRHS;
      posRHS.x = 2.3;
      posRHS.y = 4.5;
      Position posLHS;
      posLHS.x = 2.3;
      posLHS.y = 4.5;
      bool result = true;

      // exercise
      result = (posLHS != posRHS);

      // verify
      assertUnit(result == false);
      assertEquals(posRHS.x, 2.3);
      assertEquals(posRHS.y, 4.5);
      assertEquals(posLHS.x, 2.3);
      assertEquals(posLHS.y, 4.5);
   }  // teardown

   /*********************************************
    * name:    NOT EQUALS - X IS DIFFERENT
    * input:   posRHS=(99.9, 4.5) posLHS=(2.3, 4.5)
    * output:  true
    *********************************************/
   void notEquals_xDifferent()
   {  // setup
      Position posRHS;
      posRHS.x = 99.99;
      posRHS.y = 4.5;
      Position posLHS;
      posLHS.x = 2.3;
      posLHS.y = 4.5;
      bool result = false;

      // exercise
      result = (posLHS != posRHS);

      // verify
      assertUnit(result == true);
      assertEquals(posRHS.x, 99.99);
      assertEquals(posRHS.y, 4.5);
      assertEquals(posLHS.x, 2.3);
      assertEquals(posLHS.y, 4.5);
   }  // teardown

   /*********************************************
    * name:    NOT EQUALS - Y IS DIFFERENT
    * input:   posRHS=(2.3, 99.9) posLHS=(2.3, 4.5)
    * output:  true
    *********************************************/
   void notEquals_yDifferent()
   {  // setup
      Position posRHS;
      posRHS.x = 2.3;
      posRHS.y = 99.99;
      Position posLHS;
      posLHS.x = 2.3;
      posLHS.y = 4.5;
      bool result = false;

      // exercise
      result = (posLHS != posRHS);

      // verify
      assertUnit(result == true);
      assertEquals(posRHS.x, 2.3);
      assertEquals(posRHS.y, 99.99);
      assertEquals(posLHS.x, 2.3);
      assertEquals(posLHS.y, 4.5);
   }  // teardown

   /*****************************************************************
    *****************************************************************
    * ADD
    *****************************************************************
    *****************************************************************/

   /*********************************************
    * name:    ADD X ZERO
    * input:   (2.3, 4.5) x=0.0
    * output:  (2.3, 4.5)
    *********************************************/
   // add nothing
   void addX_zero()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      double x = 0.0;

      // exercise
      pos.addX(x);

      // verify
      assertEquals(pos.x, 2.3);
      assertEquals(pos.y, 4.5);
      assertEquals(x, 0.0);
   }  // teardown

   /*********************************************
    * name:    ADD X VALUE
    * input:   (2.3, 4.5) x=4.1
    * output:  (2.3, 4.5)
    *********************************************/
   void addX_value()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      double x = 4.1;

      // exercise
      pos.addX(x);

      // verify
      assertEquals(pos.x, 6.4);
      assertEquals(pos.y, 4.5);
      assertEquals(x, 4.1);
   }  // teardown

   /*********************************************
    * name:    ADD Y ZERO
    * input:   (2.3, 4.5) y=0.0
    * output:  (2.3, 4.5)
    *********************************************/
   void addY_zero()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      double y = 0.0;

      // exercise
      pos.addY(y);

      // verify
      assertEquals(pos.x, 2.3);
      assertEquals(pos.y, 4.5);
      assertEquals(y, 0.0);
   }  // teardown

   /*********************************************
    * name:    ADD Y VALUE
    * input:   (2.3, 4.5) y=4.1
    * output:  (2.3, 4.5)
    *********************************************/
   void addY_value()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      double y = 4.1;

      // exercise
      pos.addY(y);

      // verify
      assertEquals(pos.x, 2.3);
      assertEquals(pos.y, 8.6);
      assertEquals(y, 4.1);
   }  // teardown

   /*********************************************
    * name:    ADD STATIONARY
    * input:   pos=(2.3, 4.5) a=(0.0, 0.0), v=(0.0, 0.0) t=4.0
    * output:  (2.3, 4.5)
    *********************************************/
   void add_stationary()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 2.3); // 2.3 + 0.0*4 + 0.5*0.0*4^2
      assertEquals(pos.y, 4.5); // 4.5 + 0.0*4 + 0.5*0.0*4^2
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
      assertEquals(t, 4.0);
   }  // teardown

   /*********************************************
    * name:    ADD NO TIME
    * input:   pos=(2.3, 4.5) a=(6.0, 7.0), v=(8.0, 10.0) t=0.0
    * output:  (2.3, 4.5)
    *********************************************/
   void add_noTime()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 7.0;
      Velocity v;
      v.dx = 8.0;
      v.dy = 10.0;
      double t = 0.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 2.3);  // 2.3 +  8.0*0 + 0.5*6.0*0^2
      assertEquals(pos.y, 4.5);  // 4.5 + 10.0*0 + 0.5*7.0*0^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 7.0);
      assertEquals(v.dx, 8.0);
      assertEquals(v.dy, 10.0);
      assertEquals(t, 0.0);
   }  // teardown

   /*********************************************
    * name:    ADD NO ACCELERATION ONE SECOND
    * input:   pos=(2.3, 4.5) a=(0.0, 0.0), v=(8.0, 10.0) t=1.0
    * output:  (10.3, 14.5)
    *********************************************/
   void add_moving1Second()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      Velocity v;
      v.dx = 8.0;
      v.dy = 10.0;
      double t = 1.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 10.3);   // 2.3 +  8.0*1 + 0.5*0.0*1^2
      assertEquals(pos.y, 14.5);   // 4.5 + 10.0*1 + 0.5*0.0*1^2
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(v.dx, 8.0);
      assertEquals(v.dy, 10.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    ADD NO ACCELERATION FOUR SECOND
    * input:   pos=(2.3, 4.5) a=(0.0, 0.0), v=(8.0, 10.0) t=4.0
    * output:  (34.3, 44.5)
    *********************************************/
   void add_moving4Seconds()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 0.0;
      a.ddy = 0.0;
      Velocity v;
      v.dx = 8.0;
      v.dy = 10.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 34.3);   // 2.3 +  8.0*4 + 0.5*0.0*4^2
      assertEquals(pos.y, 44.5);   // 4.5 + 10.0*4 + 0.5*0.0*4^2
      assertEquals(a.ddx, 0.0);
      assertEquals(a.ddy, 0.0);
      assertEquals(v.dx, 8.0);
      assertEquals(v.dy, 10.0);
      assertEquals(t, 4.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION NO VELOCITY ONE SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(0.0, 0.0) t=1.0
    * output:  (5.3, 8.5)
    *********************************************/
   void add_accelerating1Second()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      double t = 1.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 5.3);    // 2.3 +  0.0*4 + 0.5*6.0*1^2
      assertEquals(pos.y, 8.5);    // 4.5 +  0.0*4 + 0.5*8.0*1^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION NO VELOCITY FOUR SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(0.0, 0.0) t=4.0
    * output:  (50.3, 68.5)
    *********************************************/
   void add_accelerating4Seconds()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 0.0;
      v.dy = 0.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 50.3);    // 2.3 +  0.0*4 + 0.5*6.0*4^2
      assertEquals(pos.y, 68.5);    // 4.5 +  0.0*4 + 0.5*8.0*4^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 0.0);
      assertEquals(v.dy, 0.0);
      assertEquals(t, 4.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION  VELOCITY ONE SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(3.0, 5.0) t=1.0
    * output:  (8.3, 13.5)
    *********************************************/
   void add_1Second()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 3.0;
      v.dy = 5.0;
      double t = 1.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 8.3);    // 2.3 +  3.0*1 + 0.5*6.0*1^2
      assertEquals(pos.y, 13.5);   // 4.5 +  5.0*1 + 0.5*8.0*1^2
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 3.0);
      assertEquals(v.dy, 5.0);
      assertEquals(t, 1.0);
   }  // teardown

   /*********************************************
    * name:    ADD  ACCELERATION  VELOCITY FOUR SECOND
    * input:   pos=(2.3, 4.5) a=(6.0, 8.0), v=(3.0, 5.0) t=4.0
    * output:  (62.3, 88.5)
    *********************************************/
   void add_4Seconds()
   {  // setup
      Position pos;
      pos.x = 2.3;
      pos.y = 4.5;
      Acceleration a;
      a.ddx = 6.0;
      a.ddy = 8.0;
      Velocity v;
      v.dx = 3.0;
      v.dy = 5.0;
      double t = 4.0;

      // exercise
      pos.add(a, v, t);

      // verify
      assertEquals(pos.x, 62.3);  // 2.3 + (3.0 * 4) + (0.5 * 6.0 * 16.0)
      assertEquals(pos.y, 88.5);  // 4.5 + (5.0 * 4) + (0.5 * 8.0 * 16.0)
      assertEquals(a.ddx, 6.0);
      assertEquals(a.ddy, 8.0);
      assertEquals(v.dx, 3.0);
      assertEquals(v.dy, 5.0);
      assertEquals(t, 4.0);
   }  // teardown

};
