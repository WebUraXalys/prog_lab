#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int n;
   cout << "Введіть кількість елементів масива : ";
   cin >> n;
   // double A[n] = {9, 8, 7, 6, 5, 4, 4, 3, -2, 2.2};
   double A[n];
   for (int i = 0; i < n; i++)
   {
      cout << "елемент[" << i << "] = ";
      cin >> A[i];
   }
   sort(A, n + A);
   double new_A[n];
   if (A[0] >= 0)
   {
      for (int i = 0; i < n; ++i)
      {
         new_A[i] = A[i] * (A[0] * A[0]);
         cout << new_A[i] << endl;
      }
   }
   else if (A[0] < 0)
   {
      for (int i = 0; i < n; ++i)
      {
         new_A[i] = A[i] * (A[n - 1] * A[n - 1]);
         cout << new_A[i] << endl;
      }
   }

   return 0;
}