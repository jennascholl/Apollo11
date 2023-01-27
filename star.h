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
   Point pt;    //The position of a star
   char phase;  //The phase of the star

public:
   //the constructor generates a star
   Star(const Point& pt);

   //reset the game
   void reset(int width, int height);

   //draw the star on the screen 
   void draw(ogstream & gout);

};
