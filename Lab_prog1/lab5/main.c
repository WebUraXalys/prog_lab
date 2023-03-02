#include <stdio.h>
#include <math.h>

float fun(float x)
{
   return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
}
float fun2(float x)
{
   return (3 * cos(sqrt(x)) / 2 * sqrt(x)) + 0.35;
}

int main()
{
   float xMin, xMax, esp, c;
   xMin = 2;
   xMax = 3;
   esp = 0.0000001;
   do
   {
      c = fun(xMin) / fun2(xMin);
      xMin = xMin - c;
   }
   while (c > esp);
   printf("x = %f fun(x) = %f \n", xMin, fun(xMin));
}