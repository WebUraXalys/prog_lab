#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 122;

int main()
{
   ifstream inFile("text2.txt"); 
   double arr[MAX_SIZE];  
   int i = 0;
   while (inFile >> arr[i] >> arr[i + 1] && i < MAX_SIZE)
   { 
      i += 2;
   }
   inFile.close();

   double t, Min = 0, Max = 0, iMin = 0, iMax = 0;
   for (int i = 1; i <= 122; i += 2)
   {
      if (arr[i] > Max)
      {
         Max = arr[i];
         iMax = i;
      }
      if (arr[i] < Max)
      {
         Min = arr[i];
         iMin = i;
      }
   }

   cout << "Max: " << Max << "   index: " << iMax << endl;
   cout << "Min: " << Min << "   index: " << iMin << endl;

   return 0;
}
