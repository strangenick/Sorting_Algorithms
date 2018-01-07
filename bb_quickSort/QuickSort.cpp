//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

#include "QuickSort.h"
#include <iostream>

QuickSort::QuickSort() { //constructor
}

QuickSort::~QuickSort() { //destructor
}

//Quick sort implementation (descending order):
void QuickSort::sort(int array[], int left, int right) {	
	if (left < right) {
		int part = partition(array, left, right);
		sort(array, left, part-1);  //use recursion to ensure array is sorted fully
		sort(array, part+1, right);
	}
}

int QuickSort::partition(int array[], int left, int right) {
	int pivot = array[right];
	//if left < pivot < right, swap left and right: 
	while (left < right) {
		while (array[left] > pivot) {
			left++;
		}
		while (array[right] < pivot) {
			right--;
		}

		if (array[left] == array[right]) { 
			left++;
		}else if (left < right) {
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}

	return right;
}

void QuickSort::print(int array[], int arrayLength) {
	//print sorted array for user:
	std::cout << "\nQuick Sort: ";

	for (int k = 0; k < arrayLength-1; k++) {
		std::cout << array[k] << ", "; 
	}
	std::cout << array[arrayLength-1] << std::endl;
}

