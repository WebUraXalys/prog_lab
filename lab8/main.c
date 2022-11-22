#include "stdio.h"
#include "math.h"

int main() {
   float s, N;
   s = 0;
   N = 200;
   FILE *text = fopen("graph_lab8.txt", "w");
   for (float t = 0; t < 0.02; t = 0.02/N)
   {
      if (t > 0 && t <= 0.8){
         s = (7*t) / 0.8;
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

