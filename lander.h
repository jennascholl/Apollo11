/***********************************************************************
 * Header File:
 *    Lander
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Holds all of the necessary states of the lander
 ************************************************************************/

#pragma once

#include "point.h"
#include "velocity.h"
#include "angle.h"
#include "uiDraw.h"
#include "thrust.h"
#include "uiInteract.h"

#include <math.h>

enum status { FLYING, LANDED, DEAD };

/*********************************************
 * LANDER
 * The Lunar Lander
 *********************************************/
class Lander
{
private:
   // member variables
   status currentState;
   Point pt;
   Point ptUpperRight;
   Velocity v;
   Acceleration a;
   Angle angle;
   int fuel;
   Thrust thrust;

public:
   // constructor
   Lander(Point ptUpperRight) : ptUpperRight(ptUpperRight), pt(ptUpperRight)
   {
      reset();
   }

   // getters
   bool isDead();
   bool isLanded();
   bool isFlying();
   Point getPosition()    { return pt;   }
   Velocity getVelocity() { return v;    }
   int   getFuel()        { return fuel; }

   // setters

   void coast(const Interface * pUI);
   void land();
   void crash();

   // special functions
   void reset();
   void draw(ogstream & gout);
   void input(const Interface * pUI);
};