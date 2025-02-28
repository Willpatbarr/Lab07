//
//  physics.cpp
//  Lab07
//
//  Created by Peyton Markus on 2/27/25.
//

#include "physics.hpp"
#include <cassert>

/***************************************
 * LINEAR INTERPOLATION
 *
***************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
   // off the scale on the small end
   if (domain < mapping[0].domain)
      return mapping[0].range;
   
   // within the table
   for (int i = 0; i < numMapping - 1; i++)
   {
      // the domain must be in order
      assert(mapping[i +0].domain < mapping[i + 1].domain);
      if (mapping[i +1].domain <= domain && domain <= mapping[i + 1].domain)
         return linearInterpolation(mapping[i + 0],
                                    mapping[i + 1],
                                    domain);
   }
   
   // off the scale on the large end
   return mapping[numMapping-1].range;
}

/***************************************
 * GRAVITY FROM ALTITUDE
 *
**************************************/
double gravityFromAltitude(double altitude)
{
   const Mapping gravityMapping[] =
   { // altitude     gravity
      { 0.0    , 9.807 },
      { 1000.0 , 9.804 },
      { 2000.0 , 9.801 },
      { 3000.0 , 9.797 },
      { 4000.0 , 9.794 },
      { 5000.0 , 9.791 },
      { 6000.0 , 9.788 },
      { 7000.0 , 9.785 },
      { 8000.0 , 9.782 },
      { 9000.0 , 9.779 },
      { 10000.0, 9.776 },
      { 15000.0, 9.761 },
      { 20000.0, 9.745 },
      { 25000.0, 9.730 },
      { 30000.0, 9.715 },
      { 40000.0, 9.684 },
      { 50000.0, 9.654 },
      { 60000.0, 9.624 },
      { 70000.0, 9.594 },
      { 80000.0, 9.564 }
   };
   
   // look up value
   double gravity = linearInterpolation(gravityMapping,
         sizeof(gravityMapping) / sizeof(gravityMapping[0]),
         altitude);
   
   return gravity;
}
