/***********************************************************************
 * Source File:
 *    MAIN
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Launches the unit tests - that is all!
 ************************************************************************/

 #include "test.h"
 #include <OpenGL/gl.h>
 #include <GLUT/glut.h>

 /************************************
  * MAIN
  * There can be only one!
  ************************************/
int main()
{
   // run the test code.
   testRunner();

   // return success
   return 0;
}
