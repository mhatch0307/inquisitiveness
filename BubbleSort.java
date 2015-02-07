import java.io.*;
import java.util.Random;
import java.util.Scanner;
public class BubbleSort
{   
   public static void getFromFile(int[] numberList)
   {
      try{
         Scanner fileScanner = new Scanner(new File("numberLists/10,000.txt"));
         for (int i = 0; fileScanner.hasNextInt(); i++)
         {
            numberList[i] = fileScanner.nextInt();
         }
      }
      catch (IOException e)
      {
         System.out.println("Wrong file name");
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
      int[] numberList = new int[10000]; 
      getFromFile(numberList);
      bubbleSort(numberList);
      output(numberList);
   }
}
