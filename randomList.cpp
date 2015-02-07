#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void output(int* numberList, int arraySize)
{
   for(int i = 0; i < arraySize; i++)
   {
      cout << numberList[i] << " ";
   }
}

int main()
{
   srand(time(0));
   int arraySize = 500000;
   int numberMax = 200000000;
   int numberList[arraySize];
   for (int i = 0; i < arraySize; i++)
   {
      numberList[i] = rand() % numberMax + 1;
   }
   
   output(numberList, arraySize);
}