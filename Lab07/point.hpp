//
//  point.hpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#pragma once

#include <iostream>

/***************************************
 * Point
 * a single position.
***************************************/

class Point
{
public:
   // constructors
   Point()              : x(0.0), y(0.0)  {}
   Point(double x, double y);
   Point(const Point & pt) : x(pt.x), y(pt.y) {}
   Point& operator = (const Point& pt)
   {
      x = pt.x;
      y = pt.y;
      return *this;
   }
   
   // getters
   double getX()        const { return x;             }
   double getY()        const { return y;             }
   
   // setters
   void setX(double x)        { this->x = x;          }
   void setY(double y)        { this->y = y;          }
   void addX(double dx)       { setX(getX() + dx);    }
   void addY(double dy)       { setY(getY() + dy);    }
   
private:
   double x;            // horizontal position
   double y;            // vertical position
};
