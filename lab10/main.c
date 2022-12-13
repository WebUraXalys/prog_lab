#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
   FILE *graf = fopen("graf.txt", "r");
   double t, Min = 0, Max = 0, iMin = 0, iMax = 0;
   char s[400];
   if (graf == NULL)
   {
      printf("no such file.");
      return 0;
   }
   for (int i = 0; i <= 400; i++)
   {
      fscanf(graf, "%s", s);
      t = atof(s);
      if (t > Max)
      {
         Max = t;
         iMax = i;
      }
      if (t < Min)
      {
         Min = t;
         iMin = i;
      }
   }
   printf("Max значення графіка = %.4f\t його індекс  = %.1f\nMin значення графіка = %.4f\t його індекс = %.1f\n", Max, iMax, Min, iMin);
   return 0;
}