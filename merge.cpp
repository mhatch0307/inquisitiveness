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
#include <list>
#include <fstream>

using namespace std;

/********************************************************************
* Class Definition for Merge Sort
*********************************************************************/
class MergeSort
{
public:
   MergeSort(list <int> input);
   void sort();
   friend ostream & operator << (ostream &out, MergeSort & merge);
private:
   void merge();
   void split();
   int size;
   int numSub;
   list <int> mergedList;
   list <int> sub1;
   list <int> sub2;
};

/********************************************************************
* MergeSort default constructor
*********************************************************************/
MergeSort::MergeSort(list <int> input)
{
   size = input.size();
   mergedList = input;
   numSub = 1;
}

/********************************************************************
* merge() merge the l1 and l2 together
*********************************************************************/
void MergeSort::merge()
{
   list <int>::iterator  it1 = sub1.begin();
   list <int>::iterator  it2 = sub2.begin();
   mergedList = list <int> ();
   
   while (it1 != sub1.end() && it2 != sub2.end())
   {
      if (*it1 < *it2)
      {
         mergedList.push_back(*it1);
         it1++;
      }
      else
      {
         mergedList.push_back(*it2);
         it2++;
      }
   }

   if (it1 != sub1.end())
   {
      while(it1 != sub1.end())
      {
         mergedList.push_back(*it1);
         it1++;
      }
   }
   
   else if (it2 != sub2.end())
   {
      while (it2 != sub2.end())
      {
         mergedList.push_back(*it2);
         it2++;
      }
   }
}
/********************************************************************
* split() split the mergedList into l1 and l2 based
*********************************************************************/
void MergeSort::split()
{
   bool first = true;
   numSub = 0;
   int prev;
   sub1 = list <int> ();
   sub2 = list <int> ();
   list <int>::iterator  it = mergedList.begin();
   while(it != mergedList.end())
   {
      if (first)
         sub1.push_back(*it);
      else
         sub2.push_back(*it);
      
      prev = *it;
      it++;
      if ( it != mergedList.end() && prev > *it)
      {
         numSub++;
         first = !first;
      }
   }
}

/********************************************************************
* sort() merge sort the list
*********************************************************************/
void MergeSort::sort()
{
   while (numSub > 0)
   {
      split();
      merge();
   }
}

/*******************************************************************
* << operator overload for MergeSort
********************************************************************/
ostream & operator << (ostream &out, MergeSort & merge)
{
   for (list <int>::iterator it = merge.mergedList.begin(); 
       it != merge.mergedList.end(); ++it)
   {
      out << *it << " ";
   }
   
   return out;
}
/********************************************************************
* Dirver to test the merge sort
*********************************************************************/
int main(int argc, char* argv[])
{
   char* name = new char[80];
   if (argc > 1)
   {
      name = argv[1];
   }
   else
   {
      cout << "Filename: ";
      cin >> name;
   }
   ifstream input;
   input.open(name);
   int num;
   list <int> newList;
   while (input >> num)
   {
      newList.push_back(num);
   }
   MergeSort merge = MergeSort(newList);
   merge.sort();
   cout << merge << endl;
}

