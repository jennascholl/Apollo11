/***********************************************************************
 * Header File:
 *    Lander
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Holds all of the necessary states of the lander
 ************************************************************************/

#pragma once

#include "point.h"        // for pt & ptUpperRight
#include "angle.h"        // for angle
#include "uiDraw.h"       // for draw()
#include "thrust.h"       // for thrust
#include "uiInteract.h"   // for input()

#include <math.h>         // for sin and cosine

enum status { FLYING, LANDED, DEAD, EMPTY };

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
   Lander(Point ptUpperRight) : ptUpperRight(ptUpperRight), 
               pt(ptUpperRight.getX(), ptUpperRight.getY() - 50.0) { reset(); }

   // getters
   bool isDead();
   bool isLanded();
   bool isFlying();
   bool isEmpty();
   Point getPosition()    { return pt;   }
   Velocity getVelocity() { return v;    }
   int   getFuel()        { return fuel; }

   // setters

   void coast();
   void land();
   void crash();
   void fuelEmpty();

   // special functions
   void reset();
   void draw(ogstream & gout);
   void input(const Interface* pUI);
};
