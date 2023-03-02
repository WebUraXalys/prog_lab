#include <stdio.h>
#include <math.h>

int main() {
   float x, y, answer;
   printf("Введіть X: ");
   scanf("%f", &x);
   printf("Введіть Y: ");
   scanf("%f", &y);
   // x = 0;
   // y = 0;
   printf("%f\n", x);
   printf("%f\n", y);

   if (x*y > 0) {
      answer = (x * x + y) * (x * x + y) - sqrt(x * x * y);
      } else if (x*y < 0){
         answer = (x * x + y) * (x * x + y) + sqrt(fabs(x * x * y));
      } else if (x*y == 0){
         answer = (x * x + y) * (x * x + y) + 1;
      } 
   printf("Result: %f\n", answer);
   return 0;
}

