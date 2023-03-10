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
using namespace std;
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

   // special functions
   double convertToDegrees(double radians) const;
   double convertToRadians(double radians) const;
   void normalize();

public:
   // constructors
   Angle() : radians(0.0) {}
   Angle(double degrees);
   Angle(const Angle& rhs) { radians = rhs.radians; }

   // getters
   double getDegrees() const { return convertToDegrees(radians); }
   double getRadians() const { return radians; }

   // setters
   void setDegrees(double degrees);
   void setRadians(double radians);
   void addDegrees(double degrees);
   void addRadians(double radians);

   void display() const;
};

