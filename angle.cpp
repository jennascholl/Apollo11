/***********************************************************************
 * Source File:
 *    Angle
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about the angle of the lander
 ************************************************************************/

#include "angle.h"

/******************************************
 * ANGLE : CONSTRUCTOR WITH RADIANS
 * Initialize the angle to the passed value
 *****************************************/
Angle::Angle(double radians) : radians(radians)
{
   normalize();
}

/******************************************
 * CONVERT TO DEGREES
 * Convert radians to degrees:
 *     radians / 2pi = degrees / 360
 *****************************************/
double Angle::convertToDegrees(double radians) const
{
   return radians / (2.0 * M_PI) * 360.0;
}

/******************************************
 * CONVERT TO RADIANS
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 *****************************************/
double Angle::convertToRadians(double degrees) const
{
   return (degrees / 360.0) * 2.0 * M_PI;
}

/******************************************
 * NORMALIZE
 * Reduce the angle to between 0 and 2pi 
 * in radians
 *****************************************/
void Angle::normalize()
{
   while (radians > M_PI * 2.0)
      setRadians(radians - (M_PI * 2.0));
   while (radians < -(M_PI * 2))
      setRadians(radians + (M_PI * 2.0));
}

/******************************************
 * ANGLE : SET DEGREES
 * Set the angle with a given number of
 * degrees
 *****************************************/
void Angle::setDegrees(double degrees)
{
   setRadians(convertToRadians(degrees));
}

/******************************************
 * ANGLE : SET RADIANS
 * Set the angle with a given number of
 * radians
 *****************************************/
void Angle::setRadians(double radians)
{
   this->radians = radians;
   normalize();
}

/******************************************
 * ANGLE : ADD RADIANS
 * Add to the angle with a given number of
 * radians
 *****************************************/
void Angle::addRadians(double radians)
{
   this->radians += radians;
   normalize();
}

/******************************************
 * ANGLE : ADD DEGREES
 * Add to the angle with a given number of
 * degrees
 *****************************************/
void Angle::addDegrees(double degrees)
{
   addRadians(convertToRadians(degrees));
}