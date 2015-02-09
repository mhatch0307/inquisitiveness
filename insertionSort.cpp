#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int ARRAY_SIZE = 500000;

void getFromFile(int* numberList)
{
   ifstream file;
   int num;
   file.open("numberLists/500,000.txt");
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

int main()
{
	int numbers[ARRAY_SIZE];
	getFromFile(numbers);
	insertionSort(numbers, ARRAY_SIZE);
	cout << endl;
	display(numbers, ARRAY_SIZE);
	//recursiveInsertionSort(numbers2, size, size);
}
