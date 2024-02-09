//
//  Thrust.cpp
//  lab05
//
//  Created by Seth on 2/9/24.
//

#include "thrust.h"

/*******************************
 *Thrust: Rotation
 *Get rotation in radians per second
 ********************************/
double Thrust::rotation() const
{
   if (clockwise && counterClockwise)
      return 0.0;
   else if (clockwise)
      return 0.1;
   else if (counterClockwise)
      return -0.1;
   return 0.0;
};

/*************************************
 *Thrust: set
 *Get main engine thrust in  m / s ^ 2
 ********************************************/

