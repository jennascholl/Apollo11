/***********************************************************************
 * Header File:
 *    Star
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about a star
 ************************************************************************/

#pragma once

#include "point.h"    // for Point
#include "uiDraw.h"   // for ogstream

/*********************************************
 * STAR
 * A single star
 *********************************************/
class Star
{
private:     
   Point pt;             // the position of a star
   unsigned char phase;  // the phase of the star

public:
   // constructor
   Star(const Point& pt) : pt(pt) { reset(); }

   void reset();
   void draw(ogstream & gout);  // can't be const because the phase must change

};
