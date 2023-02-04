/***********************************************************************
 * Source File:
 *    Angle Test
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Tests the functionality of the Angle class
 ************************************************************************/

#include "angle.h"

#include <cassert>
#define _USE_MATH_DEFINES    // for M_PI
#include <math.h>


/*********************************
 * MAIN
 * All of the tests are run here
 *********************************/
//int main()
//{
//   // testing the default constructor
//   Angle angle = Angle();
//   assert(angle.getRadians() == 0.0);
//   assert(angle.getDegrees() == 0.0);
//
//   // testing the non-default constructor with standard value
//   Angle angle1 = Angle(180.0);
//   assert(angle1.getDegrees() == 180.0);
//
//   // testing the non-default constructor with value greater than 360
//   Angle angle2 = Angle(540.0);
//   assert(angle2.getDegrees() == 180.0);
//
//   // testing the copy constructor
//   Angle angle3 = Angle(angle1);
//   assert(angle3.getRadians() == M_PI);
//
//   // testing the setters with standard values
//   angle.setDegrees(180.0);
//   assert(angle.getDegrees() == 180.0);
//   angle.setRadians(M_PI);
//   assert(angle.getRadians() == M_PI);
//
//   // testing the setters with values greater than 360 or 2pi
//   angle.setDegrees(540.0);
//   assert(angle.getDegrees() == 180.0);
//   angle.setRadians(3 * M_PI);
//   assert(angle.getRadians() == M_PI);
//
//   // testing the adders with standard values
//   angle.addDegrees(90.0);
//   assert(angle.getDegrees() == 270.0);
//   angle1.addRadians(M_PI);
//   assert(angle1.getRadians() == 2 * M_PI);
//
//   // testing the adders with values greater than 360 or 2pi
//   angle.addDegrees(180.0);
//   assert(angle.getDegrees() == 90.0);
//   angle1.addRadians(M_PI);
//   assert(angle1.getRadians() == M_PI);
//
//   // display
//   angle.display();
//}