/********************************************************************
* Program:
*    Assignment 18, Merge Sort
*    Brother Ercanbrack, CS235
* Author:
*    Matthew Hatch
* Summary:
*    Implementation of merge sort
*********************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

/********************************************************************
* Class Definition for Merge Sort
*********************************************************************/
class MergeSort
{
public:
   MergeSort(int* input, int size, int* sub1, int* sub2);
   void sort();
   void recursiveSort();
   void display();
   friend ostream & operator << (ostream &out, MergeSort & merge);
private:
   void merge();
   void split();
   int size;
   int sub1Size;
   int sub2Size;
   bool sorted;
   int* merged;
   int* sub1;
   int* sub2;
};
/********************************************************************
* MergeSort default constructor
*********************************************************************/
MergeSort::MergeSort(int* input, int pSize, int* pSub1, int* pSub2)
{
   size = pSize;
   sub1Size = 0;
   sub2Size = 0;
   sub1 = pSub1;
   sub2 = pSub2;
   merged = input;
   sorted = false;
}

/********************************************************************
* merge() merge the l1 and l2 together
*********************************************************************/
void MergeSort::merge()
{ 
   int sub1I = 0;
   int sub2I = 0;
   int mergedI = 0;
   while (sub1I < sub1Size && sub2I < sub2Size)
   {
      if(sub1[sub1I] < sub2[sub2I])
      {
         merged[mergedI] = sub1[sub1I];
         sub1I++;
      }
      else
      {
         merged[mergedI] = sub2[sub2I];
         sub2I++;
      }
      mergedI++;
   }

   while(sub1I < sub1Size)
   { 
      merged[mergedI] = sub1[sub1I];
      sub1I++;
      mergedI++;
   }
   while (sub2I < sub2Size)
   {
      merged[mergedI] = sub2[sub2I];
      sub2I++;
      mergedI++;
   }
}
/********************************************************************
* split() split the merged into l1 and l2 based
*********************************************************************/
void MergeSort::split()
{
   bool first = true;
   sorted = true;
   int prev;
   sub1Size = 0;
   sub2Size = 0;
   int mergedI = 0;
   int sub1I = 0;
   int sub2I = 0;
   while(mergedI < size)
   {
      if (first)
      {
         sub1[sub1I] = merged[mergedI];
         sub1I++;
         sub1Size++;
      }
      else
      {
         sub2[sub2I] = merged[mergedI];
         sub2I++;
         sub2Size++;		
      }
      prev = merged[mergedI];
      mergedI++;
      if (mergedI < size && prev > merged[mergedI])
      {
         sorted = false;
         first = !first;
      }
   }
}

/********************************************************************
* sort() merge sort the vector
*********************************************************************/
void MergeSort::sort()
{
   while(!sorted)
   {
      split();
      merge();
   }
}

void MergeSort::recursiveSort(int low, int high)
{
    int mid;
    if(low < high)
    {

    }
}

void MergeSort::display()
{
   for(int i = 0; i < size; i++)
   {
      cout << merged[i] << " ";
   }
}	

/*********************************g**********************************
* << operator overload for MergeSort
********************************************************************/
ostream & operator << (ostream &out, MergeSort & merge)
{
   for(int i = 0; i < merge.size; i++)
   {
	out << merge.merged[i] << " ";
   }
   return out;
}
/********************************************************************
* Dirver to test the merge sort
*********************************************************************/
int main(int argc, char* argv[])
{
   char* name = new char[80];
   int size;
   if (argc > 1)
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
   ifstream input;
   input.open(name);
   int numbers[size];
   int sub1[size];
   int sub2[size];
   int i = 0;
   int num;
   while (input >> num)
   {
      numbers[i] = num;
      i++;
   }	 
   MergeSort merge = MergeSort(numbers, size, sub1, sub2);
   //merge.display();
   merge.sort();
   merge.display();

}

