/***********************************************************************
 * Source File:
 *    Lander : The Lunar Lander itself
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Holds all of the necessary states of the lander
 ************************************************************************/

#include "lander.h"
#include <iostream>     

const double GRAVITY = -1.625;   // vertical acceleration due to gravity, in m/s^2
const double WEIGHT = 15103.000; // weight in KG
const double TIME = 0.100;       // the rate in seconds per frame

using namespace std;

/******************************************
 * LANDER : IS DEAD
 * Has the lander crashed?
 *****************************************/
bool Lander::isDead()
{
   if (currentState == DEAD)
      return true;
   else
      return false;
}

/******************************************
 * LANDER : IS LANDED
 * Has the lander successfully landed?
 *****************************************/
bool Lander::isLanded()
{
   if (currentState == LANDED)
      return true;
   else
      return false;
}

/******************************************
 * LANDER : IS FLYING
 * Is the lander still flying?
 *****************************************/
bool Lander::isFlying()
{
   if (currentState == FLYING)
      return true;
   else
      return false;
}

/******************************************
 * LANDER : RESET
 * Reset all the lander's states
 *****************************************/
void Lander::reset()
{
   fuel = 5000;
   angle = 0.0;
   v.setDX(-5.0);
   v.setDY(0.0);
   currentState = FLYING;
}

/******************************************
 * LANDER : DRAW
 * Draw the lander
 *****************************************/
void Lander::draw(ogstream & gout)
{
   gout.drawLander(pt, angle.getRadians());
   // no flames if there's no fuel or if we've crashed or landed
   if (fuel != 0 && isFlying())
      gout.drawLanderFlames(pt, angle.getRadians(), thrust.isMain(), 
                         thrust.isCounter(), thrust.isClock());

}

/******************************************
 * LANDER : INPUT
 * Adjust the lander's position and rotation
 * based on user input
 *****************************************/
void Lander::input(const Interface * pUI)
{
   // we can't use the thruster with no fuel
   if (fuel == 0)
   {
      a.setDDY(GRAVITY);
      a.setDDX(0);
      return; 
   }

   // set the thruster according to user input
   thrust.set(pUI);

   // adjust our acceleration and fuel accordingly
   if (thrust.isMain())
   {
      double power = thrust.getThrust() / WEIGHT;
      a.setDDY(cos(angle.getRadians()) * power + GRAVITY);
      a.setDDX(-sin(angle.getRadians()) * power);
      fuel = fuel - 10;
   }
   else
   {
      a.setDDY(GRAVITY * 1.0);
      a.setDDX(0);
   }

   // rotate if necessary
   if (thrust.isClock())
   {
      angle.addRadians(-0.1);
      fuel = fuel - 1;
   }
   if (thrust.isCounter())
   {
      angle.addRadians(0.1);
      fuel = fuel - 1;
   }

   // we can't have negative fuel
   if (fuel < 0)
      fuel = 0;
}

/******************************************
 * LANDER : COAST
 * Apply inertia to move the lander
 *****************************************/
void Lander::coast()
{
   v.add(a, TIME);
   pt.add(a, v, TIME);
}

/******************************************
 * LANDER : LAND
 * Successfully put the lander on the ground
 *****************************************/
void Lander::land()
{
   currentState = LANDED;
   angle.setDegrees(0.0);
}

/******************************************
 * LANDER : CRASH
 * Kill the lunar lander
 *****************************************/
void Lander::crash()
{
   currentState = DEAD;
   angle.setDegrees(180.0);
}