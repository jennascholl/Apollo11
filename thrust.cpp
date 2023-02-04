/***********************************************************************
 * Source File:
 *    Thrust
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about the lander's thrust
 ************************************************************************/

#include "thrust.h"

/******************************************
 * THRUST : SET
 * Use user input to set mainEngine, 
 * clockwise, and counterclockwise appropriately
 ******************************************/
void Thrust::set(const Interface* pUI)
{
   // down arrow activates the main engine
   if (pUI->isDown())
      mainEngine = true;
   else
      mainEngine = false;

   // left arrow rotates counterclockwise
   if (pUI->isLeft())
      counterclockwise = true;
   else
      counterclockwise = false;

   // right arrow rotates clockwise
   if (pUI->isRight())
      clockwise = true;
   else
      clockwise = false;
}