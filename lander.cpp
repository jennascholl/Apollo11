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

}

/******************************************
 * LANDER : DRAW
 * Draw the lander
 *****************************************/
void Lander::draw(ogstream & gout)
{
   gout.drawLander(pt, angle.getRadians());
   gout.drawLanderFlames(pt, angle.getRadians(), thrust.isMain(), thrust.isCounter(), thrust.isClock());

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
      a.setDDY(gravity * (pUI->frameRate() * 3));
      a.setDDX(0);
      return; 
   }

   // set the thruster according to user input
   thrust.set(pUI);

   // adjust our acceleration and fuel accordingly
   if (thrust.isMain())
   {
      double power = thrust.getThrust() / weight;
      a.setDDY(cos(angle.getRadians()) * power + (gravity * (pUI->frameRate() * 3)));
      a.setDDX(-sin(angle.getRadians()) * power);
      fuel = fuel - 10;
   }
   else
   {
      a.setDDY(gravity * (pUI->frameRate() * 3));
      a.setDDX(0);
   }

   // rotate if necessary
   if (thrust.isClock())
   {
      angle.addRadians(0.1);
      fuel = fuel - 1;
   }
   if (thrust.isCounter())
   {
      angle.addRadians(-0.1);
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
void Lander::coast(const Interface * pUI)
{
   v.add(a, pUI->frameRate() * 3.0);
   pt.add(a, v, pUI->frameRate() * 3.0);
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