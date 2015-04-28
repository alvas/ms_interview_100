default: CountPrimes

#CFLAGS =-std=c++11 -stdlib=libc++
EXPORTED = -DEXPORTED
#DEBUG = -DDEBUG -g
#FLAGS =
# -c: compile or assemble the source files, but do not link.
CFLAGS = -c -Wall -DDEBUG -DEXPORTED
DFLAGS = -Wall -g -DDEBUG
LFLAGS = -Wall
#CC = /usr/local/bin/g++-4.7
#CC = /usr/bin/g++
CC = clang++
# using boost
LEETCODE = ./leetcode/
INCLUDES = -I/usr/include -I/usr/local/include -I./ -I/usr/local/Cellar/boost/1.57.0/include

LIBS = 

SRCS = *.cpp

OBJS = $(SRCS:.cpp=.o)

objects = RandomData.o QuickSort.o InsertionSort.o LinkList.o \
          CircularLinkList.o NormalData.o Josephus.o

all: $(objects)
	$(CC) $(INCLUDES) $(CFLAGS) $(objects) $(LIBS)

exec1: 
	g++ exec1.cpp

exec2:
	g++ exec2.cpp

NormalData.o:
	$(CC) $(CFLAGS) NormalData.cpp

# whatever uses RandomData.o needs to use NormalData.o
RandomData.o: NormalData.o
	$(CC) $(CFLAGS) RandomData.cpp NormalData.o

RandomData: NormalData.o
	$(CC) $(DFLAGS) RandomData.cpp NormalData.o

QuickSort.o: RandomData.o
	$(CC) $(CFLAGS) QuickSort.cpp RandomData.o

QuickSort: RandomData.o
	$(CC) $(DFLAGS) QuickSort.cpp RandomData.o NormalData.o

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

Tree.o: NormalData.o
	$(CC) $(CFLAGS) Tree.cpp NormalData.o

Tree: NormalData.o
	$(CC) $(DFLAGS) Tree.cpp NormalData.o

Interval:
	$(CC) $(DFLAGS) Interval.cpp

Graph: NormalData.o
	$(CC) $(DFLAGS) Graph.cpp NormalData.o

Power:
	$(CC) $(DFLAGS) Power.cpp

Shift: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) Shift.cpp NormalData.o

IntegerToRoman:
	$(CC) $(DFLAGS) $(LEETCODE)IntegerToRoman.cpp

RomanToInteger:
	$(CC) $(DFLAGS) $(LEETCODE)RomanToInteger.cpp

MajorityElement:
	$(CC) $(DFLAGS) $(LEETCODE)MajorityElement.cpp

BinarySearch: RandomData.o
	$(CC) $(DFLAGS) BinarySearch.cpp RandomData.o NormalData.o

PathSum: Tree.o
	$(CC) $(DFLAGS) $(LEETCODE)PathSum.cpp Tree.o

LengthOfLastWord:
	$(CC) $(DFLAGS) $(LEETCODE)LengthOfLastWord.cpp

ValidParentheses:
	$(CC) $(DFLAGS) $(LEETCODE)ValidParentheses.cpp

RotateArray: RandomData.o
	$(CC) $(DFLAGS) $(LEETCODE)RotateArray.cpp RandomData.o NormalData.o

ExcelSheetColumnNumber:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnNumber.cpp

ExcelSheetColumnTitle:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnTitle.cpp

IntersectionOfTwoLinkedLists: LinkList.o
	$(CC) $(DFLAGS) $(LEETCODE)IntersectionOfTwoLinkedLists.cpp LinkList.o RandomData.o NormalData.o

NumberOf1Bits:
	$(CC) $(DFLAGS) $(LEETCODE)NumberOf1Bits.cpp

CompareVersionNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CompareVersionNumbers.cpp

CountAndSay:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountAndSay.cpp

PascalsTriangle: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle.cpp NormalData.o

FactorialTrailingZeroes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FactorialTrailingZeroes.cpp

MaximumDepthOfBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumDepthOfBinaryTree.cpp Tree.o

PalindromeNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeNumber.cpp 

ZigZagConversion:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ZigZagConversion.cpp 

ReverseInteger:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseInteger.cpp 

MinStack:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinStack.cpp 

StringToInteger:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StringToInteger.cpp 

LongestCommonPrefix:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestCommonPrefix.cpp 

ValidPalindrome:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidPalindrome.cpp 

RemoveNthNodeFromEndOfList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveNthNodeFromEndOfList.cpp LinkList.o RandomData.o NormalData.o

PascalsTriangle2: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle2.cpp NormalData.o

MergeTwoSortedLists: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeTwoSortedLists.cpp LinkList.o

MinimumDepthOfBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumDepthOfBinaryTree.cpp Tree.o

BalancedBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BalancedBinaryTree.cpp Tree.o

ReverseBits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseBits.cpp

BinaryTreeLevelOrderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversal.cpp Tree.o

BinaryTreeLevelOrderTraversalII: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversalII.cpp Tree.o

RemoveDuplicatesFromSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArray.cpp

ImplementStrStr:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStrStr.cpp

SameTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SameTree.cpp Tree.o

SymmetricTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SymmetricTree.cpp Tree.o

HouseRobber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobber.cpp 

MergeSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeSortedArray.cpp 

RemoveElement:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveElement.cpp 

RemoveDuplicatesFromSortedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedList.cpp LinkList.o

ClimbingStairs:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClimbingStairs.cpp 

AddBinary:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddBinary.cpp 

PlusOne:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PlusOne.cpp 

ValidSudoku:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidSudoku.cpp 

HappyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HappyNumber.cpp 

LinkedListCycle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycle.cpp 

AddTwoNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddTwoNumbers.cpp 

BinaryTreeRightSideView: Tree.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeRightSideView.cpp Tree.o NormalData.o

RemoveLinkedListElements: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveLinkedListElements.cpp LinkList.o

# This uses unordered_set initialier list which needs c++11 support
WordBreak:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreak.cpp

SingleNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumber.cpp

SingleNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberII.cpp
	
CountPrimes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountPrimes.cpp

ThreeSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSum.cpp

ctags:
	ctags *

cscope:
	find . -name "*.cpp" -o -name "*.h" > cscope.files
	cscope -b -q -k
	
doc:
	doxygen Doxyfile

#declare phony target
.PHONY: clean
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
SZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversionZigZagConversiontringSearch.o: RandomData.h
