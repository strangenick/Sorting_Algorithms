//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"

class QuickSort : public Sort {
	public:
		QuickSort(); //constructor
		virtual ~QuickSort(); //destructor
		virtual void sort(int[], int, int); //polymorphic behavior
		int partition(int[], int, int);
		virtual void print(int[], int);

};

#endif //QUICKSORT_H
