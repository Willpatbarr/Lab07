//
//  direction.hpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#pragma once

#include <cmath>

/***************************************
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
   Direction{const Direction & rhs}    : radians(rhs.radians) {}
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
      radians = atan2(dx, dy)
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
