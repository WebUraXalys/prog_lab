#include "stdio.h"
#include "math.h"

int main() {
   float sum, ser;
   sum = 0;
   int A[] = {7,7,7,7,7,6,6,6,6,8,9,11,11,12,12,11,10,8,8,7,7,6,6,6};
   for (int i = 0; i < 24; i++)
   {
      sum = sum + A[i];
      // printf("%f\n", sum);
   }
   ser = sum / 24;
   printf("%f\n", ser);
}