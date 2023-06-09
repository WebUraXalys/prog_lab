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
         // return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
         return 0.1 * x * x - 5 * x * log(x) - 1;
      }

      float fun2(float x) {
         return 1 / 5 * x - 5 * log(x) - 5;
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
   obj1.esp = 0.0001;
   obj1.xMin = 1;
   obj1.xMax = 2;
   obj1.fors();

   // data obj2;
   // obj2.esp = 0.0000001;
   // obj2.xMin = 7.5;
   // obj2.xMax = 8;
   // obj2.fors();
   // do {
   //    newObj.c = newObj.fun(newObj.xMin) /newObj.fun2(newObj.xMin);
   //    newObj.xMin = newObj.xMin - newObj.c; 
   // }
   // while(newObj.c > newObj.esp);
   // cout << "x = " << newObj.xMin << " fun(x) = " << newObj.fun(newObj.xMin) << endl;

}
