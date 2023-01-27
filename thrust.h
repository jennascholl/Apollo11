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
   double vThrust;    // Thrust of main engine, in Newtons (kg m/s^2)

public:
   // constructor
   Thrust() : mainEngine(false), clockwise(false), counterclockwise(false), vThrust(45000.000) {}
   
   // getters
   bool isMain()      const { return mainEngine;       }
   bool isClock()     const { return clockwise;        }
   bool isCounter()   const { return counterclockwise; }
   double getThrust() const { return vThrust;          }

   // setter
   void set(const Interface* pUI);

   void rotation();


};