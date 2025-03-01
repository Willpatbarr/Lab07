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
      cout << "radius: " << radius << endl;
      
      double y = pvt.pt.getY();
      cout << "y: " << y << endl;

      Direction direction = pvt.v.getDirection();

      double speed = pvt.v.getSpeed();
      cout << "speed: " << speed << endl;

      double x = pvt.pt.getX();
      cout << "x: " << x << endl;

      
      //compute speed of sound
      double mach = machFromAltitude(y);
      cout << "mach: " << mach << endl;

      
      //compute mach of shell
      double machOfShell = speed / mach;
      cout << "machOfShell: " << machOfShell << endl;

      
      //compute air density
      double density = densityFromAltitude(y);
      cout << "density: " << density << endl;

      
      //compute drag coefficient
      double drag = dragFromMach(machOfShell);
      cout << "drag: " << drag << endl;

      
      //compute forces on shell
      double dragForce = forceFromDrag(density, drag, radius, pvt.v.getSpeed());
      cout << "dragForce: " << dragForce << endl;

      
      //compute acceleration
      double acceleration = accelerationFromForce(dragForce, shellMass);
      cout << "acceleration: " << acceleration << endl;

      
      //compute velocity components
      double dx = computeHorizontalComponent(direction.getDegrees(), speed);
      cout << "dx: " << dx << endl;

      double dy = computeVerticalComponent(direction.getDegrees(), speed);
      cout << "dy: " << dy << endl;

      
      pvt.v.setDX(dx);
      pvt.v.setDY(dy);
      
      //compute acceleration components
      double ddx = computeHorizontalComponent(direction.getDegrees(), acceleration) * -1;
      cout << "ddx: " << ddx << endl;

      double ddy = (computeVerticalComponent(direction.getDegrees(), acceleration) + gravityFromAltitude(y)) * -1;
      cout << "ddy: " << ddy << endl;

      
      //compute positions
      x = computeDistance(x, dx, interval, ddx);
      cout << "x: " << x << endl;

      y = computeDistance(y, dy, interval, ddy);
      cout << "y: " << y << endl;

      
      //recompute velocity components using v1 = v0 + a * t
      dx = dx + ddx * interval;
      cout << "new dx: " << dx << endl;

      dy = dy + ddy * interval;
      cout << "new dy: " << dy << endl;

      
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
