//
//  Lab07.cpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cassert>
#include "velocity.hpp"
#include "point.hpp"
#include "direction.hpp"
#include "simulation.hpp"
using namespace std;

int main()
{
   // setup the simulation
   Simulation s;
   s.setInterval(0.01);
   
   Direction d = Direction(75);
   s.setAngle(d);
   
   // run the simulation
   s.fire();
   
   // output
   
   return 0;
   }
