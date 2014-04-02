#CFLAGS=-std=c++11 -stdlib=libc++
CFLAGS=-std=c++11 
#EXPORT=-DEXPORTED
#DEBUG =-DDEBUG
CC=/usr/local/bin/g++-4.7

exec1: 
	g++ exec1.cpp

exec2:
	g++ exec2.cpp

RandomData.o:
	$(CC) $(CFLAGS) $(EXPORTED) -c RandomData.cpp

RandomData:
	$(CC) $(CFLAGS) RandomData.cpp

QuickSort.o: RandomData.o
	g++ $(CFLAGS) -c QuickSort.cpp

QuickSort: RandomData.o
	g++ QuickSort.cpp RandomData.o

exec3:
	g++ exec3.cpp

exec4:
	g++ exec4.cpp

exec5:
	g++ exec5.cpp

exec8:
	g++ exec8.cpp

HeapSort: RandomData.o
	g++ HeapSort.cpp RandomData.o

InsertionSort.o: RandomData.o
	g++ $(CFLAGS) -c InsertionSort.cpp RandomData.o

InsertionSort: RandomData.o
	g++ InsertionSort.cpp RandomData.o

Select: QuickSort.o InsertionSort.o 
	g++ $(CFLAGS) Select.cpp QuickSort.o InsertionSort.o RandomData.o

BinarySearchTree: QuickSort.o
	g++ BinarySearchTree.cpp RandomData.o QuickSort.o

MiscSort: RandomData.o
	g++ MiscSort.cpp RandomData.o

StringSearch: RandomData.o
	g++ $(DEBUG) StringSearch.cpp RandomData.o

ctags:
	ctags *

cscope:
	find . -name "*.cpp" -o -name "*.h" > cscope.files
	cscope -b -q -k
	
clean:
	rm a.out *.o tags
