//Honor Pledge: I pledge that I have neither
//given nor received any undue help on this assignment.
//
//strangni
//
//CS 240 - Assignment 5 - A Healthy Dose of Inheritance - BlackBelt: Any Number of Employees
//Created by: Nicholas Strange

public class BubbleSort extends Sort {  //inheritance
	
	public BubbleSort(){  //default constructor
	}
	
	public void sort(int array[], int length) {
		for (int i = 0; i < length - 1; i++) { //loop through all elements of the array length-1 times to ensure a complete sort
			for (int j = 0; j < length-1-i ; j++) {  //The '-i' in the condition is used because the last i elements are already in the correct place.
				if(array[j] < array[j+1]) {   //compare each element to its right neighbor; if it's smaller, swap the two
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	//print sorted array for the user:
	System.out.print("\nBubble Sort: ");
	
		for (int k = 0; k < length-1; k++) {
			System.out.print(array[k] + ", "); 
		}
		System.out.println(array[length-1]);
	}
}
