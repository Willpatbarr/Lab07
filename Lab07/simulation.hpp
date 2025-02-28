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
   void fire();
   Point ptInitial;
};

struct PositionVelocityTime
{
public:
   Point pt;
   double time;
   Velocity v;
};
