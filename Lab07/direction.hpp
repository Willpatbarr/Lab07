//
//  direction.hpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#pragma once

#define USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI      3.14159265358979323846
#define M_PI_2    1.57079632679489661923
#endif // M_PI

/**************************************
 * DEGREES FROM RADIANS
 *
***************************************/
inline double degreesFromRadians(double radians)
{
   return 360.0 * (radians / (2.0 * M_PI));
}


/**************************************
 * RADIANS FROM DEGREES
 *
***************************************/
inline double radiansFromDegrees(double degrees)
{
   return (degrees / 360.0) * (2.0 * M_PI);
}


/**************************************
 * Direction
 * Determine the direction
***************************************/
class Direction
{
public:
   // constructors
   Direction()                         : radians(0.0) {}
   Direction(double degrees)           : radians(0.0)
   {
      radians = radiansFromDegrees(degrees);
   }
   Direction(const Direction & rhs)    : radians(rhs.radians) {}
   Direction & operator = (const Direction& rhs)
   {
      radians = rhs.radians;
      return *this;
   }
   
   // setters
   void setRadians(double rhs) { radians = rhs;                      }
   void setDegrees(double rhs) { radians = radiansFromDegrees(rhs);  }
   void setDxDy (double dx, double dy)
   {
      radians = atan2(dx, dy);
   }
   
   void setDown()   { radians = M_PI;          }
   void setUp()     { radians = 0.0;           }
   void setRight()  { radians = M_PI_2;        }
   void setLeft()   { radians = M_PI_2 + M_PI; }
   void reverse()   { radians += M_PI;         }
   
   // getters
   double getRadians()   const  { return radians;                      }
   double getDegrees()   const  { return degreesFromRadians(radians);  }
   double getDX()        const  { return sin(radians);                 }
   double getDY()        const  { return cos(radians);                 }
   
   
private:
   double radians;
};
