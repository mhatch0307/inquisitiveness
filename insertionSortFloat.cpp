#include <iostream>
#include <fstream>

using namespace std;

int ARRAY_SIZE = 500000;

void getFromFile(float* numberList)
{
   ifstream file;
   float num;
   file.open("numberLists/500000FloatNums.txt");
   for (int i = 0; file >> num; i++)
   {
      numberList[i] = num;//atoi(num.c_str());
   }
}

void swap(int indexOne, int indexTwo, float *numbers)
{
	int temp = numbers[indexOne];
	numbers[indexOne] = numbers[indexTwo];
	numbers[indexTwo] = temp;
}

void display(float *numbers, int size)
{
	for (int i = 0; i < size; i++)
		cout << numbers[i] << " ";
	cout << endl;
}

void insertionSort(float *numbers, int size)
{ 
	for(int i = 0; i < size; i++)
	{
		for(int j = i; j > 0 && numbers[j - 1] > numbers[j]; j--)
		{
			swap (j, j - 1, numbers);
		}
	}
}

void recursiveInsertionSort(float *numbers, int last, int size)
{
	if(last > 0)
	{ 
		recursiveInsertionSort(numbers, last - 1, size);
		for(int i = last - 1; i > 0 && numbers[i - 1] > numbers[i]; i--)
			swap(i, i - 1, numbers);
	}
}

int main()
{
	float numbers[ARRAY_SIZE];
	getFromFile(numbers);
	insertionSort(numbers, ARRAY_SIZE);
	cout << endl;	
	display(numbers, ARRAY_SIZE);

	//recursiveInsertionSort(numbers2, size, size);
}
