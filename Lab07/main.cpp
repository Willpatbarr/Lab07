
#include <iostream>  // for CIN and COUT
#include <cmath> // for Triginometric Calculations
#include <string> // for string prompts

using namespace std;

// Set Global Variables
#define MASS                 46.7    // Weight in KG
#define DIAMETER             0.15489 // Diameter of the shell
#define TIME                 0.01    // the amount of time in seconds used to increment
#define DRAG_COEFFICIENT     0.3     // drag coeffecient as a constant
#define AIR_DENSITY          0.6     // the density of air as a constant

/**************************************************
 * COMPUTE CIRCLE AREA
 * computes the surface area of a circle
 * INPUT
 *      d: diameter of the circle
 * OUTPUT
 *      a: surface area in square meters
 ***************************************************/
double computeCircleArea(double d)
{
   // perform the area calculation
   double a = M_PI * pow(d / 2.0, 2);
   
   // return the surface area
   return a;
}

/**************************************************
 * COMPUTE DRAG FORCE
 * computes the drag force on an object
 * INPUT
 *      v: velocity
 *      c: drag coefficient
 *      p: density of the air
 *      a: surface area
 * OUTPUT
 *      d: drage force in newtons
 ***************************************************/
double computeDragForce(double v, double c, double p, double a)
{
   // perform the drag force equation
   double d = 0.5 * c * p * (v * v) * a;
   
   // return the drag force
   return d;
}

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

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double computeTotalComponent(double x, double y)
{
   //return statement
   return sqrt((x * x + y * y));
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
double computeAcceleration(double f, double m)
{
   //return statement
   return (f/m);
}

/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
double computeVelocity(double v, double a, double t)
{
   //return statement
   return (v + a * t);
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
//   double angle = prompt("what is your angle in degrees?: ");
   double angle = 75.0;
   double speed= 827.0;
//   double speed = prompt("what is your speed in m/s?: ");
   double x = 0.0; // set to 0.0 as default
   double y = 0.0; // set to 0.0 as default
   double t = 0.0; // used to keep track of hang time
   double g = 9.807; // initial value at sea level
   double area = computeCircleArea(DIAMETER); // computes the circular area of the shell
   
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
      
      // compute total velocity
      double velocity = computeTotalComponent(dx, dy);
      
      // compute drag force
      double dragForce = computeDragForce(velocity, DRAG_COEFFICIENT, AIR_DENSITY, area);
      
      // compute acceleration from drag
      double dragAcceleration = computeAcceleration(dragForce, MASS);
      
      // compute drag angle
      double dragAngle = atan2(dy, dx);
      
      // compute the components of the drag acceleration
      double ddx = computeHorizontalComponent(dragAngle, dragAcceleration);
      double ddy = computeVerticalComponent(dragAngle, dragAcceleration);

      // update dx and dy to account for drag acceleration
      dx = computeVelocity(dx, -ddx, TIME);
      dy = computeVelocity(dy, -ddy, TIME);
      dy = computeVelocity(dy, -g, TIME); // update for gravity as well

      // update the hangtime
      t += TIME;

      // display updated values
      cout << "Time: " << t
           << " | Distance: " << x
           << " | Altitude: " << y
           << " | Velocity: " << velocity
           << " | Drag Force: " << dragForce
           << " | dx: " << dx
           << " | dy: " << dy
           << endl;
   }
   
   cout << " --------------------------------------------" << endl;
   cout << "Ground Impact" << endl;
   cout << "Final Values" << endl;
   cout << "Distance: " << x << " | Altitude: " << y << " | Hang Time: " << t << endl;
   
   return 0;
}
