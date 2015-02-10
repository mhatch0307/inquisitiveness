import java.io.*;
import java.util.Scanner;
class insertionSort
{
   
   public static void getFromFile(int[] numbers)
   {
      try{
         Scanner fileScanner = new Scanner(new File("numberLists/50,000.txt"));
         for (int i = 0; fileScanner.hasNextInt(); i++)
         {
            numbers[i] = fileScanner.nextInt();
         }
      }
      catch (IOException e)
      {
         System.out.println("Wrong file name");
      }
   }
   
	public static void swap(int indexOne, int indexTwo, int numbers[])
	{
		int temp = numbers[indexOne];
		numbers[indexOne] = numbers[indexTwo];
		numbers[indexTwo] = temp;
	}

	private static void display(int numbers[])
	{
		for (int i = 0; i < numbers.length; i++)
			System.out.print(numbers[i] + " ");
		System.out.println();

	}

	public static void insertionSort(int numbers[])
	{
		for(int i = 0; i < numbers.length; i++)
		{
//			display(numbers);
			for(int j = i; j > 0 && numbers[j - 1] > numbers[j]; j--)
			{	
				swap(j, j-1, numbers);
			}
		}
	}

	public static void main(String[] args)
	{
		int[] numbers = new int[50000];
      getFromFile(numbers);
      double startTime = System.currentTimeMillis();
      insertionSort(numbers);
      double stopTime = System.currentTimeMillis();
      double elapsedTime = stopTime - startTime;
      display(numbers);
      System.out.println(elapsedTime/1000.0);
	}
}