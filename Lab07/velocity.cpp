//
//  velocity.cpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#include "velocity.hpp"
#include "physics.hpp"

/*********************************************
 * VELOCITY : GET SPEED
 *  find the magnitude of velocity
 *********************************************/
double Velocity::getSpeed() const
{
   double s = sqrt((dx * dx) + (dy * dy));
   return s;
}

void Velocity::setSpeedDirection(double speed, const Direction & direction)
{
   this->speed = speed;
   this->direction = direction;
   
   this->dx = computeHorizontalComponent(direction.getDegrees(), speed);
   this->dy = computeVerticalComponent(direction.getDegrees(), speed);
}
   
