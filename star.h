/***********************************************************************
 * Header File:
 *    Star
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about a star
 ************************************************************************/

#pragma once

#include "point.h"   // for Point
#include "uiDraw.h"   // for ogstream

/*********************************************
 * STAR
 * A single star
 *********************************************/
class Star
{
private:        //Member variables needed for drawing the star
   Point pt;             //The position of a star
   unsigned char phase;   //The phase of the star

public:
   //the constructor generates a star
   Star(const Point& pt) : pt(pt) { reset(); }

   //reset the star
   void reset();

   //draw the star on the screen 
   void draw(ogstream & gout);  // can't be const because the phase must change

};
