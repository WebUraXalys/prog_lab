#include <stdio.h>
#include <math.h>

int main()
{
   float x, xMin, xMax, y;
   xMin = 0;
   xMax = 10;
   x = xMin;
   FILE *text = fopen("lab_6_resolt.txt", "w");
   while (x <= xMax)
   {
      y = 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
      fprintf(text, "\n%f", y);
      fprintf(text, "   %f", x);
      printf("Result: y = %f", y);
      printf(" x = %f\n", x);
      x = x + 0.5;
   }
   fclose(text);
   return 0;
}