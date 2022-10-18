#include <stdio.h>
#include <math.h>

float fun(float x)
{
   return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
}

int main()
{
   float x, xMin, xMax, y, c;
   xMin = 2;
   xMax = 3;
   x = xMin;
   while (fabs(xMin - xMax) > 0.00001)
   {
      c = (xMin + xMax) / 2;
      if (fun(c) * fun(xMin) < 0)
      {
         xMax = c;
      }
      if (fun(c) * fun(xMax) < 0)
      {
         xMin = c;
      }
   }
   printf("x = %f fun(x) = %f \n", c, fun(c));
}