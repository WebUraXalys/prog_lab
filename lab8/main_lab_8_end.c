#include "stdio.h"
#include "math.h"

double sygn (float t) {
   double s;
   float T = 0.02;

   // if (t == 0) {
   //    s = 0;
   // };
   if ((t > 0) && (t <= T/4)){
      s = 5*t /(T/4);
   };
   if ((t > T/4) && (t <= 0.75*T)){
      s = 5*15*(t-T/4) /(0.75*T);
   }
   if ((t > 0.75 * T) && (t <= T))
   {
      s = 5*t / (T/4) - 20;
   }
   if (t == T){
      s = 0;
   }
   return s;
}

int main(){
   float T = 0.3;
   int N = 200;
   int i;
   FILE *text = fopen("graf_1.", "w");
   float t[N], s[N];
   for (i = 0; i < N; i++){
      t[i] = i
   }



   double w;
   w = (2* 3.14159) / T;


}