//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sort.h"

class InsertionSort : public Sort {
	public:
		InsertionSort(); //constructor
		virtual ~InsertionSort(); //destructor
		virtual void sort(int[], int, int); //polymorphic behavior
		virtual void print(int[], int);
};

#endif //INSERTIONSORT_H
