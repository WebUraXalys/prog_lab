#include "math.h"
#include "stdio.h"

int main(){
   int a, b;
   float S, s, h, x, N;
   a = 0;
   b = 4;
   N = 1000;
   S = 0;
   h = (b - a)/ N;
   for(int i = 1; i <= N; i++){
      x = a + i * h;
      s += ( 3 * x + 5 );
   }
   S = h * s;
   printf("%f \n", S);

}