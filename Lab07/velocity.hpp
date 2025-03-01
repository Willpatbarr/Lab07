//
//  velocity.hpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#pragma once

#include <stdio.h>
#include "direction.hpp"
#include "direction.cpp"

/***************************************
 * Velocity
 * I feel the need, the need for speed
***************************************/
class Velocity
{
public:
   // constructors
   Velocity() : dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy) : dx(dx), dy(dy) {}
   Velocity(const Velocity & rhs) : dx(rhs.dx), dy(rhs.dy) {}
   Velocity & operator = (const Velocity & rhs)
   {
      dx = rhs.dx;
      dy = rhs.dy;
      return *this;
   }
   
   // getters
   double getDX()             const { return dx;    }
   double getDY()             const { return dy;    }
   double getSpeed()          const;
   Direction getDirection()   const { return direction; }
   
   // setters
   void setDX(double dx)                { this->dx = dx;                   }
   void setDY(double dy)                { this->dy = dy;                   }
   void setDxDy(double dx, double dy)   { this->dx = dx; this->dy = dy;    }
   void setDirection(const Direction & direction)
   {
      setSpeedDirection(getSpeed(), direction);
   }
   void setSpeed(double speed)
   {
      setSpeedDirection(speed, getDirection());
   }
   void setSpeedDirection(double speed, const Direction & direction);
   
   void addDX(double dx)                { setDX(getDX() + dx); }
   void addDY(double dy)                { setDY(getDY() + dy); }
   void addV(const Velocity & v)
   {
      dx += v.dx;
      dy += v.dy;
   }
   Velocity& operator += (const Velocity& rhs)
   {
      addV(rhs);
      return *this;
   }
   void reverse()
   {
      dx += -1.0;
      dy += -1.0;
   }
   
   
private:
   double dx;
   double dy;
   double speed;
   Direction direction;
};
