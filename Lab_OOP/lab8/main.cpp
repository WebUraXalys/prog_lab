#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double sygn(float t)
{
   double s;
   float T = 0.02;

   if (t == 0){
      s = 0;
   }
   if ((t > 0) && (t <= 0.8 * T)){
      s = 7 * t / (0.8 * T);
   }
   if ((t > 0.8 * T) && (t <= T))
      s = 7 - 28 * (t - 0.8 * T) / (0.8 * T);
   if (t == T)
      s = 0;

   return s;
}
int main()
{
   const float T = 0.02;
   const int N = 200;
   int i;
   ifstream inFile("graf1.txt");
   double w;
   w = (2 * 3.14159) / T;
   float h;
   h = T / N;
   float t[N], s[N];
   for (i = 0; i < N; i++)
   {
      t[i] = i * h;
      s[i] = sygn(t[i]);
      inFile >> t[i] >> s[i];
   }
   inFile.close();

   // Part3

   double a0 = 0;
   double Sum = 0;
   for (i = 1; i < N; i++)
   {
      Sum += s[i];
   }
   a0 = 2 / T * h * Sum;
   cout << "a0 = " << a0 << endl;
   // printf("a0 = %f\n", a0);

   int k = 10;
   float a[k], b[k];
   for (k = 1; k <= 10; k++)
   {

      Sum = 0;
      for (i = 1; i < N; i++)
      {
         Sum += s[i] * cos(k * w * t[i]);
      }
      a[k - 1] = 2 * h * Sum / T;
      cout << "ak = " << a[k - 1] << endl;
      // printf("ak = %f\n", a[k - 1]);

      Sum = 0;
      for (i = 1; i < N; i++)
      {
         Sum += s[i] * sin(k * w * t[i]);
      }
      b[k - 1] = 2 * h * Sum / T;
      cout << "bk = " << b[k - 1] << endl;
      // printf("bk = %f\n", b[k - 1]);
   }

   // Part4

   ofstream inFile2("graf1.txt");
   float Suma = 0;
   for (i = 1; i < N; i++)
   {
      Suma = a0 / 2;
      for (k = 1; k <= 10; k++)
      {
         Suma = Suma + a[k - 1] * cos(k * w * t[i]) + b[k - 1] * sin(k * w * t[i]);
      }
      inFile2 >> t[i] >> Suma;
      // fprintf(graf2, "%f %f\n", t[i], Suma);
   }
   inFile2.close();
   return 0;
}