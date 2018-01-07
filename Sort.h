//Honor Pledge: I pledge that I have neither given nor
//received any undue help on this assignment.
//
//strangni
//
//CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
//Created by: Nicholas Strange

#ifndef SORT_H
#define SORT_H

class Sort {
	public:
		Sort(){}; //constructor
		virtual ~Sort(){}; //destructor
		virtual void sort(int[], int) = 0; //pure virtual method - polymorphic behavior
};

#endif //SORT_H
