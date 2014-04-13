#CFLAGS=-std=c++11 -stdlib=libc++
EXPORTED=-DEXPORTED
#DEBUG=-DDEBUG
CFLAGS=-DDEBUG -Wall
CC=/usr/local/bin/g++-4.7
#CC=/usr/bin/g++

objects = RandomData.o QuickSort.o InsertionSort.o LinkList.o \
          CircularLinkList.o NormalData.o Josephus.o

a.out: $(objects)
	$(CC) $(CFLAGS) $(EXPORTED) $(objects)

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
	$(CC) $(CFLAGS) QuickSort.cpp RandomData.o

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
	$(CC) $(CFLAGS) StringSearch.cpp RandomData.o

LinkList.o: RandomData.o
	$(CC) $(CFLAGS) $(EXPORTED) -c LinkList.cpp RandomData.o

LinkList: RandomData.o
	$(CC) $(CFLAGS) LinkList.cpp RandomData.o

Bit: 
	$(CC) $(CFLAGS) Bit.cpp

MinPathSum:
	$(CC) $(CFLAGS) MinPathSum.cpp

Fibonacci:
	$(CC) $(CFLAGS) Fibonacci.cpp

NormalData.o:
	$(CC) $(CFLAGS) $(EXPORTED) -c NormalData.cpp

CircularLinkList.o: LinkList.o NormalData.o
	$(CC) $(CFLAGS) $(EXPORTED) -c CircularLinkList.cpp LinkList.o NormalData.o

CircularLinkList: LinkList.o NormalData.o
	$(CC) $(CFLAGS) CircularLinkList.cpp LinkList.o NormalData.o

Josephus.o: LinkList.o CircularLinkList.o NormalData.o
	$(CC) $(CFLAGS) -c LinkList.o CircularLinkList.o NormalData.o Josephus.cpp

Josephus: LinkList.o CircularLinkList.o NormalData.o 
	$(CC) $(CFLAGS) LinkList.o CircularLinkList.o NormalData.o Josephus.cpp 

ctags:
	ctags *

cscope:
	find . -name "*.cpp" -o -name "*.h" > cscope.files
	cscope -b -q -k
	
clean:
	rm a.out *.o
