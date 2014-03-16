ms_interview_100
================

This is the code implementation for 100 interview questions

To compile the target in the make file:
make target_name, for example: make Select

To compile a file who contains a main function to an object in order to export its other functions except the main:
make CFLAGS=-DEXPORTED target_name, for example: make QuickSort.o
