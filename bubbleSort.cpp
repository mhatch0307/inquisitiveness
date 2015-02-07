#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

int ARRAY_SIZE = 10000;

void getFromFile(int* numberList)
{
   ifstream file;
   string num;
   file.open("numberLists/10,000.txt");
   for (int i = 0; file >> num; i++)
   {
      numberList[i] = atoi(num.c_str());
   }
}

void output(int* numberList)
{
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
      cout << numberList[i] << " ";
   }
   cout << endl;
}

void bubbleSort(int* numberList)
{
   int temp;
   bool sorted = false;
   while (!sorted)
   {
      sorted = true;
      for (int i = 0; i < ARRAY_SIZE - 1; i++)
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

int main()
{
   int numberList[ARRAY_SIZE]; 
   getFromFile(numberList);
   bubbleSort(numberList);
   output(numberList);
   return 0;
}