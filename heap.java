import java.io.*;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

class Heap
{
	private List <Integer> heap;
	private int heapSize;

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
   
	public Heap(List <Integer> numbers)
	{
		heap = numbers;
		heapSize = numbers.size() - 1;
		convertToHeap();
	}

	private void display()
	{
		for (int i = 0; i <= heapSize; i++)
			System.out.print(heap.get(i) + " ");
		System.out.println();
	}
	
	private void sort()
	{
		int temp;
		for(int i = heapSize; i >= 1; i--)
		{
			temp = heap.get(0);
			heap.set(0, heap.get(i));
			heap.set(i, temp);
			percolateDown(0, i-1);
		}
	}

	private void convertToHeap()
	{
		for(int r = heapSize / 2; r >= 0; r--)
		{
			percolateDown(r, heapSize);
		}
	}

	private void percolateDown(int r, int n)
	{
		int c = 2 * r;
		int temp;
		while(c <= n)
		{
			if(c < n && heap.get(c) < heap.get(c + 1)) c++;

			if(c <= heapSize && heap.get(r) < heap.get(c))
			{
				temp = heap.get(r);
				heap.set(r, heap.get(c));
				heap.set(c, temp);
				r = c;
				c = c * 2;
			}
			else { break; }
		}
	}

	private void deletMaxItem()
	{
		heap.set(0, heap.get(heapSize));
		heapSize--;
	}

	public static void main(String[] args)
	{
		List <Integer> numbers = new ArrayList <Integer>();
      getFromFile(numbers);
		Heap heap = new Heap(numbers);
      double startTime = System.currentTimeMillis();
		heap.sort();
      double stopTime = System.currentTimeMillis();
      double elapsedTime = stopTime - startTime;
		heap.display();
      System.out.println(elapsedTime/1000.0);
	}
}