#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

ofstream myFile("text2.txt");

class data
{
public:
   float y, xMin, xMax;

   void fun()
   {
      for (float x = xMin; x <= xMax; x += 0.1)
      {
         if(x >= -3 && x < -1.5){
            y = 2;
         } else if (x >= -1.5 && x <= 1.5)
         {
            y = 4 - (x*x);
         } else if (x > 1.5 && x <= 3)
         {
            y = 2;
         }
         cout << x << " " << y << endl;
         myFile << x << "  " << y << endl;
      };
   }
};

int main()
{
   data newObj;
   newObj.xMin = -3;
   newObj.xMax = 3;
   newObj.fun();
   myFile.close();
}