/********************************************************************
* Program:
*    Assignment 17, Heap Sort
*    Brother Ercanbrack, CS235
* Author:
*    Matthew Hatch
* Summary:
*    Huffman Code
********************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;

/**********************************************************
* class deffinition for heap sort
***********************************************************/
class Heap
{
private:
  float* heap;
public:
   Heap(int size);
   ~Heap();
   void convertToHeap();
   int mySize;
   int retrieveMaxItem() { return heap[1]; } // return teh max item in heap
   void deleteMaxItem();
   void percolateDown(int r, int n);
   void sort();
   void recursiveSort(int index);
   friend istream & operator >> (istream &in, Heap &h);
   friend ostream & operator << (ostream &out, const Heap &h);
};

/**********************************************************
 * insertion operator overload, inserts data into heap vector
 *        and converts it to heap
 ***********************************************************/
istream & operator >> (istream &in, Heap &h)
{
   float next;
   while(in >> next)
   {
      h.heap[h.mySize] = next;
      h.mySize++;
   }
   h.convertToHeap();
   return in;
}

/**********************************************************
 * extraction operator overload, outputs heat in ascending
 * order 
 ***********************************************************/
ostream & operator << (ostream & out, const Heap &h)
{
   for (int i = 0; i < h.mySize; i++)
      out << h.heap[i] << " ";
   out << endl;
   return out;
}

/**********************************************************
 * default constructor
 ***********************************************************/
Heap::Heap(int pSize)
{
   mySize = 0;
   heap = new int[pSize];
}

Heap::~Heap()
{
   delete heap;
}

/**********************************************************
* sort the heap into ascending order
***********************************************************/
void Heap::sort()
{
   int temp;
   for (int i = mySize; i >= 1; i--)
   {
      temp = heap[0];
      heap[0] = heap[i];
      heap[i] = temp;
      percolateDown(0, i-1);
   }
}

void Heap::recursiveSort(int index)
{
   if(index >= 2)
   {
      int temp = heap[0];
      heap[0] = heap[index];
      heap[index] = temp;
      percolateDown(0, --index);
      recursiveSort(index);
   }
}

/**********************************************************
* convertToHeap converts binary tree to heap
***********************************************************/
void Heap::convertToHeap()
{
   for (int r = (mySize / 2); r >= 0; r--)
   {
      percolateDown(r, mySize);
   }
}

/**********************************************************
* prelocateDown() converts semi heap to heap
***********************************************************/
void Heap::percolateDown(int r, int n)
{
   int c = 2 * r;
   int temp;
   while (c <= n)
   {
      if (c < n && heap[c] < heap[c + 1])
      {
         c++;
      }
      
      if (c <= mySize && heap[r] < heap[c])
      {
         temp = heap[r];
         heap[r] = heap[c];
         heap[c] = temp;
         r = c;
         c = c * 2;
      }
      else
      {
         break;
      }
   }
}


/**********************************************************
* main driver function
***********************************************************/
int main(int argc, char* argv[])
{
   int size;
   char* fileName = new char[80];
   if (argc > 2)
   {
      fileName = argv[1];
      size = atoi(argv[2]);
   }
   else
   {
      cout << "File name: ";
      cin >> fileName;
     cout << "Size :";
     cin >> size;
   }

   ifstream inFile;
   inFile.open(fileName);
   Heap heap = Heap(size);
   inFile >> heap;
   clock_t t;
   t = clock();
   heap.sort();
   t = clock() - t;
   cout << heap;
   cout << endl << (float)t / CLOCKS_PER_SEC << endl;
   //inFile >> heap;
  // heap.recursiveSort(heap.mySize);
   //cout << heap;
}
