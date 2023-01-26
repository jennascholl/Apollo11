/***********************************************************************
 * Header File:
 *    Angle
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about the angle of the lander
 ************************************************************************/

#pragma once

#include <iostream>
#define _USE_MATH_DEFINES    // for M_PI
#include <math.h>

/*********************************************
 * ANGLE
 * A measurement of orientation
 *********************************************/
class Angle
{
private:
   // the member variable
   double radians;

   // special operations
   double convertToDegrees(double radians) const;
   double convertToRadians(double radians) const;
   void normalize();

public:
   // constructors
   Angle() : radians(M_PI) {}
   Angle(double radians);

   // getters
   double getDegrees() const { return convertToDegrees(radians); }
   double getRadians() const { return radians; }

   // setters
   void setDegrees(double d);
   void setRadians(double r);
};

