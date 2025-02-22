
#include <iostream>  // for CIN and COUT
#include <cmath> // for Triginometric Calculations
#include <string> // for string prompts

using namespace std;

// Set Global Variables
#define WEIGHT   46.7   // Weight in KG
#define TIME     0.01   // the amount of time in seconds used to increment
#define DRAG     0.3    // drag coeffecient as a constant
#define AIR      0.6    // the density of air as a constant

/***********************************************
 * INTERPOLATE GRAVITY VALUE
 * Interpolate for the value of gravity at a given altitude
 * INPUT
 *     altitude
 * OUTPUT
 *     g: the value of gravity linearly interpolated
 ***********************************************/
double interpolateGravity(double altitude)
{
   // Gravity-altitude table
      const double altitudes[] = {0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000};
      const double gravities[] = {9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730, 9.715, 9.684, 9.654, 9.624, 9.594, 9.564};

   // Find the two value of altitude above and below the input altitude
   for (int i = 0; i < 19; i++) // iterates 20 times becuase of size of the arrays
   {
      if (altitude >= altitudes[i] && altitude <= altitudes[i + 1])
      {
         // get the values
         double g0 = gravities[i];
         double g1 = gravities[i + 1];
         double y0 = altitudes[i];
         double y1 = altitudes[i + 1];
         
         //perform the interpolation equation
         return g0 + ((g1 - g0) * (altitude - y0) / (y1 - y0));
      }
   }
   
   return 9.807;
}


/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
double computeHorizontalComponent(double a, double total)
{
   //return statement
   return (sin(a) * total);
}

/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
double computeVerticalComponent(double a, double total)
{
   //return statement
   return (cos(a) * total);
}

/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double radFromDeg(double d)
{
   return (2 * M_PI * (d/360.0));
}

/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
double prompt(string prompt)
{
   double variable;
   cout << prompt;
   cin >> variable;
   return variable;
}

/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
int main()
{
   // initialize variables
   double angle = prompt("what is your angle in degrees?: ");
   double speed = prompt("what is your speed in m/s?: ");
   double x = 0.0; // set to 0.0 as default
   double y = 0.0; // set to 0.0 as default
   double t = 0.0; // used to keep track of hang time
   double g = 9.807; // initial value at sea level
   
   // convert degrees to radians
   double angleInRad = radFromDeg(angle);
   
   // compute initial velocity components
   double dx = computeHorizontalComponent(angleInRad, speed);
   double dy = computeVerticalComponent(angleInRad, speed);
   
   // display the initial dx and dy
   cout << "init dx: " << dx << endl;
   cout << "init dy: " << dy << endl;
   
   // loop until the altitude reaches a negative value
   while (y >= 0)
   {
      // update the position
      x = x + dx * TIME;
      y = y + dy * TIME;
      
      // update gravity
      g = interpolateGravity(y);

      // update the vertical velocity component with acceleration due to gravity
      dy = dy + (-g) * TIME;
      
      // update the hangtime
      t += TIME;

      // display updated values
      cout << "Time: " << t << " | Distance: " << x << " | Altitude: " << y << endl;
   }
   
   cout << " --------------------------------------------" << endl;
   cout << "Ground Impact" << endl;
   cout << "Final Values" << endl;
   cout << "Distance: " << x << " | Altitude: " << y << " | Hang Time: " << t << endl;
   
   return 0;
}
