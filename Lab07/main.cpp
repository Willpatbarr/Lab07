
#include <iostream>  // for CIN and COUT
#include <cmath> // for Triginometric Calculations
#include <string> // for string prompts

using namespace std;

// Set Global Variables
#define WEIGHT   46.7   // Weight in KG
#define TIME     0.01           // the amount of time in seconds used to increment

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

      // update the vertical velocity component with acceleration due to gravity
      dy = dy + (-9.8) * TIME;
      
      // update the hangtime
      t += TIME;

      // display updated values
      cout << "Time: " << t << " | Distance: " << x << " | Altitude: " << y << " | Hang Time: " << t << endl;
   }
   
   cout << " --------------------------------------------" << endl;
   cout << "Ground Impact" << endl;
   cout << "Final Values" << endl;
   cout << "Time: " << t << " | Distance: " << x << " | Altitude: " << y << " | Hang Time: " << t << endl;
   
   return 0;
}
