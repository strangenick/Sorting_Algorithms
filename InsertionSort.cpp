//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

#include "InsertionSort.h"
#include <iostream>

InsertionSort::InsertionSort() { //constructor
}

InsertionSort::~InsertionSort() { //destructor
}

//Insertion sort implementation (descending order):
void InsertionSort::sort(int array[], int length) {	
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
	//print sorted array for user:
	std::cout << "\nInsertion Sort: ";

	for (int k = 0; k < length-1; k++) {
		std::cout << array[k] << ", "; 
	}
	std::cout << array[length-1] << std::endl;
}
