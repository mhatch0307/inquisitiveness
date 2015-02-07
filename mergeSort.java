import java.util.ArrayList;
import java.util.List;
	
class MergeSort
{
	//private int size;
	private boolean sorted;
	private List <Integer> mergedList;
	private List <Integer> sub1;
	private List <Integer> sub2;

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
		numbers.add(10);
		numbers.add(7);
		numbers.add(14);
		numbers.add(3);
		numbers.add(2);
		numbers.add(13);
		numbers.add(8);
		numbers.add(5);
		numbers.add(12);
		numbers.add(4);
		numbers.add(9);
		numbers.add(6);
		numbers.add(11);
		numbers.add(1);
		MergeSort mergeSort = new MergeSort(numbers);
		mergeSort.sort();
		mergeSort.display();
	}

}