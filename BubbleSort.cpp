//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

#include "BubbleSort.h"
#include <iostream>

BubbleSort::BubbleSort() { //constructor
}

BubbleSort::~BubbleSort() { //destructor
}	

//Bubble sort implementation (descending order):
void BubbleSort::sort(int array[], int length) {
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
	std::cout << "\nBubble Sort: ";
	
	for (int k = 0; k < length-1; k++) {
		std::cout << array[k] << ", "; 
	}
	std::cout << array[length-1] << std::endl;
}
