/***********************************************************************
 * Source File:
 *    TEST
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner which will implement execute all the unit tests
 ************************************************************************/

#include "testAngle.h"
#include "testAcceleration.h"

/************************************
 * TEST RUNNER
 * Run all the unit tests
 ************************************/
void testRunner()
{
   // Unit tests
   TestAngle().run();
   TestAcceleration().run();
}
