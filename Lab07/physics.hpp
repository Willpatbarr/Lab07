//
//  physics.hpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#pragma once

#include <cmath>
#include <cassert>


/***************************************
 * AREA FROM RADIUS
 *
***************************************/

inline double areaFromRadius(double radius)
{
   return M_PI * radius * radius;
}


/***************************************
 * FORCE FROM DRAG
 *
***************************************/
inline double forceFromDrag(double density, double drag,
                            double radius, double velocity)
{
   // compute area
   double area = areaFromRadius(radius);
   
   // compute and return drag
   return 0.5 * drag * area * velocity * velocity;
}


/***************************************
 * ACCELERATION FROM FORCE
 *
***************************************/
inline double accelerationFromForce(double force, double mass)
{
   // a = m / f
   return mass / force;
}


/***************************************do * VELOCITY FROM ACCELERATION
 *
***************************************/
inline double velocityFromAcceleration(double acceleration, double time)
{
   return acceleration * time;
}

/***************************************
 * MAPPING
 *
***************************************/
struct Mapping
{
   double domain;
   double range;
};


/*!
 * LINEAR INTERPOLATION
 * from a list of domains and ranges, linear interpolate
 *
 *    |         *(d1,r1)
 *    |        /
 *    |      *(d,r)
 *   r|     /
 *    |    *(d0,r0)
 *    |
 *    +-------------------
 *
 * equation:
 *    (r - r0) / (d - d0) = (r1 - r0) / (d1 - d0)
 * Thus
 *    r = r0 + r(1 - r0) (d - d0) / (d1 - d0)
*/
inline double linearInterpolation(double d0, double r0,
                                  double d1, double r1,
                                  double d)
{
   assert(abs(d1 - d0) >= abs(d - d0));
   double range = r0 + (r1 - r0) * (d - d0) / (d1 - d0);
   assert(abs(r1 - r0) >= abs(range - r0));
   return range;
}

/***************************************
 * LINEAR INTERPOLATION
 *
***************************************/
inline double linearInterpolation(const Mapping & zero,
                                  const Mapping & one,
                                  double d)
{
   return linearInterpolation(zero.domain, zero.range,
                              one.domain, one.range,
                              d);
}
double machFromAltitude(double altitude);
double densityFromAltitude(double altitude);
double dragFromMach(double mach);
double computeHorizontalComponent(double angle, double speed);
double computeVerticalComponent(double angle, double speed);
double gravityFromAltitude(double altitude);
double computeDistance(double initial, double velocity, double time, double acceleration);
