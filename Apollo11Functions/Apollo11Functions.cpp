/*************************************************************
 * 1. Name:
 *      Jenna Scholl and Neil Reed
 * 2. Assignment Name:
 *      Lab 02: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      Trying to avoid creating redundant code. We ended up
 *      passing everything to simulate() by reference.
 * 5. How long did it take for you to complete the assignment?
 *      45 minutes
 *****************************************************************/

#include <iostream>          // for CIN and COUT
using namespace std;

#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

#define _USE_MATH_DEFINES    // for M_PI
#include <math.h>            // for sin and cos

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
double computeDistance(double s, double v, double a, double t)
{
   return s + v * t + 0.5 * a * (t * t);
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
   return f / m;
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
   return v + (a * t);
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
   return cos(a) * total;
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
   return sin(a) * total;
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
   return sqrt((x * x) + (y * y));
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
double radiansFromDegrees(double d)
{
   return (d / 360) * 2 * M_PI;
}

/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
double prompt(string message)
{
   double value = 0.0;
   cout << message;
   cin >> value;
   return value;
}

/**************************************************
 * SIMULATE
 * A function to simulate movement of the Apollo 11
 * by modifying each value by 1 unit of time
 * INPUT
 *      x : position
 *      y : altitude
 *      dx : horizontal velocity
 *      dy : vertical velocity
 *      ddx : horizontal acceleration
 *      ddy : vertical acceleration
 *      v : total velocity
 *      aDegrees : angle in degrees
 *      t : the unit of time
 *      currentT: total time passed
 ***************************************************/
void simulate(double &x, double &y, double &dx, double &dy, double &ddx, double &ddy, double &v, double &aDegrees, double &t, double &currentT)
{
   dy = computeVelocity(dy, ddy, t);                  // Compute new vertical velocity
   dx = computeVelocity(dx, ddx, t);                  // Compute new horizontal velocity
   v = computeTotalComponent(dx, dy);                 // Compute new total velocity
   y = computeDistance(y, dy, ddy, t);                // Compute new altitude
   x = computeDistance(x, dx, ddx, t);                // Compute new position

   // Output
   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(2);

   cout << "\t" << currentT << "s - x, y: ("
        << x << ", " << y << ")m  dx, dy: ("
        << dx << ", " << dy << "m / s  speed: "
        << v << "m / s  angle: "
        << aDegrees << "deg" << endl;

   currentT += t;
}

/****************************************************************
* MAIN
* Prompt for input, compute new position, and display output
****************************************************************/
int main()
{
   // Prompt for input and variables to be computed
   double dx = prompt("What is your horizontal velocity (m/s)? ");
   double dy = prompt("What is your vertical velocity (m/s)? ");
   double y = prompt("What is your altitude (m)? ");
   double x = 0.0;
   double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
   double t = 1.0;                                                                 // Time interval between updates
   double currentT = t;                                                            // Total time passed
   double aRadians = radiansFromDegrees(aDegrees);                                 // Angle in radians
   double accelerationThrust = computeAcceleration(THRUST, WEIGHT);                // Acceleration due to thrust 
   double ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);    // Horizontal acceleration due to thrust
   double ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);      // Vertical acceleration due to thrust
   double ddx = ddxThrust;                                                         // Total horizontal acceleration
   double ddy = ddyThrust + GRAVITY;                                               // Total vertical acceleration
   double v = computeTotalComponent(dx, dy);                                       // Total velocity
   double a = computeTotalComponent(ddx, ddy);                                     // Total acceleration

   // Run the simulator 5 times
   for (int i = 0; i < 5; i++)
      simulate(x, y, dx, dy, ddx, ddy, v, aDegrees, t, currentT);

   // Prompt for new angle and modify the necessary variables
   aDegrees = prompt("What is the new angle of the LM where 0 is up (degrees)? ");
   aRadians = radiansFromDegrees(aDegrees);                                        // Update angle in radians
   ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);           // Update horizontal acceleration due to thrust
   ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);             // Update vertical acceleration due to thrust
   ddx = ddxThrust;                                                                // Update total horizontal acceleration
   ddy = ddyThrust + GRAVITY;                                                      // Update total vertical acceleration
   v = computeTotalComponent(dx, dy);                                              // Update total velocity

   // Run the simulator 5 more times
   for (int i = 0; i < 5; i++)
      simulate(x, y, dx, dy, ddx, ddy, v, aDegrees, t, currentT);

   return 0;
}
