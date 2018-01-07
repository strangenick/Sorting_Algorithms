//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 BlackBelt- Take in integer list from file and randomly select whether to use Insertion, Bubble, or Quick sort
//Created by: Nicholas Strange

#include <iostream> //std::cin, std::cout, std::string
#include <fstream>  //std::ifstream
#include <string>   //std::getline, c_str
#include <cstring>  //memcpy
#include <sstream>  //std::stringstream
#include <stdlib.h> //atoi, rand
#include <ctime>    //time()

#include "Sort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "QuickSort.h"

int main(){
	std::cout << "\nWeclome to the CSCI 240 Sorting Program!\n";

	std::string selection1 = "0"; //stores user input from first menu
	std::string selection2 = "0"; //stores user input from second menu
	
	std::string string_number; //stores file tokens
	std::stringstream ss; //used to convert the tokens to integers
	//ensure stringstream is clear:
	ss.clear();
	ss.str("");
	
	int fileArray[50]; //array used to store integer tokens from file; will remain untouched and unsorted
	int arrayToBeSorted[50]; //fileArray will be copied into this array, which is then passed to the sort methods. This is done in a loop, meaning arrayToBeSorted is continually sorted, printed, and then reset.

	std::ifstream inputFile("data.txt"); //open input file stream
	if(inputFile.is_open()) {
		for(int i = 0; std::getline(inputFile, string_number, ','); i++) { //getline parses file using comma as delimiter

			ss << string_number; //adds next string token to stringstream
			ss >> fileArray[i]; //outputs string token as integer into the fileArray
			//clear the stringstream for the next token:
			ss.clear();
			ss.str("");
		}
		
		inputFile.close();
	
	}else{
		std::cout << "Unable to open file" << std::endl;
		selection1 = "2";
	}
 	
	while (selection1 != "2"){ //while user hasn't selected to end program
		
		int arrayLength = sizeof(fileArray)/sizeof(int);
		
		memcpy(arrayToBeSorted, fileArray, sizeof(fileArray)); //copies fileArray to arrayToBeSorted			
		
		std::cout << "\n1. Load Data (From File)\n2. Exit Program\nPlease enter your selection: "; //first menu
		std::cin >> selection1;

		switch(atoi(selection1.c_str())) { //atoi takes selection1 as a C-string and converts it to an int. This allows the following switch statement to run.
			
			case 1:{
				//print unsorted array for the user (as the integers appear in the file):
				std::cout << "\nUnsorted Array: ";
				for(int k = 0; k < arrayLength-1; k++){
					std::cout << arrayToBeSorted[k] << ", ";
				}
				std::cout << arrayToBeSorted[arrayLength-1] << std::endl;	
				
				srand(time(NULL));
				int whichSort = rand() % 3 + 1;

				switch(whichSort) { 
					case 1:{
						Sort * insertionSort = new InsertionSort(); //allows for polymorphic behavior
						insertionSort->sort(arrayToBeSorted, arrayLength, 0); //sorts array using Insertion sort
						insertionSort->print(arrayToBeSorted, arrayLength);
						delete insertionSort;
					       
					       }break;
					
					case 2:{
						Sort * bubbleSort = new BubbleSort(); //allows for polymorphic behavior
						bubbleSort->sort(arrayToBeSorted, arrayLength, 0); //sorts array using Bubble sort, then prints it
						bubbleSort->print(arrayToBeSorted, arrayLength);
						delete bubbleSort;
					       
					       }break;
					
					case 3:{ 
						Sort * quickSort = new QuickSort();
						quickSort->sort(arrayToBeSorted, 0, arrayLength-1);
						quickSort->print(arrayToBeSorted, arrayLength);
					      	delete quickSort; 
						
					       }break;		
				}
				
			       }break;

			case 2:
				break;
			
			default:
				std::cout << "\nInvalid choice! Please select option 1 or 2.\n";
				break;
		}
	
	}
	
	std::cout << "\nGoodbye!\n\n";
	
	return 0;
}
