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
   int arraySize = 500000;
   int numberList[arraySize];
   int insert = arraySize - 1;
   for (int i = 0; i < arraySize; i++)
   {
      numberList[i] = insert;
      insert--;
   }
   
   output(numberList, arraySize);
}
