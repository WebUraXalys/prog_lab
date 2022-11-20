#include <iostream>

using namespace std;

// int main()
// {
//    int n;
//    double a[n];
//    double min = a[0];
//    for (int i = 0; i <= n; i++)
//    {
//       if (a[1] < min){
//          min = m[i];
//       }
//    }

//    cout << "Hello World \n";

//    return 0;
// }

int main()
{
   int i, n, m[n];
   // n = 10;
   cout << "Кількість чисел в масиві";
   // scanf("%d", &n);
   cout << "Input age: ";
   for (i = 0; i < n; i++)
   {
      cin >> m[i]; // Вводим с клавиатуры значение ячейки массива
   }

   for (i = 0; i < 10; i++)
   {
      cout << "m[" << i << "]= " << m[i] << "\n"; // На экран через пробелы выводятся все элементы массива
   }

   system("pause");
   return 0;
}

// int main()
// {
//     int age;
//     double weight;
//     std::cout << "Input age: ";
//     std::cin >> age >> weight;
//     std::cout << "Your age: " << age << "\t your weight: " << weight << std::endl;
//     return 0;
// }