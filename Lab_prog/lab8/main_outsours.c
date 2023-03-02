#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x, float T)
{
   float x1, x2, y1, y2;
   if (x > 0 && x <= 0.3 * T)
   {
      x1 = 0;
      y1 = 0;
      x2 = 0.3 * T;
      y2 = 7;
   }
   if (x >= 0.3 * T && x <= T)
   {
      x1 = 0.3 * T;
      y1 = 7;
      x2 = T, y2 = 0;
   }
   return (x - x1) * (y2 - y1) / (x2 - x1) + y1;
}

int main()
{
   FILE *file = fopen("dant.txt", "w+");
   float N = 200, T = 0.03;
   for (float i = 0; i < T; i = i + T / N)
   {
      fprintf(file, "%f       %f\n", i, f(i, T));
   }
   fclose(file);
   return 0;
}