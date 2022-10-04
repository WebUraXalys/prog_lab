#include <stdio.h>
#include <math.h>

int main() {
   float x, xMin, xMax, y;
   xMin = 0;
   xMax = 10;
   x = xMin;
   while (x<=xMax)
   {
      y=3*sin(x)+0.35*x-3.8;
      printf("Result: y = %f", y);
      printf(" x = %f\n", x);
      ++x;
   }
   
}