#CFLAGS =-std=c++11 -stdlib=libc++
EXPORTED = -DEXPORTED
#DEBUG = -DDEBUG -g
FLAGS = -Wall
CFLAGS = -c -Wall -DDEBUG -DEXPORTED
DFLAGS = -Wall -g -DDEBUG
LFLAGS = -Wall
#CC = /usr/local/bin/g++-4.7
#CC = /usr/bin/g++
CC = clang++
INCLUDES = -I/usr/include -I/usr/local/include -I./

LIBS = 

SRCS = *.cpp

OBJS = $(SRCS:.cpp=.o)

objects = RandomData.o QuickSort.o InsertionSort.o LinkList.o \
          CircularLcnkList.o NormalData.o Josephus.o

default: StringSearch 

all: $(objects)
	$(CC) $(CFLAGS) $(objects) $(LIBS)

exec1: 
	g++ exec1.cpp

exec2:
	g++ exec2.cpp

NormalData.o:
	$(CC) $(CFLAGS) NormalData.cpp

RandomData.o: NormalData.o
	$(CC) $(CFLAGS) RandomData.cpp NormalData.o

RandomData: NormalData.o
	$(CC) $(FLAGS) RandomData.cpp NormalData.o

QuickSort.o: RandomData.o
	$(CC) $(CFLAGS) QuickSort.cpp RandomData.o

QuickSort: RandomData.o
	$(CC) $(FLAGS) QuickSort.cpp RandomData.o

exec3:
	g++ exec3.cpp

exec4:
	g++ exec4.cpp

exec5:
	g++ exec5.cpp

exec8:
	g++ exec8.cpp

HeapSort: RandomData.o NormalData.o
	$(CC) HeapSort.cpp RandomData.o NormalData.o

InsertionSort.o: RandomData.o
	$(CC) $(CFLAGS) InsertionSort.cpp RandomData.o

InsertionSort: RandomData.o
	$(CC) InsertionSort.cpp RandomData.o

Select: QuickSort.o InsertionSort.o 
	$(CC) $(FLAGS) Select.cpp QuickSort.o InsertionSort.o RandomData.o

MergeSort: RandomData.o
	$(CC) $(FLAGS) MergeSort.cpp RandomData.o

BinarySearchTree: QuickSort.o
	$(CC) BinarySearchTree.cpp RandomData.o QuickSort.o 

MiscSort: RandomData.o
	$(CC) MiscSort.cpp RandomData.o

StringSearch: RandomData.o NormalData.o
	$(CC) $(FLAGS) $(INCLUDES) StringSearch.cpp RandomData.o NormalData.o

LinkList.o: RandomData.o
	$(CC) $(CFLAGS) LinkList.cpp RandomData.o

LinkList: RandomData.o
	$(CC) $(FLAGS) LinkList.cpp RandomData.o

Bit: 
	$(CC) $(FLAGS) Bit.cpp

MinPathSum:
	$(CC) $(FLAGS) MinPathSum.cpp

Fibonacci: RandomData.o NormalData.o
	$(CC) $(FLAGS) Fibonacci.cpp RandomData.o NormalData.o

CircularLinkList.o: LinkList.o NormalData.o
	$(CC) $(CFLAGS) CircularLinkList.cpp LinkList.o NormalData.o

CircularLinkList: LinkList.o NormalData.o
	$(CC) $(FLAGS) CircularLinkList.cpp LinkList.o NormalData.o

Josephus.o: LinkList.o CircularLinkList.o NormalData.o
	$(CC) $(CFLAGS) LinkList.o CircularLinkList.o NormalData.o Josephus.cpp

Josephus: LinkList.o CircularLinkList.o NormalData.o
	$(CC) $(DFLAGS) Josephus.cpp LinkList.o CircularLinkList.o NormalData.o

ctags:
	ctags *

cscope:
	find . -name "*.cpp" -o -name "*.h" > cscope.files
	cscope -b -q -k
	
clean:
	rm a.out *.o

depend: $(SRCS)
	makedepend $(INCLUDES) $^

#end
# DO NOT DELETE

BinarySearchTree.o: BinarySearchTree.h QuickSort.h RandomData.h
CircularLinkList.o: CircularLinkList.h LinkList.h NormalData.h
HeapSort.o: RandomData.h
InsertionSort.o: InsertionSort.h RandomData.h
Josephus.o: CircularLinkList.h LinkList.h NormalData.h
LinkList.o: LinkList.h RandomData.h
MiscSort.o: RandomData.h
NormalData.o: NormalData.h
QuickSort.o: RandomData.h QuickSort.h
RandomData.o: RandomData.h
Select.o: InsertionSort.h RandomData.h QuickSort.h
StringSearch.o: RandomData.h
