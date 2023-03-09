#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

class data{
   public:
      float xMin, xMax, c, esp;
      float fun(float x){
         return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
      }

      void cycle(){
         while((xMax - xMin) > esp){
            c = (xMin + xMax) / 2;
            if (fun(c) * fun(xMin) < 0){
               xMax = c;
            }
            if(fun(c) * fun(xMax) < 0){
               xMin = c;
            }
         }
         printf("x = %f fun(x) = %f \n", c, fun(c));
         // cout << "x = " << c << " fun(x) = " << fun(c) << endl;
      }

};
int main(){
      data newObj;
      newObj.esp = 0.00001;
      newObj.xMin = 2;
      newObj.xMax = 3;
      newObj.cycle();
      // newObj.x;
      // newObj.fun();

}