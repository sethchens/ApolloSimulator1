/***********************************************************************
 * Source File:
 *    TEST
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner which will implement execute all the unit tests
 ************************************************************************/

#include "testPosition.h"
#include "testAcceleration.h"
#include "testVelocity.h"
#include "testAngle.h"
#include "testThrust.h"
#include "testLander.h"

 // This code, and the similar IF_DEF in testRunner(), is to ensure that
 // you can see the text output (called the console window) and OpenGL's
 // graphics at the same time. It is not required on Apple's XCode, only
 // on Window's Visual Studio. If you have problems seeing the output window
 // and your team is exclusively on Visual Studio, you can safely remove
 // these two "#ifdef _WIN32" and the "#endif" below it.
#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/************************************
 * TEST RUNNER
 * Run all the unit tests
 ************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   // Unit tests
   TestAngle().run();
   TestAcceleration().run();
   TestVelocity().run();
   TestPosition().run();
   TestThrust().run();
   TestLander().run();
}
