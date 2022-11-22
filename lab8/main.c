#include "stdio.h"
#include "math.h"

int main() {
   float s, N, T;
   s = 0;
   N = 200;
   T = 0.02;
   FILE *text = fopen("graph_lab8.txt", "w");
   for (float t = 0; t < 0.02; t = t+ (T/N))
   {
      if (t > 0 && t <= 0.8 * T ){
         printf("%f \n", t);
         s = 7*0.8*t / 0.8*t;
      };
      if (t > 0.8 && t <= 1)
      {
         s = 7 - 7 * t * (t-0.8) / 0.2;
      };
      fprintf(text, "\n%f", t);
      fprintf(text, "    %f", s);
      printf("Result: s = %f", s);
      printf(" t = %f\n", t);
   }
   
}

