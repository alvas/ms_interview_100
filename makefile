#CFLAGS=-std=c++11 -stdlib=libc++
FLAGS=-std=c++11 
EXPORTED=-DEXPORTED
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
	$(CC) $(CFLAGS) $(EXPORTED) -c QuickSort.cpp RandomData.o

QuickSort: RandomData.o
	$(CC) QuickSort.cpp RandomData.o

exec3:
	g++ exec3.cpp

exec4:
	g++ exec4.cpp

exec5:
	g++ exec5.cpp

exec8:
	g++ exec8.cpp

HeapSort: RandomData.o
	$(CC) HeapSort.cpp RandomData.o

InsertionSort.o: RandomData.o
	$(CC) $(CFLAGS) $(EXPORTED) -c InsertionSort.cpp RandomData.o

InsertionSort: RandomData.o
	$(CC) InsertionSort.cpp RandomData.o

Select: QuickSort.o InsertionSort.o 
	$(CC) $(CFLAGS) Select.cpp QuickSort.o InsertionSort.o RandomData.o

BinarySearchTree: QuickSort.o
	$(CC) BinarySearchTree.cpp RandomData.o QuickSort.o 

MiscSort: RandomData.o
	$(CC) MiscSort.cpp RandomData.o

StringSearch: RandomData.o
	$(CC) $(DEBUG) StringSearch.cpp RandomData.o

LinkList.o: RandomData.o
	$(CC) $(CFLANGS) LinkList.cpp RandomData.o

LinkList: RandomData.o
	$(CC) LinkList.cpp RandomData.o

Bit: 
	$(CC) Bit.cpp

MinPathSum:
	$(CC) MinPathSum.cpp

ctags:
	ctags *

cscope:
	find . -name "*.cpp" -o -name "*.h" > cscope.files
	cscope -b -q -k
	
clean:
	rm a.out *.o tags
