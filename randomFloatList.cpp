#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void output(float* numberList, int arraySize)
{
   for(int i = 0; i < arraySize; i++)
   {
      cout << numberList[i] << " ";
   }
}

int main()
{
   srand(time(0));
   int arraySize = 1000000;
   int numberMax = 200000000;
   float numberList[arraySize];
   for (int i = 0; i < arraySize; i++)
   {
      numberList[i] = (rand() % (numberMax) + 1) / 10000.0;
   }
   
   output(numberList, arraySize);
}
