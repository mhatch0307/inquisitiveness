import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
	
class MergeSort
{
	//private int size;
	private boolean sorted;
	private List <Integer> mergedList;
	private List <Integer> sub1;
	private List <Integer> sub2;

   public static void getFromFile(List<Integer> numberList)
   {
      try{
         Scanner fileScanner = new Scanner(new File("numberLists/10,000.txt"));
         for (int i = 0; fileScanner.hasNextInt(); i++)
         {
            numberList.add(fileScanner.nextInt());
         }
      }
      catch (IOException e)
      {
         System.out.println("Wrong file name");
      }
   }
   
	public MergeSort(List <Integer> numbers)
	{
		//size = numbers.size();
		mergedList = numbers;
		sorted = false;
	}

	private void merge()
	{
		int sub1Size = sub1.size();
		int sub2Size = sub2.size();
		int sub1I = 0;
		int sub2I = 0;
		mergedList = new ArrayList <Integer> ();
		while(sub1I < sub1Size && sub2I < sub2Size)
		{
			int sub1Val = sub1.get(sub1I);
			int sub2Val = sub2.get(sub2I);
			if(sub1Val < sub2Val)
			{
				mergedList.add(sub1Val);
				sub1I++;
			}
			else
			{
				mergedList.add(sub2Val);
				sub2I++;
			}
		}
		if(sub1I < sub1Size)
		{
			while(sub1I < sub1Size)
			{
				mergedList.add(sub1.get(sub1I));
				sub1I++;
			}
		}
		else
		{
			while(sub2I < sub2Size)
			{
				mergedList.add(sub2.get(sub2I));
				sub2I++;
			}
		}
	}

	void split()
	{
		boolean first = true;
		sorted = true;
		sub1 = new ArrayList <Integer> ();
		sub2 = new ArrayList <Integer> ();
		int size = mergedList.size();
		int index = 0;
		int prev;
		while(index < size)
		{
			int val = mergedList.get(index);
			if(first)
				sub1.add(val);
			else
				sub2.add(val);
			prev = val;
			index++;
			if(index < size && prev > mergedList.get(index))
			{
				sorted = false;
				first = !first;
			}
		}
	}
	
	void sort()
	{
		while(!sorted)
		{
			split();
			merge();
		}
	}

	void display()
	{
		int size = mergedList.size();
		for(int i = 0; i < size; i++)
		{
			System.out.print(mergedList.get(i) + " ");
		}
		System.out.println();
	}
	
	public static void main(String args[])
	{
		List <Integer> numbers = new ArrayList <Integer>();
      getFromFile(numbers);
		MergeSort mergeSort = new MergeSort(numbers);
      double startTime = System.currentTimeMillis();
		mergeSort.sort();
      double stopTime = System.currentTimeMillis();
      double elapsedTime = stopTime - startTime;
		mergeSort.display();
      System.out.println(elapsedTime/1000.0);
	}

}