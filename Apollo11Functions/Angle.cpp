/*************************************************************
 * 1. Name:
 *      Jenna Scholl and Neil Reed
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      Represent angles with a class
 * 4. What was the hardest part? Be as specific as possible.
 *      Determining the proper usage of normalize()
 * 5. How long did it take for you to complete the assignment?
 *      1 hour
 *****************************************************************/

using namespace std;

#define _USE_MATH_DEFINES    // for M_PI
#include <math.h>
#include <iostream>          // for CIN and COUT

/*********************************************
 * ANGLE
 * Represents an angle using both radians
 * and degrees
 *********************************************/
class Angle
{
public:
   // constructors
   Angle() : radians(M_PI) {}
   Angle(double r) { radians = r; }

   // getters
   double getDegrees() const { return convertToDegrees(radians); }
   double getRadians() const { return radians;                   }

   // setters
   void setDegrees(double d)
   {
      radians = convertToRadians(d);
      normalize();
   }
   void setRadians(double r)
   {
      radians = r;
      normalize();
   }

   /*************************************************
    * DISPLAY
    * Display the angle, in degrees, to 1 decimal
    * place of accuracy
    **************************************************/
   void display()
   {
      cout.setf(ios::fixed | ios::showpoint);
      cout.precision(1);

      cout << convertToDegrees(radians);
   }

private:
   double radians;             // angle in radians

   /*************************************************
    * CONVERT TO DEGREES
    * Convert radians to degrees:
    *     radians / 2pi = degrees / 360
    * INPUT
    *     r : radians from 0 to 2pi
    * OUTPUT
    *     d : degrees from 0 to 360
    **************************************************/
   double convertToDegrees(double r) const
   {
      return r / (2.0 * M_PI) * 360.0;
   }

   /*************************************************
    * CONVERT TO RADIANS
    * Convert degrees to radians:
    *     radians / 2pi = degrees / 360
    * INPUT
    *     d : degrees from 0 to 360
    * OUTPUT
    *     r : radians from 0 to 2pi
    **************************************************/
   double convertToRadians(double d) const
   {
      return (d / 360.0) * 2.0 * M_PI;
   }

   /*************************************************
    * NORMALIZE
    * Reduce the angle to between 0 and 2pi in radians
    **************************************************/
   void normalize()
   {
      while (radians > M_PI * 2.0)
         setRadians(radians - (M_PI * 2.0));
      while (radians < -(M_PI * 2))
         setRadians(radians + (M_PI * 2.0));
   }
};

/****************************************************************
* MAIN
* A driver program to test the angle class
****************************************************************/
int main()
{
   Angle testAngle;

   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(1);

   cout << "===== SET & GET RADIANS =====" << endl;
   testAngle.setRadians(M_PI * 2.0);
   cout << "Input:" << endl;
   cout << "\t" << M_PI * 2.0 << " radians" << endl;
   cout << "Output:" << endl;
   cout << "\tRadians: " << testAngle.getRadians() << endl;
   cout << "\tDegrees: " << testAngle.getDegrees() << endl;

   cout << "\n===== SET & GET DEGREES =====" << endl;
   testAngle.setDegrees(45.0);
   cout << "Input:" << endl;
   cout << "\t" << 45.0 << " degrees" << endl;
   cout << "Output:" << endl;
   cout << "\tRadians: " << testAngle.getRadians() << endl;
   cout << "\tDegrees: " << testAngle.getDegrees() << endl;

   cout << "\n==== NORMALIZE & DISPLAY ====" << endl;
   testAngle.setDegrees(540.0);
   cout << "Input:" << endl;
   cout << "\t" << 540.0 << " degrees" << endl;
   cout << "Output:" << endl;
   cout << "\t";
   testAngle.display();
   cout << " degrees" << endl;

   return 0;
}