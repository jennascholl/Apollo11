/*************************************************************
 * 1. Name:
 *      Jenna Scholl & Neil Reed
 * 2. Assignment Name:
 *      Lab 05: Apollo 11 Code Complete
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part of this assignment was getting the physics
 *      to look correct. 
 * 5. How long did it take for you to complete the assignment?
 *      It took less than an hour to complete this assignment.
 *****************************************************************/

#pragma once

#include "lander.h"
#include "point.h"
#include "ground.h"
#include "star.h"
#include "uiInteract.h"
#include "thrust.h"

#include <vector>

/*********************************************
 * GAME
 * The main components of the game put together
 *********************************************/
class Game
{
private:
   Point ptUpperRight;
   Lander lander;
   Ground ground;
   std::vector<Star*> stars;

public:
   Game(Point ptUpperRight) : lander(ptUpperRight),
      ground(ptUpperRight), ptUpperRight(ptUpperRight) 
   {
      // spawn 40 stars in random positions
      for (int i = 0; i < 40; i++)
      {
         stars.push_back(new Star(Point(((double) ptUpperRight.getX() * (rand() % 100) / 100),
                                         (double) ptUpperRight.getY() * (rand() % 100) / 100)));
      }
   }
   void reset();
   void input(const Interface* pUI);
   void gamePlay();
   void display();
   Lander getLander() { return lander; }
};

/******************************************
 * GAME : RESET
 * Reset all the components in the game
 *****************************************/
void Game::reset()
{
   for (auto &star : stars)
      star->reset();
   ground.reset();
   lander.reset();
}

/******************************************
 * GAME : INPUT
 * Take input from the user and send it
 * to the lander
 *****************************************/
void Game::input(const Interface* pUI)
{  
   if(lander.isFlying())
      lander.input(pUI);
}

/******************************************
 * GAME : GAMEPLAY
 * The moving parts of the game
 *****************************************/
void Game::gamePlay()
{
   // don't do anything if we're not still flying
   if (!lander.isFlying())
      return;

   // apply inertia to the lander
   lander.coast();

   // check if we still have fuel
   if (lander.getFuel() == 0)
      lander.fuelEmpty();

   // check if we have collided with anything
   if (ground.hitGround(lander.getPosition(), 20))
      lander.crash();
   else if (ground.onPlatform(lander.getPosition(), 20))
      if (lander.getVelocity().getSpeed() > 4)
         lander.crash();
      else
         lander.land();
}

/******************************************
 * GAME : DISPLAY
 * Draw all the components of the game
 *****************************************/
void Game::display()
{
   ogstream gout;

   // draw the elements of the game
   for (auto &star : stars)
      star->draw(gout);
   ground.draw(gout);
   lander.draw(gout);

   // draw the text
   gout.setf(std::ios::fixed | std::ios::showpoint);
   gout.precision(2);
   gout.setPosition(Point(30.0, ptUpperRight.getY() - 30.0));
   gout << "Fuel:\t" << lander.getFuel() 
        << " lbs\nAltitude:\t" << (int)ground.getElevation(lander.getPosition())
        << " meters\nSpeed:\t" << lander.getVelocity().getSpeed() << " m/s";

   // end message
   if (lander.isEmpty())
   {
      gout.setPosition(Point(ptUpperRight.getX() * 0.30, ptUpperRight.getY() * 0.67));
      gout << "Houston, we're out of fuel!";
   }
   if (lander.isDead())
   {
      gout.setPosition(Point(ptUpperRight.getX() * 0.30, ptUpperRight.getY() * 0.67));
      gout << "Houston, we have a problem!";
   }
   else if (lander.isLanded())
   {
      gout.setPosition(Point(ptUpperRight.getX() * 0.30, ptUpperRight.getY() * 0.67));
      gout << "One giant leap for mankind!";
   }
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Game* game = (Game*)p;

   // get input
   game->input(pUI);

   // move the stuff around
   game->gamePlay();

   // draw the screen
   game->display();

}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL,
      "Lunar Lander",
      ptUpperRight);

   // initialize the game class
   Game game(ptUpperRight);

   // set everything into action
   ui.run(callBack, &game);

   return 0;
}
