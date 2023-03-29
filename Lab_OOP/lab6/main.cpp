#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 122;
int i = 0;
class data
{
   public:
      double arrX[MAX_SIZE / 2];
      double arrY[MAX_SIZE / 2];
      void fileToArr(){
         ifstream inFile("text2.txt");
         while (inFile >> arrX[i] >> arrY[i] && i < MAX_SIZE)
         {
            i++;
         }
         inFile.close();
      }
      void minAndMaxEll() {
         double t, Min = 0, Max = 0, iMin = 0, iMax = 0;
         for (int i = 1; i <= MAX_SIZE / 2; i++)
         {
            if (arrY[i] > Max)
            {
               Max = arrY[i];
               iMax = i;
            }
            if (arrY[i] < Max)
            {
               Min = arrY[i];
               iMin = i;
            }
         }

         cout << "Max: " << Max << "   index: " << iMax << endl;
         cout << "Min: " << Min << "   index: " << iMin << endl;
      }
      void sortArr() {
         int len = sizeof(arrY) / sizeof(arrY[17]);
         // cout << len << endl;

         sort(arrY, arrY + len);
         for (int j = 0; j < i; j++)
         {
            cout << arrY[j] << " ";
         }
      }

};

int main()
{
   data newObj;
   newObj.fileToArr();
   newObj.minAndMaxEll();
   newObj.sortArr();
   return 0;
}
