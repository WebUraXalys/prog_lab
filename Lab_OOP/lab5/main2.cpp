#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 122; // maximum size of array

int main()
{
   ifstream inFile("text2.txt"); // open the input file
   double arr[MAX_SIZE];           // create a 1D array to store numbers
   int i = 0;
   while (inFile >> arr[i] >> arr[i + 1] && i < MAX_SIZE)
   { // read numbers from file and store in array
      i += 2;
   }
   inFile.close(); // close the input file

   // print the numbers in the array
   // for (int j = 0; j < i; j += 2)
   // {
   //    cout << arr[j] << " " << arr[j + 1] << endl;
   // }
   double t, Min = 0, Max = 0, iMin = 0, iMax = 0;
   for (int i = 1; i <= 122; i += 2)
   {
      cout << i << " " << arr[i] << endl;
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
