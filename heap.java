import java.util.ArrayList;

class Heap
{
	private ArrayList <Integer> heap;
	private int heapSize;

	public Heap(ArrayList <Integer> numbers)
	{
		heap = numbers;
		heapSize = numbers.size();
		heap.add(0, 0);
		display();
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
		for(int i = heapSize; i >= 2; i--)
		{
			temp = heap.get(1);
			heap.set(1, heap.get(i));
			heap.set(i, temp);
			percolateDown(1, i-1);
		}
	}

	private void convertToHeap()
	{
		for(int r = (int) (heapSize / 2); r >= 1; r--)
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
		heap.set(1, heap.get(heapSize));
		heapSize--;
	}

	public static void main(String[] args)
	{
		ArrayList <Integer> numbers = new ArrayList <Integer>();
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
		Heap heap = new Heap(numbers);
		heap.display();
		heap.sort();
		heap.display();
	}
}