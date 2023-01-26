/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "point.h"
#include <cassert>

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(double x, double y) : x(0.0), y(0.0)
{
   setX(x);
   setY(y);
}

/******************************************
 * POINT : ADD
 * Apply inertia to compute a new position
 * based on acceleration, velocity, and time
 *    s = s + v t + 1/2 a t^2
 *****************************************/
void Point::add(Acceleration a, Velocity v, double t)
{
   x += (v.getDX() * t) + (0.5 * a.getDDX() * t * t);
   y += (v.getDY() * t) + (0.5 * a.getDDY() * t * t);
}

/******************************************
 * POINT : insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT : extraction
 *       Prompt for coordinates
 ******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}
   
