/***********************************************************************
 * Source File:
 *    VELOCITY
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about the lander's velocity
 ************************************************************************/

#include "velocity.h"

/******************************************
 * VELOCITY : CONSTRUCTOR WITH DX,DY
 * Initialize velocity to the passed dx
 * and dy
 *****************************************/
Velocity::Velocity(double dx, double dy) : dx(0.0), dy(0.0)
{
   setDX(dx);
   setDY(dy);
}

/*********************************************
 * VELOCITY : GET VELOCITY
 * Return the total current velocity
 *    x^2 + y^2 = t^2
 *********************************************/
double Velocity::getSpeed() const
{
   return sqrt((dx * dx) + (dy * dy));
}

/*********************************************
 * VELOCITY : ADD
 * Given an existing velocity, update it
 * with added acceleration and time
 *********************************************/
void Velocity::add(Acceleration a, double t)
{
   dx += a.getDDX() * t;
   dy += a.getDDY() * t;
}