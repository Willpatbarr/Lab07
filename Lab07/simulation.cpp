//
//  simulation.cpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#include "simulation.hpp"
#include "physics.hpp"

#include <cmath>
#include <cassert>

using namespace std;

/***************************************
 * Fire
 * Handles execution
***************************************/
void Simulation::fire()
{
   Velocity v;
   v.setSpeedDirection(muzzleVelocity, angle);
   
   interval = 0.01;
   
   // start by setting position, velocity, and time
   PositionVelocityTime pvt;
   pvt.pt = ptInitial;
   pvt.time = interval;
   pvt.v = v;
   
   // start loop that will loop until y = 0.0
   do
   {
      double radius = 154.89 / 2;
      cout << "   radius: " << radius;
      
      double y = pvt.pt.getY();
      cout << "   y: " << y;

      Direction direction = pvt.v.getDirection();

      double speed = pvt.v.getSpeed();
      cout << "   speed: " << speed;

      double x = pvt.pt.getX();
      cout << "   x: " << x;

      
      //compute speed of sound
      double mach = machFromAltitude(y);
      cout << "   mach: " << mach;

      
      //compute mach of shell
      double machOfShell = speed / mach;
      cout << "   machOfShell: " << machOfShell;

      
      //compute air density
      double density = densityFromAltitude(y);
      cout << "   density: " << density;

      
      //compute drag coefficient
      double drag = dragFromMach(machOfShell);
      cout << "   drag: " << drag;

      
      //compute forces on shell
      double dragForce = forceFromDrag(density, drag, radius, pvt.v.getSpeed());
      cout << "   dragForce: " << dragForce;

      
      //compute acceleration
      double acceleration = accelerationFromForce(dragForce, shellMass);
      cout << "   acceleration: " << acceleration;

      
      //compute velocity components
      double dx = computeHorizontalComponent(direction.getDegrees(), speed);
      cout << "dx: " << dx;

      double dy = computeVerticalComponent(direction.getDegrees(), speed);
      cout << "   dy: " << dy;

      
      pvt.v.setDX(dx);
      pvt.v.setDY(dy);
      
      //compute acceleration components
      double ddx = computeHorizontalComponent(direction.getDegrees(), acceleration) * -1;
      cout << "   ddx: " << ddx;

      double ddy = (computeVerticalComponent(direction.getDegrees(), acceleration) + gravityFromAltitude(y)) * -1;
      cout << "   ddy: " << ddy;

      
      //compute positions
      x = computeDistance(x, dx, interval, ddx);
      cout << "   x: " << x;

      y = computeDistance(y, dy, interval, ddy);
      cout << "   y: " << y;

      
      //recompute velocity components using v1 = v0 + a * t
      dx = dx + ddx * interval;
      cout << "   new dx: " << dx;

      dy = dy + ddy * interval;
      cout << "   new dy: " << dy << "\n" << endl;

      
      //update pvt
      pvt.pt.setX(x);
      pvt.pt.setY(y);
      
      pvt.v.setDX(dx);
      pvt.v.setDY(dy);
      
      pvt.time += interval;
      
   } while (pvt.pt.getY() > 0.0);
   
   cout << " --------------------------------------------" << endl;
   cout << "Ground Impact" << endl;
   cout << "Final Values" << endl;
   cout << "Distance: " << pvt.pt.getX() << " | Altitude: " << pvt.pt.getY() << " | Hang Time: " << pvt.time << endl;
}
