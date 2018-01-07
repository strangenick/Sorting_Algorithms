//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.h"

class BubbleSort : public Sort {
	public:
		BubbleSort(); //constructor
		virtual ~BubbleSort(); //destructor
		virtual void sort(int[], int, int); //polymorphic behavior
		virtual void print(int[], int);
};

#endif //BUBBLESORT_H
