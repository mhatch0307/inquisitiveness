#include <iostream>

using namespace std;

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
		display(numbers, size);
		for(int j = i; j > 0 && numbers[j - 1] > numbers[j]; j--)
		{
			swap (j, j - 1, numbers);
		}
	}
	display(numbers, size);
}

void recursiveInsertionSort(int *numbers, int last, int size)
{
	if(last > 0)
	{ 
		recursiveInsertionSort(numbers, last - 1, size);
		for(int i = last - 1; i > 0 && numbers[i - 1] > numbers[i]; i--)
			swap(i, i - 1, numbers);
	}
	display(numbers, size);
}

int main()
{
	int numbers[] = {10, 7, 14, 3, 2, 13, 8, 5, 12, 4, 9, 6, 11, 1};
	int size = 14;
	insertionSort(numbers, size);
	int numbers2[] = {10, 7, 14, 3, 2, 13, 8, 5, 12, 4, 9, 6, 11, 1};
	cout << endl;
	recursiveInsertionSort(numbers2, size, size);
}