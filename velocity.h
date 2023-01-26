/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about the lander's velocity
 ************************************************************************/


#pragma once

#include "acceleration.h"

#include <math.h> // for sqrt()

 /*********************************************
  * VELOCITY
  * The speed at which something travels
  *********************************************/
class Velocity
{
private:
   // member variables
   double dx;
   double dy;

public:
   // constructors
   Velocity() : dx(0), dy(0)   {}
   Velocity(double dx, double dy);

   // getters
   double getDX()    const { return dx; }
   double getDY()    const { return dy; }
   double getSpeed() const;

   // setters
   void setDX(const double &dx) { this->dx = dx; }
   void setDY(const double &dy) { this->dy = dy; }

   // special functions
   void add(Acceleration a, double t);

};