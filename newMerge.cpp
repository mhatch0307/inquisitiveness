#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.H>
using namespace std;
 
 
void merge(int a[], const int low, const int mid, const int high)
{
	// Variables declaration. 
	int * b = new int[high+1-low];
	int h,i,j,k;
	h=low;
	i=0;
	j=mid+1;
	// Merges the two array's into b[] until the first one is finish
	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	// Completes the array filling in it the missing values
	if(h>mid)
	{
		for(k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	// Prints into the original array
	for(k=0;k<=high-low;k++) 
	{
		a[k+low]=b[k];
	}
	delete[] b;
}
 
void merge_sort( int a[], const int low, const int high )		// Recursive sort ...
{
	int mid;
	if( low < high )
	{
		mid = ( low + high ) / 2;
		merge_sort( a, low, mid );
		merge_sort( a, mid + 1, high );
		merge( a, low, mid, high );
	}
}
 
int main(int argc, char* argv[])
{
	int arraySize;
	char* name = new char[80];
	   if (argc > 2)
	   {
	      name = argv[1];
              arraySize = atoi(argv[2]);
	   }
	   else
	   {
	      cout << "Filename: ";
	      cin >> name;
	      cout << "Array Size: ";
              cin >> arraySize;
	   }
	   ifstream input;
	   input.open(name);
           //int arraySize = 10000;
           int numbers[arraySize];
	   int i = 0;
	   int num;
	   while (input >> num)
	   {
	      numbers[i] = num;
	      i++;
	   }	   
        clock_t t;
        t = clock();
	merge_sort(numbers, 0, (arraySize-1) );  
         t = clock() - t;
        for(int i = 0; i < arraySize; i++)
        {
	   cout << numbers[i] << " ";
        }
         cout << endl << (float)t / CLOCKS_PER_SEC << endl;
	return 0;
}
