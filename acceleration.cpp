/***********************************************************************
 * Source File:
 *    Acceleration
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about the lander's acceleration
 ************************************************************************/

#include "acceleration.h"

/******************************************
 * ACCELERATION : CONSTRUCTOR WITH DDX,DDY
 * Initialize acceleration to the passed
 * ddx and ddy
 *****************************************/
Acceleration::Acceleration(double ddx, double ddy) : ddx(0.0), ddy(0.0)
{
   setDDX(ddx);
   setDDY(ddy);
}

/*********************************************
 * ACCELERATION : GET ACCELERATION
 * Return the total current acceleration
 *    x^2 + y^2 = t^2
 *********************************************/
double Acceleration::getAcceleration() const
{ 
   return sqrt((ddx * ddx) + (ddy * ddy)); 
}