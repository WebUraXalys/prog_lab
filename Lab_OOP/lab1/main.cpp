#include <iostream>
#include <cmath>

using namespace std;
class date
{
public:
   float x, xMin, xMax, y;
   void func()
   {
      for (x = 1; x <= xMax; x+=0.1)
      {
         y = cos(2 / x) - 2 * sin(1 / x) + 1 / x;
         cout << "Result: y = " << y;
         cout << " x = " << x << endl;
      }
   }
};

int main()
{
   date newObj;

   newObj.x = 0;
   newObj.xMin = 1;
   newObj.xMax = 2;
   newObj.func();

   return 0;
}
