#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

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

void swap(int indexOne, int indexTwo, int *numbers)
{
	int temp = numbers[indexOne];
	numbers[indexOne] = numbers[indexTwo];
	numbers[indexTwo] = temp;
}

void display(int * numbers, int size)
{
	for (int i = 0; i < size; i++)
		cout << numbers[i] << " ";
	cout << endl;
}

void insertionSort(int *numbers, int size)
{ 
	for(int i = 0; i < size; i++)
	{
		for(int j = i; j > 0 && numbers[j - 1] > numbers[j]; j--)
		{
			swap (j, j - 1, numbers);
		}
	}
	//display(numbers, size);
}

void recursiveInsertionSort(int *numbers, int last, int size)
{
	if(last > 0)
	{ 
		recursiveInsertionSort(numbers, last - 1, size);
		for(int i = last - 1; i > 0 && numbers[i - 1] > numbers[i]; i--)
			swap(i, i - 1, numbers);
	}
	//display(numbers, size);
}

int main(int argc, char* argv[])
{
   char* name = new char[80];
   int size;
   if (argc > 2)
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
	int numbers[size];
	getFromFile(numbers, name);
           clock_t t;
          t = clock();
	insertionSort(numbers, size);
           t = clock() - t;
	cout << endl;
	display(numbers, size);
         cout << endl << (float)t / CLOCKS_PER_SEC << endl;
	//recursiveInsertionSort(numbers2, size, size);
}
