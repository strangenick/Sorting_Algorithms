//Honor Pledge: I pledge that I have neither
//given nor received any undue help on this assignment.
//
//strangni
//
//CS 240 - Assignment 5 - A Healthy Dose of Inheritance - BlackBelt: Any Number of Employees
//Created by: Nicholas Strange

public class InsertionSort extends Sort {  //inheritance
	
	public InsertionSort(){  //default constructor
	}
	
	public void sort(int array[], int length) {
		if (length != 1) { 
			int j;
			for (int i = 1; i < length; i++) {
				int key = array[i];
				for (j = i; j > 0 && key > array[j-1]; j--) { //compare each element (key) to the sorted subarray to its left
					array[j] = array[j-1];  //if the key element is greater than an element to its left, the smaller element is moved one space to the right
				}
				array[j] = key; //key element is placed in its proper location
			}
		}
	//print sorted array for the user:
		System.out.print("\nInsertion Sort: ");
	
		for (int k = 0; k < length-1; k++) {
			System.out.print(array[k] + ", "); 
		}
		System.out.println(array[length-1]);
	}
}
