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
using namespace std;

/**********************************************************
* class deffinition for heap sort
***********************************************************/
class Heap
{
private:
   vector <float> heap;
public:
   Heap();
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
      h.heap.push_back(next);
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
   for (int i = 1; i <= h.mySize; i++)
      out << h.heap[i] << " ";
   out << endl;
   return out;
}

/**********************************************************
 * default constructor
 ***********************************************************/
Heap::Heap()
{
   mySize = 0;
   heap.push_back(0);
}

/**********************************************************
* sort the heap into ascending order
***********************************************************/
void Heap::sort()
{
   int temp;
   for (int i = mySize; i >= 2; i--)
   {
      temp = heap[1];
      heap[1] = heap[i];
      heap[i] = temp;
      percolateDown(1, i-1);
   }
}

void Heap::recursiveSort(int index)
{
   if(index >= 2)
   {
      int temp = heap[1];
      heap[1] = heap[index];
      heap[index] = temp;
      percolateDown(1, --index);
      recursiveSort(index);
   }
}

/**********************************************************
* convertToHeap converts binary tree to heap
***********************************************************/
void Heap::convertToHeap()
{
   for (int r = (mySize / 2); r >= 1; r--)
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
 *        delete max item; delete the max item in heap
***********************************************************/
void Heap::deleteMaxItem()
{
   heap.at(1) = heap.at(mySize);
   mySize--;
}


/**********************************************************
* main driver function
***********************************************************/
int main(int argc, char* argv[])
{
   char* fileName = new char[80];
   if (argc > 1)
   {
      fileName = argv[1];
   }
   else
   {
      cout << "File name: ";
      cin >> fileName;
   }

   ifstream inFile;
   inFile.open(fileName);
   Heap heap;
   inFile >> heap;
   heap.sort();
   cout << heap;
   cout << endl;
   inFile >> heap;
   heap.recursiveSort(heap.mySize);
   cout << heap;
}
