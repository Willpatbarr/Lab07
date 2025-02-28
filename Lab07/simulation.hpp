//
//  simulation.hpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#include "physics.hpp"
#include "direction.hpp"
#include "point.hpp"
#include "velocity.hpp"
#include <stdlib.h>
class Simulation
{
public:
   
   // setters
   void setAngle(const Direction & d)    { this->angle = d;     }
   void setInterval(double t)            { this->interval = t;  }
   
   void fire();
   
   
private:
   Point ptInitial = Point();
   Direction angle;
   double interval;
   double muzzleVelocity = 827.0;
};



struct PositionVelocityTime
{
public:
   Point pt;
   double time;
   Velocity v;
};
