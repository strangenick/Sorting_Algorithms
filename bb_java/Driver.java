//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

import java.io.*;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Driver{
public static void main(String[] args){
	System.out.println("\nWeclome to the CSCI 240 Sorting Program!");

	int selection1 = 0; //stores user input from first menu
	int selection2 = 0; //stores user input from second menu
	int fileArray[] = new int[50];
	int arrayToBeSorted[] = new int[50];
	Scanner input = new Scanner(System.in);  //used for getting user input
	
	try{
		//strategy for reading text file data:
		InputStream inputStream = new FileInputStream("data.txt");
		InputStreamReader reader = new InputStreamReader(inputStream);
		BufferedReader buffer = new BufferedReader(reader);
		String line = buffer.readLine();
				
		String[] parsed = line.split(",");
		for(int i=0; i < 50; i++) {
			try{
				fileArray[i] = Integer.parseInt(parsed[i]);  
			}catch(NumberFormatException nf){
				System.err.println(nf);
			}
		}
		buffer.close();
	}catch(FileNotFoundException fnfe){
		System.out.println("The employee file cannot be found. Make sure it exists and is in the right folder, and rerun the program.");
	}catch(IOException e){
		System.err.println(e);
	}		
		
 	
	while (selection1 != 2){ //while user hasn't selected to end program
		
		int arrayLength = 50;
		
		System.arraycopy(fileArray, 0, arrayToBeSorted, 0, 50); //copies fileArray to arrayToBeSorted			
		
		System.out.print("\n1. Load Data (From File)\n2. Exit Program\nPlease enter your selection: "); //first menu
		try{
			selection1 = input.nextInt();
		}catch(InputMismatchException ime){ 
			input.next(); //consumes erroneous entry
		}

		switch(selection1) { 
			
			case 1:
				//print unsorted array for the user (as the integers appear in the file):
				System.out.print("\nUnsorted Array: ");
				for(int k = 0; k < arrayLength-1; k++){
					System.out.print(arrayToBeSorted[k] + ", ");
				}
				System.out.println(arrayToBeSorted[arrayLength-1]);

				System.out.print("\n1. Insertion Sort\n2. Bubble Sort\n3. Exit Program\nPlease enter your selection: "); //second menu
				try{
					selection2 = input.nextInt();
				}catch(InputMismatchException ime){ 
					input.next(); //consumes erroneous entry
				}
				//force user to enter valid selection: 
				while (selection2 != 1 && selection2 != 2 && selection2 != 3) {
					System.out.println("\nInvalid choice! Please select option 1, 2, or 3.");
					System.out.print("\n1. Insertion Sort\n2. Bubble Sort\n3. Exit Program\nPlease enter your selection: ");
					try{
						selection2 = input.nextInt();
					}catch(InputMismatchException ime){ 
						input.next(); //consumes erroneous entry
					}
				}	
				
				switch(selection2) {

					case 1:{
						Sort insertionSort = new InsertionSort(); //allows for polymorphic behavior
						insertionSort.sort(arrayToBeSorted, arrayLength); //sorts array using Insertion sort, then prints it
						
						}break;
					
					case 2:{
						Sort bubbleSort = new BubbleSort(); //allows for polymorphic behavior
						bubbleSort.sort(arrayToBeSorted, arrayLength); //sorts array using Bubble sort, then prints it
				
					    }break;
					
					case 3: //user has selected to end the program; set selection1 to "2" to end the while loop
						selection1 = 2;
						break;		
				}
				
				break;

			case 2:
				break;
			
			default:
				System.out.println("\nInvalid choice! Please select option 1 or 2.");
				break;
		}
	
	}
	
	System.out.println("\nGoodbye!\n");
	
}
}