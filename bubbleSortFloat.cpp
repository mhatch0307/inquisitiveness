#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

int ARRAY_SIZE = 100000;

void getFromFile(double* numberList)
{
   ifstream file;
   string num;
   file.open("numberLists/100000FloatNums.txt");
   for (int i = 0; file >> num; i++)
   {
      numberList[i] = atof(num.c_str());
   }
}

void output(double* numberList)
{
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
      cout << numberList[i] << " ";
   }
   cout << endl;
}

void bubbleSort(double* numberList)
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
   double numberList[ARRAY_SIZE]; 
   getFromFile(numberList);
   bubbleSort(numberList);
   output(numberList);
   return 0;
}
