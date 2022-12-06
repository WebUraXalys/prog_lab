#include "stdio.h"
#include "math.h"

const float T = 0.03;
const int N = 200;
int i;
float sygn(float t)
{
   float x1, x2, y1, y2;
   float s;
   if (t > 0 && t <= T / 3)
   {
      x1 = 0;
      y1 = 0;
      x2 = T / 3;
      y2 = 5;
   }
   if (t >= T / 3 && t <= 0.9 * T)
   {
      x1 = T / 3;
      y1 = 5;
      x2 = 0.9 * T;
      y2 = -3;
   }
   if (t > 0.9 * T && t <= T)
   {
      x1 = 0.9 * T;
      y1 = -3;
      x2 = T;
      y2 = 0;
   }
   return s = (t - x1) * (2 - y1) / (x2 - x1) + y1;
}
int main()
{

   FILE *text = fopen("answer.txt", "w");
   double w;
   w = (2 * 3.14159) / T;
   float h;
   h = T / N;
   float t[N], s[N];
   for (i = 0; i < N; i++)
   {
      t[i] = i * h;
      s[i] = sygn(t[i]);
      fprintf(text, "%f %f/n", t[i], s[i]);
   }
   fclose(text);

   // Part3
   double a0 = 0;
   double Suma = 0;
   for (i = 0; i < N; i++)
   {
      Suma += s[i];
   }
   a0 = 2 / T * h * Suma;
   printf("a0 = %f/n", a0);

   int k = 10;
   float a[k], b[k];
   for (k = 1; k <= 10; k++)
   {

      Suma = 0;
      for (i = 0; i < N; i++)
      {
         Suma += s[i] * cos(k * w * t[i]);
      }
      b[k - 1] = 2 * h * Suma / T;
      printf("bk = %f/n", b[k - 1]);
   }
   // Part4
   FILE *text2 = fopen("answer2.txt", "w");
   float Sm = 0;
   for (i = 0; i < N; i++)
   {
      Sm = a0 / 2;
      for (k = 1; k <= 10; k++)
      {
         Sm = Sm + a[k - 1] * cos(k * w * t[i]) + b[k - 1] * sin(k * w * t[i]);
      }
      fprintf(text2, "%f %f/n", t[i], Sm);
   }
   fclose(text2);
   return 0;
}
