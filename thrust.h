/***********************************************************************
 * Header File:
 *    Thrust
 * Author:
 *    Jenna Scholl & Neil Reed
 * Summary:
 *    Everything we need to know about the lander's thrust
 ************************************************************************/

#pragma once

#include "uiInteract.h"

 /*********************************************
  * THRUST
  * Are we rotating or moving up?
  *********************************************/
class Thrust
{
private:
   // member variables
   bool mainEngine;
   bool clockwise;
   bool counterclockwise;

public:
   // constructor
   Thrust() : mainEngine(false), clockwise(false), counterclockwise(false) {}
   
   // getters
   bool isMain()    const { return mainEngine;       }
   bool isClock()   const { return clockwise;        }
   bool isCounter() const { return counterclockwise; }

   // setter
   void set(const Interface* pUI);

   void rotation();


};