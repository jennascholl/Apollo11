/***********************************************************************
 * Source File:
 *    Star
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about a star
 ************************************************************************/

#include "star.h"    //for the Star class definition
#include "uiDraw.h"  //for random() 

 /*****************************************************************
  * STAR : RESET
  * Reset the star's state
  ****************************************************************/
void Star::reset()
{
   phase = random(0, 255);
}

/*****************************************************************
 * STAR : DRAW
 * Draw a star on the screen
 ****************************************************************/
void Star::draw(ogstream& gout)
{
   gout.drawStar(pt, phase++);
}