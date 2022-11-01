#include <stdio.h>
#include <math.h>

float fun(float x)
{
   return 3 * sin(sqrt(x)) + 0.35 * x - 0.38;
}

int main()
{
   FILE *text = fopen("lab_6_2_resolt.txt", "w");
   for (float x = 0; x <= 10; x++)
   {
      fprintf(text, "\n%f", x);
      fprintf(text, "   %f", fun(x));
   }
   fclose(text);
   return 0;
}