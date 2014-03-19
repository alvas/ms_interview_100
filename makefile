CFLAGS=-DEXPORTED

exec1: 
	g++ exec1.cpp

exec2:
	g++ exec2.cpp

RandomArray.o:
	g++ $(CFLAGS) -c RandomArray.cpp

QuickSort.o: RandomArray.o
	g++ $(CFLAGS) -c QuickSort.cpp

QuickSort: RandomArray.o
	g++ QuickSort.cpp RandomArray.o

exec3:
	g++ exec3.cpp

exec4:
	g++ exec4.cpp

exec5:
	g++ exec5.cpp

exec8:
	g++ exec8.cpp

HeapSort: RandomArray.o
	g++ HeapSort.cpp RandomArray.o

InsertionSort.o: RandomArray.o
	g++ $(CFLAGS) -c InsertionSort.cpp RandomArray.o

InsertionSort: RandomArray.o
	g++ InsertionSort.cpp RandomArray.o

Select: QuickSort.o InsertionSort.o 
	g++ $(CFLAGS) Select.cpp QuickSort.o InsertionSort.o RandomArray.o

BinarySearchTree: QuickSort.o
	g++ BinarySearchTree.cpp RandomArray.o QuickSort.o

MiscSort: RandomArray.o
	g++ MiscSort.cpp RandomArray.o

clean:
	rm a.out *.o
