//
//  simulation.cpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#include "simulation.hpp"

/***************************************
 * Fire
 * Handles execution
***************************************/
void Simulation::fire()
{
   Velocity v;
   v.setSpeed(muzzleVelocity);
   v.setDirection(angle);
   
   
   
   // start by setting position, velocity, and time
   PositionVelocityTime pvt;
   pvt.pt = ptInitial;
   pvt.time = interval;
   pvt.v = v;
   
   // start loop that will loop until y = 0.0
   do
   {
      //compute speed of sound
      
      //compute drag forces
      
      //compute acceleration
      
      //compute velocity components
      
      //compute acceleration components
      
      //compute positions
      
      //recompute velocity components using v1 = v0 + a * t
      
   } while (pvt.pt.getY() != 0.0);
   
}
