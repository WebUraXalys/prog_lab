#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

ofstream myFile("text.txt");

class data
{
   public: 
      float y, xMin, xMax;
      
      void fun(){
         for (float x = xMin; x <= xMax; x++)
         {
            if (x >= -4 && x < -3)
            {
               y = 3;
            }
            else if (x >= -3 && x < 2)
            {
               y = 4;
            }
            else if (x >= 2 && x < 4)
            {
               y = 1;
            }
            cout << x << " " << y << endl;
            myFile << x << "  " << y << endl;
         };
      }
};

int main() {
   data newObj;
   newObj.xMin = -4;
   newObj.xMax = 5;
   newObj.fun();
   myFile.close();
}