#CFLAGS =-std=c++11 -stdlib=libc++
EXPORTED = -DEXPORTED
#DEBUG = -DDEBUG -g
#FLAGS =
CFLAGS = -c -Wall -DDEBUG -DEXPORTED
DFLAGS = -Wall -g -DDEBUG
LFLAGS = -Wall
#CC = /usr/local/bin/g++-4.7
#CC = /usr/bin/g++
CC = clang++
# using boost
INCLUDES = -I/usr/include -I/usr/local/include -I./ -I/usr/local/Cellar/boost/1.55.0_2/include/
LEETCODE = ./leetcode/

LIBS = 

SRCS = *.cpp

OBJS = $(SRCS:.cpp=.o)

objects = RandomData.o QuickSort.o InsertionSort.o LinkList.o \
          CircularLcnkList.o NormalData.o Josephus.o

default: MajorityElement 

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
	$(CC) $(DFLAGS) RandomData.cpp NormalData.o

QuickSort.o: RandomData.o
	$(CC) $(CFLAGS) QuickSort.cpp RandomData.o

QuickSort: RandomData.o
	$(CC) $(DFLAGS) QuickSort.cpp RandomData.o

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

BinarySearchTree: QuickSort.o RandomData.o  NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) BinarySearchTree.cpp RandomData.o QuickSort.o NormalData.o

MiscSort: RandomData.o
	$(CC) MiscSort.cpp RandomData.o

StringSearch: RandomData.o NormalData.o
	$(CC) $(FLAGS) $(INCLUDES) StringSearch.cpp RandomData.o NormalData.o

LinkList.o: RandomData.o NormalData.o
	$(CC) $(CFLAGS) LinkList.cpp RandomData.o NormalData.o

LinkList: NormalData.o RandomData.o
	$(CC) $(DFLAGS) LinkList.cpp NormalData.o RandomData.o

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

StringProcess:
	$(CC) $(DFLAGS) StringProcess.cpp

DataProcess: NormalData.o
	$(CC) $(DFLAGS) DataProcess.cpp NormalData.o

Tree:
	$(CC) $(DFLAGS) Tree.cpp

Interval:
	$(CC) $(DFLAGS) Interval.cpp

Graph: NormalData.o
	$(CC) $(DFLAGS) Graph.cpp NormalData.o

Power:
	$(CC) $(DFLAGS) Power.cpp

Shift: NormalData.o
	$(CC) $(DFLAG) Shift.cpp NormalData.o

IntegerToRoman:
	$(CC) $(DFLAG) $(LEETCODE)IntegerToRoman.cpp

RomanToInteger:
	$(CC) $(DFLAG) $(LEETCODE)RomanToInteger.cpp

MajorityElement:
	$(CC) $(DFLAG) $(LEETCODE)MajorityElement.cpp

ctags:
	ctags *

cscope:
	find . -name "*.cpp" -o -name "*.h" > cscope.files
	cscope -b -q -k
	
doc:
	doxygen Doxyfile

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
