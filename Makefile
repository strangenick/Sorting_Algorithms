#Honor Pledge: I pledge that I have neither given nor
#received any undue help on this assignment.
#
#strangni
#
#CS240 - Assignment 6 - Take in integer list from file and sort using Insertion or Bubble sort
#Created by: Nicholas Strange

CompiledFile: Driver.o InsertionSort.o BubbleSort.o
	g++ Driver.o InsertionSort.o BubbleSort.o -o CompiledFile
	
Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o
	
InsertionSort.o: InsertionSort.cpp InsertionSort.h
	g++ -c InsertionSort.cpp -o InsertionSort.o
	
BubbleSort.o: BubbleSort.cpp BubbleSort.h
	g++ -c BubbleSort.cpp -o BubbleSort.o
	
clean:
	rm -f Driver.o InsertionSort.o BubbleSort.o CompiledFile
	
run: CompiledFile
	./CompiledFile
