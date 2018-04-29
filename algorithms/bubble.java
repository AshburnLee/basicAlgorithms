import java.io.*;
import java.util.*;

class bubble
{
	public static void main(String argvs[])
	{
	
		// define an array:
		// int len = 100000;
		// double[] arr = new double[len];

		// long start = System.currentTimeMillis();
		// //random number:
		// generatedRandom(arr);
		// long end = System.currentTimeMillis();
		// System.out.println((end-start)/1000L);

		// // dop the operations:
		// System.out.println("BUBBLE: ");
		// long start2 = System.currentTimeMillis();
		// bubbleSort(arr, len);
		// long end2 = System.currentTimeMillis();
		// System.out.println((end2-start2)/1000L);
		// System.out.println("Soted array: ");
		// printArray(arr, len);
	}

// 	//pass array as parameter:
// 	static void bubbleSort(double[] arr, int n)
// 	{
// 		boolean swap;
// 		for(int i=0;i<n-1;i++){

// 			swap = false;

// 			for(int j=0;j<n-1;j++){

// 				if(arr[j] > arr[j+1]){

// 					double tmp = arr[j];
// 					arr[j] = arr[j+1];
// 					arr[j+1] = tmp;

// 					swap = true;
// 				}
// 			}
// 			if(swap==false)
// 				break;
// 		}
// 	}

// 	static void generatedRandom(double[] arr)
// 	{
// 		for(int i=0;i<arr.length;i++){
// 			Random rn = new Random();
// 			double min = 10;
// 			double max = 20;
// 			arr[i] = min + rn.nextDouble() * (max - min);
// 		}
// 	}
// 	//pass array as parameter:
// 	static void printArray(double[] arr, int n)
// 	{
// 		for(int i=0;i<n;i++){
// 			System.out.print(arr[i]+" ");
// 		}
// 		System.out.println();
// 	}

}