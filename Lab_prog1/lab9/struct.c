// #include "stdio.h"
// #include <string.h>

// struct Person {
//    char name[50];
//    int age;
//    char city;
// };

// int main() {
//    struct Person person1;
//    person1.name = "Ura";
//    person1.age = 11;

//    printf("%s\n", person1.name);
//    printf("%d\n", person1.age);
//    char name = "id";
//    printf("%s", name);
// };

#include <stdio.h>
#include <string.h>

// create struct with person1 variable
struct Person
{
   char name[50];
   int citNo;
   float salary;
};

int main()
{

   // assign value to name of person1
   struct Person person1;
   //strcpy(person1.name, "George Orwell");
   person1.name = "George Orwell";
    // assign values to other person1 variables
   person1.citNo = 1984;
   person1.salary = 2500;

   // print struct variables
   printf("Name: %s\n", person1.name);
   printf("Citizenship No.: %d\n", person1.citNo);
   printf("Salary: %.2f\n", person1.salary);

   return 0;
}
