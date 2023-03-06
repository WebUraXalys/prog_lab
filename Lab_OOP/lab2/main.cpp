#include <iostream>
#include <cmath>

using namespace std;

class data
{
   // private:
   //    float esp;
   public:
      // float esp = 0.0000001;
      float xMin, xMax, esp, c;
      float fun(float x){
         return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
      }

      float fun2(float x) {
         return (3 * cos(sqrt(x)) / 2 * sqrt(x)) + 0.35;
      }
      void fors(){
         do
         {
            c = fun(xMin) / fun2(xMin);
            xMin = xMin - c;
         } while (c > esp);
         cout << "x = " << xMin << " fun(x) = " << fun(xMin) << endl;
      }

};

int main(){
   data obj1;
   obj1.esp = 0.0000001;
   obj1.xMin = 2;
   obj1.xMax = 2.5;
   obj1.fors();

   data obj2;
   obj2.esp = 0.0000001;
   obj2.xMin = 7.5;
   obj2.xMax = 8;
   obj2.fors();
   // do {
   //    newObj.c = newObj.fun(newObj.xMin) /newObj.fun2(newObj.xMin);
   //    newObj.xMin = newObj.xMin - newObj.c; 
   // }
   // while(newObj.c > newObj.esp);
   // cout << "x = " << newObj.xMin << " fun(x) = " << newObj.fun(newObj.xMin) << endl;

}
