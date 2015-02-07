import java.io.*;
import java.util.Random;

public class BubbleSort
{   
   public static void getRandomNumbers(int[] numberList)
   {
      Random rand = new Random();
      for (int i = 0; i < numberList.length; i++)
      {
         numberList[i] = rand.nextInt(1000);
      }      
   }
   
   public static void output(int[] numberList)
   {
      for (int i = 0; i < numberList.length; i++)
      {
         System.out.print(numberList[i] + " ");
      }
      System.out.println("");
   }
   
   public static void bubbleSort(int[] numberList)
   {
      int temp;
      boolean sorted = false;
      while (!sorted)
      {
         sorted = true;
         for (int i = 0; i < numberList.length - 1; i++)
         {
            if (numberList[i] > numberList[i+1])
            {
               temp = numberList[i];
               numberList[i] = numberList[i+1];
               numberList[i+1] = temp;
               sorted = false;
            }
         }
      }
   }
   
   public static void main(String[] args)
   {
      int[] numberList = new int[20]; 
      getRandomNumbers(numberList);
      bubbleSort(numberList);
      output(numberList);
   }
}
