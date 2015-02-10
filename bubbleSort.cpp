#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

void getFromFile(int* numberList, char* name)
{
   ifstream file;
   int num;
   file.open(name);
   for (int i = 0; file >> num; i++)
   {
      numberList[i] = num;//atoi(num.c_str());
   }
}

void output(int* numberList, int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << numberList[i] << " ";
   }
   cout << endl;
}

void bubbleSort(int* numberList, int size)
{
   int temp;
   bool sorted = false;
   while (!sorted)
   {
      sorted = true;
      for (int i = 0; i < size - 1; i++)
      {
         if (numberList[i] > numberList[i+1])
         {
            temp = numberList[i];
            numberList[i] = numberList[i+1];
            numberList[i+1] = temp;
            sorted = false;
         }
      }
   }
}

int main(int argc, char* argv[])
{
  char* name = new char[80];
   int size;
   if (argc > 1)
   {
      name = argv[1];
      size = atoi(argv[2]);
   }
   else
   {
      cout << "Filename: ";
      cin >> name;
      cout << "Size: ";
      cin >> size;
   }
   int numberList[size]; 
   getFromFile(numberList, name); 
   clock_t t;
   t = clock();
   bubbleSort(numberList, size);
    t = clock() - t;
   output(numberList, size);
   cout << endl << (float)t / CLOCKS_PER_SEC << endl;
   return 0;
}
