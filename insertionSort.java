class InsertionSort
{
	public void swap(int indexOne, int indexTwo, int numbers[])
	{
		int temp = numbers[indexOne];
		numbers[indexOne] = numbers[indexTwo];
		numbers[indexTwo] = temp;
	}

	private void display(int numbers[])
	{
		for (int i = 0; i < numbers.length; i++)
			System.out.print(numbers[i] + " ");
		System.out.println();

	}

	public void insertionSort(int numbers[])
	{
		for(int i = 0; i < numbers.length; i++)
		{
			display(numbers);
			for(int j = i; j > 0 && numbers[j - 1] > numbers[j]; j--)
			{	
				swap(j, j-1, numbers);
			}
		}
		display(numbers);
	}

	public static void main(String[] args)
	{
		int numbers[] = {10, 7, 14, 3, 2, 13, 8, 5, 12, 4, 9, 6, 11, 1};
		InsertionSort insertionSort = new InsertionSort();
		insertionSort.insertionSort(numbers);
	}
}