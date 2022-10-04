#include <stdio.h>
#include <math.h>
int main() {
   float x, y, z, t;
   float PI = 3.1415926;
   x = 14.26;
   y = -1.22;
   z = 0.035;
   int k = 2;
   float w1 = 2*cos(x-PI/6);
   float w2 = 0.5 + pow(sin(y), 2);
   float w3 = pow(z, 2) / (3 - (pow(z, 2)/5)) + 1;
   t = (w1/w2) * w3;
   printf("Result: %f\n", t);
   return 0;
}