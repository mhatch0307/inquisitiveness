#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int ARRAY_SIZE = 20;

void getRandomNumbers(int* numberList)
{
   srand(time(0));
   for (int i = 0; i < ARRAY_SIZE; i++)
   {
      numberList[i] = rand() % 1001;
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
   if(!sorted)
      bubbleSort(numberList);
}

int main()
{
   int numberList[ARRAY_SIZE]; 
   getRandomNumbers(numberList);
   bubbleSort(numberList);
   output(numberList);
   return 0;
}