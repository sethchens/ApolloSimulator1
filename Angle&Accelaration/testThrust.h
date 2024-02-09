/***********************************************************************
 * Header File:
 *    TEST THRUST
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for THRUST
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "thrust.h"

 /*******************************
  * TEST THRUST
  * A friend class for Thrust which contains the Thrust unit tests
  ********************************/
class TestThrust : public UnitTest
{
public:
   void run()
   {
      // Constructor
      defaultConstructor();

      // getters
      rotation_none();
      rotation_clock();
      rotation_counterClock();
      rotation_both();
      mainEngineThrust();
      isMain_no();
      isMain_yes();
      isClock_no();
      isClock_yes();
      isCounter_no();
      isCounter_yes();

      // Setters
      set_none();
      set_left();
      set_right();
      set_down();
      set_all();

      report("Thrust");
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
   * output:  zero
   *********************************************/
   void defaultConstructor()
   {  // setup
      // exercise
      Thrust t;

      // verify
      assertUnit(t.mainEngine == false);
      assertUnit(t.clockwise == false);
      assertUnit(t.counterClockwise == false);
   } // teardown


    /*****************************************************************
     *****************************************************************
     * GETTERS
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    ROTATION NONE
      * input:   clockwise=false, counterClockwise=false
      * output:  zero
      *********************************************/
      void rotation_none()
      {  // setup
         Thrust t;
         t.mainEngine = true;
         t.clockwise = false;
         t.counterClockwise = false;
         double d = -99.9;
        
         // exercise
         d = t.rotation();

         // verify
         assertEquals(d, 0.0);
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == false);
     }  // teardown

     /*********************************************
      * name:    ROTATION CLOCK
      * input:   clockwise=true, counterClockwise=false
      * output:  0.1
      *********************************************/
      void rotation_clock()
      {  // setup
         Thrust t;
         t.mainEngine = false;
         t.clockwise = true;
         t.counterClockwise = false;
         double d = -99.9;

         // exercise
         d = t.rotation();

         // verify
         assertEquals(d, 0.1);
         assertUnit(t.mainEngine == false);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == false);
      }  // teardown

     /*********************************************
      * name:    ROTATION COUNTER CLOCKWISE
      * input:   clockwise=false, counterClockwise=true
      * output:  0.1
      *********************************************/
      void rotation_counterClock()
      {  // setup
         Thrust t;
         t.mainEngine = true;
         t.clockwise = false;
         t.counterClockwise = true;
         double d = -99.9;

         // exercise
         d = t.rotation();

         // verify
         assertEquals(d, -0.1);
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == true);
      }  // teardown

     /*********************************************
      * name:    ROTATION BOTH
      * input:   clockwise=true, counterClockwise=true
      * output:  0.1
      *********************************************/
      void rotation_both()
      {  // setup
         Thrust t;
         t.mainEngine = true;
         t.clockwise = true;
         t.counterClockwise = true;
         double d = -99.9;

         // exercise
         d = t.rotation();

         // verify
         assertEquals(d, 0.0);
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == true);
      }  // teardown

     /*********************************************
      * name:    MAIN ENGINE THRUST
      * input:   none
      * output:  45000.00 / 15103.00  m / s ^ 2
      *********************************************/
      void mainEngineThrust()
      {  // setup
         Thrust t;
         t.mainEngine = true;
         t.clockwise = true;
         t.counterClockwise = true;
         double met = -99.9;

         // exercise
         met = t.mainEngineThrust();

         // verify
         assertEquals(met, 2.97954048864);
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == true);
      }  // teardown

     /*********************************************
      * name:    IS MAIN ENGINE ON? NO
      * input:   mainEngine=false, clockwise=true, counterClockwise=true
      * output:  false
      *********************************************/
      void isMain_no()
      {  // setup
         Thrust t;
         t.mainEngine = false;
         t.clockwise = true;
         t.counterClockwise = true;
         bool on = false;

         // exercise
         on = t.isMain();

         // verify
         assertUnit(on == false);
         assertUnit(t.mainEngine == false);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == true);
      }  // teardown

     /*********************************************
      * name:    IS MAIN ENGINE ON? YES
      * input:   mainEngine=false, clockwise=true, counterClockwise=true
      * output:  true
      *********************************************/
      void isMain_yes()
      {  // setup
         Thrust t;
         t.mainEngine = true;
         t.clockwise = false;
         t.counterClockwise = false;
         bool on = true;

         // exercise
         on = t.isMain();

         // verify
         assertUnit(on == true);
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == false);
      }  // teardown

     /*********************************************
      * name:    IS CLOCKWISE ENGINE ON? NO
      * input:   mainEngine=true, clockwise=false, counterClockwise=true
      * output:  false
      *********************************************/
      void isClock_no()
      {  // setup
         Thrust t;
         t.mainEngine = true;
         t.clockwise = false;
         t.counterClockwise = true;
         bool on = true;

         // exercise
         on = t.isClock();

         // verify
         assertUnit(on == false);
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == true);
      }  // teardown

     /*********************************************
      * name:    IS CLOCKWISE ENGINE ON? YES
      * input:   mainEngine=false, clockwise=true, counterClockwise=false
      * output:  true
      *********************************************/
      void isClock_yes()
      {  // setup
         Thrust t;
         t.mainEngine = false;
         t.clockwise = true;
         t.counterClockwise = false;
         bool on = false;

         // exercise
         on = t.isClock();

         // verify
         assertUnit(on == true);
         assertUnit(t.mainEngine == false);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == false);
      }  // teardown

     /*********************************************
      * name:    IS COUNTER CLOCKWISE ENGINE ON? NO
      * input:   mainEngine=true, clockwise=true, counterClockwise=false
      * output:  false
      *********************************************/
      void isCounter_no()
      {  // setup
         Thrust t;
         t.mainEngine = true;
         t.clockwise = true;
         t.counterClockwise = false;
         bool on = true;

         // exercise
         on = t.isCounter();

         // verify
         assertUnit(on == false);
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == false);
      }  // teardown

     /*********************************************
      * name:    IS COUNTER CLOCKWISE ENGINE ON? YES
      * input:   mainEngine=false, clockwise=false, counterClockwise=true
      * output:  true
      *********************************************/
      void isCounter_yes()
      {  // setup
         Thrust t;
         t.mainEngine = false;
         t.clockwise = false;
         t.counterClockwise = true;
         bool on = false;

         // exercise
         on = t.isCounter();

         // verify
         assertUnit(on == true);
         assertUnit(t.mainEngine == false);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == true);
      }  // teardown


    /*****************************************************************
     *****************************************************************
     * SETTERS
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    SET NOTHING
      * input:   isDown=0 isLeft=0 isRight=0
      * output:  mainEngine=false clockwise=false counterClockwise=false
      *********************************************/
      void set_none()
      {  // setup
         Interface ui;
         ui.isDownPress = 0;
         ui.isLeftPress = 0;
         ui.isRightPress = 0;
         Thrust t;
         t.mainEngine = true;
         t.clockwise = true;
         t.counterClockwise = true;

         // exercise
         t.set(&ui);

         // verify
         assertUnit(t.mainEngine == false);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == false);
         assertUnit(ui.isDownPress == 0);
         assertUnit(ui.isLeftPress == 0);
         assertUnit(ui.isRightPress == 0);

         // teardown
         ui.isDownPress = 0;
         ui.isLeftPress = 0;
         ui.isRightPress = 0;
      }

     /*********************************************
      * name:    SET LEFT ONLY
      * input:   isDown=0 isLeft=1 isRight=0
      * output:  mainEngine=false clockwise=false counterClockwise=false
      *********************************************/
      void set_left()
      {  // setup
         Interface ui;
         ui.isDownPress = 0;
         ui.isLeftPress = 1;
         ui.isRightPress = 0;
         Thrust t;
         t.mainEngine = true;
         t.clockwise = false;
         t.counterClockwise = true;

         // exercise
         t.set(&ui);

         // verify
         assertUnit(t.mainEngine == false);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == false);
         assertUnit(ui.isDownPress == 0);
         assertUnit(ui.isLeftPress == 1);
         assertUnit(ui.isRightPress == 0);

         // teardown
         ui.isDownPress = 0;
         ui.isLeftPress = 0;
         ui.isRightPress = 0;
      }

     /*********************************************
      * name:    SET RIGHT ONLY
      * input:   isDown=0 isLeft=0 isRight=2
      * output:  mainEngine=false clockwise=false counterClockwise=true
      *********************************************/
      void set_right()
      {  // setup
         Interface ui;
         ui.isDownPress = 0;
         ui.isLeftPress = 0;
         ui.isRightPress = 2;
         Thrust t;
         t.mainEngine = true;
         t.clockwise = true;
         t.counterClockwise = false;

         // exercise
         t.set(&ui);

         // verify
         assertUnit(t.mainEngine == false);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == true);
         assertUnit(ui.isDownPress == 0);
         assertUnit(ui.isLeftPress == 0);
         assertUnit(ui.isRightPress == 2);

         // teardown
         ui.isDownPress = 0;
         ui.isLeftPress = 0;
         ui.isRightPress = 0;
      }

     /*********************************************
      * name:    SET DOWN ONLY
      * input:   isDown=7 isLeft=0 isRight=0
      * output:  mainEngine=true clockwise=false counterClockwise=false
      *********************************************/
      void set_down()
      {  // setup
         Interface ui;
         ui.isDownPress = 7;
         ui.isLeftPress = 0;
         ui.isRightPress = 0;
         Thrust t;
         t.mainEngine = false;
         t.clockwise = true;
         t.counterClockwise = true;

         // exercise
         t.set(&ui);

         // verify
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == false);
         assertUnit(t.counterClockwise == false);
         assertUnit(ui.isDownPress == 7);
         assertUnit(ui.isLeftPress == 0);
         assertUnit(ui.isRightPress == 0);

         // teardown
         ui.isDownPress = 0;
         ui.isLeftPress = 0;
         ui.isRightPress = 0;
      }


     /*********************************************
      * name:    SET EVERYTHING
      * input:   isDown=4 isLeft=4 isRight=4
      * output:  mainEngine=true clockwise=true counterClockwise=true
      *********************************************/
      void set_all()
      {  // setup
         Interface ui;
         ui.isDownPress = 4;
         ui.isLeftPress = 4;
         ui.isRightPress = 4;
         Thrust t;
         t.mainEngine = false;
         t.clockwise = false;
         t.counterClockwise = false;

         // exercise
         t.set(&ui);

         // verify
         assertUnit(t.mainEngine == true);
         assertUnit(t.clockwise == true);
         assertUnit(t.counterClockwise == true);
         assertUnit(ui.isDownPress == 4);
         assertUnit(ui.isLeftPress == 4);
         assertUnit(ui.isRightPress == 4);

         // teardown
         ui.isDownPress = 0;
         ui.isLeftPress = 0;
         ui.isRightPress = 0;
      } 

 };

