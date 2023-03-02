#include <iostream>
#include <cmath>

using namespace std;
class date
{
public:
   float x, xMin, xMax, y;
   void func()
   {
      for (x = 0; x <= xMax; x+=0.5)
      {
         y = 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
         cout << "Result: y = " << y;
         cout << " x = " << x << endl;
      }
   }
};

int main()
{
   date newObj;

   newObj.x = 0;
   newObj.xMin = 0;
   newObj.xMax = 10;
   newObj.func();

   return 0;
}
