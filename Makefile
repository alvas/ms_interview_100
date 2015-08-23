default: MaximumProductSubarray

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
# using this, so the header file could be found in the ms_interview_100 folder.
INCLUDES = -I/usr/include -I/usr/local/include -I./ -I/usr/local/Cellar/boost/1.57.0/include
OPTS=-ggdb -pg -fprofile-arcs -ftest-coverage

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

exec3:
	g++ exec3.cpp

exec4:
	g++ exec4.cpp

exec5:
	g++ exec5.cpp

exec8:
	g++ exec8.cpp

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

PowerOfTwo:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowerOfTwo.cpp

Shift: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) Shift.cpp NormalData.o

IntegerToRoman:
	$(CC) $(DFLAGS) $(LEETCODE)IntegerToRoman.cpp

RomanToInteger:
	$(CC) $(DFLAGS) $(LEETCODE)RomanToInteger.cpp

MajorityElement:
	$(CC) $(DFLAGS) $(LEETCODE)MajorityElement.cpp

MajorityElementII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MajorityElementII.cpp RandomData.o NormalData.o

BinarySearch: RandomData.o
	$(CC) $(DFLAGS) BinarySearch.cpp RandomData.o NormalData.o

PathSum: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSum.cpp Tree.o

PathSumII: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSumII.cpp Tree.o

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

BinaryTreeZigzagLevelOrderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeZigzagLevelOrderTraversal.cpp Tree.o

RemoveDuplicatesFromSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArray.cpp

RemoveDuplicatesFromSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArrayII.cpp

ImplementStrStr:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStrStr.cpp

SameTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SameTree.cpp Tree.o

SymmetricTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SymmetricTree.cpp Tree.o

HouseRobber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobber.cpp 

HouseRobberII: RandomData.o NormalData.o
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobberII.cpp RandomData.o NormalData.o

MergeSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeSortedArray.cpp 

RemoveElement:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveElement.cpp 

RemoveDuplicatesFromSortedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedList.cpp LinkList.o

RemoveDuplicatesFromSortedListII: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedListII.cpp LinkList.o

ClimbingStairs:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClimbingStairs.cpp 

AddBinary:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddBinary.cpp 

PlusOne:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PlusOne.cpp 

ValidSudoku:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidSudoku.cpp 

SudokuSolver:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SudokuSolver.cpp 

HappyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HappyNumber.cpp 

ReverseLinkedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedList.cpp LinkList.o

ReverseLinkedListII: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedListII.cpp LinkList.o

ReverseNodesInKGroup: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseNodesInKGroup.cpp LinkList.o

LinkedListCycle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycle.cpp 

LinkedListCycleII: LinkList.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycleII.cpp LinkList.o NormalData.o

AddTwoNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddTwoNumbers.cpp 

BinaryTreeRightSideView: Tree.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeRightSideView.cpp Tree.o NormalData.o

RemoveLinkedListElements: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveLinkedListElements.cpp LinkList.o

# This uses unordered_set initialier list which needs c++11 support
WordBreak:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreak.cpp

WordBreakII:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreakII.cpp

SingleNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumber.cpp

SingleNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberII.cpp
	
SingleNumberIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberIII.cpp

CountPrimes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountPrimes.cpp

TwoSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TwoSum.cpp

ThreeSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSum.cpp

FourSum: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FourSum.cpp NormalData.o

IsomorphicStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IsomorphicStrings.cpp

GasStation: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GasStation.cpp RandomData.o NormalData.o

CloneGraph:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CloneGraph.cpp

CopyListWithRandomPointer: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CopyListWithRandomPointer.cpp LinkList.o

ThreeSumClosest:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSumClosest.cpp

PalindromePartitioning:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioning.cpp

UniqueBinarySearchTrees:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTrees.cpp

UniqueBinarySearchTreesII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTreesII.cpp

SurroundedRegions:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SurroundedRegions.cpp

SumRootToLeafNumbers: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SumRootToLeafNumbers.cpp Tree.o

BestTimeToBuyAndSellStock:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStock.cpp

BestTimeToBuyAndSellStockII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockII.cpp

BestTimeToBuyAndSellStockIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIII.cpp

BestTimeToBuyAndSellStockIV:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIV.cpp

BinaryTreePreorderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePreorderTraversal.cpp Tree.o

BinaryTreeInorderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeInorderTraversal.cpp Tree.o

BinaryTreePostorderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePostorderTraversal.cpp Tree.o

SearchInsertPosition:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInsertPosition.cpp

SwapNodesInPairs: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SwapNodesInPairs.cpp LinkList.o

ReorderList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReorderList.cpp LinkList.o

ConvertSortedArrayToBinarySearchTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedArrayToBinarySearchTree.cpp Tree.o

ConvertSortedListToBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedListToBinarySearchTree.cpp

GenerateParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GenerateParentheses.cpp

MaximumSubarray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumSubarray.cpp

MinimumSizeSubarraySum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumSizeSubarraySum.cpp

ValidateBinarySearchTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidateBinarySearchTree.cpp Tree.o

NumberOfIslands:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfIslands.cpp

PopulatingNextRightPointersInEachNode: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNode.cpp Tree.o

PopulatingNextRightPointersInEachNodeII: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNodeII.cpp Tree.o

FindMinimumInRotatedSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArray.cpp

FindMinimumInRotatedSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArrayII.cpp

SearchInRotatedSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArray.cpp

SearchInRotatedSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArrayII.cpp

FlattenBinaryTreeToLinkedList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FlattenBinaryTreeToLinkedList.cpp

BinarySearchTreeIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinarySearchTreeIterator.cpp

SortList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortList.cpp

SortColors:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortColors.cpp

InsertionSortList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertionSortList.cpp

ContainsDuplicate:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicate.cpp

ContainsDuplicateII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateII.cpp

ContainsDuplicateIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateIII.cpp

Combinations:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Combinations.cpp

Permutations: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Permutations.cpp NormalData.o

PermutationsII: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationsII.cpp NormalData.o

NextPermutation: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NextPermutation.cpp NormalData.o

PermutationSequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationSequence.cpp

KthLargestElementInAnArray: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthLargestElementInAnArray.cpp RandomData.o NormalData.o

UniquePaths:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePaths.cpp

UniquePathsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePathsII.cpp

FindPeakElement: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindPeakElement.cpp RandomData.o NormalData.o

GrayCode:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GrayCode.cpp

NQueens:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueens.cpp

NQueensII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueensII.cpp

ConstructBinaryTreeFromPreorderAndInorderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp

ConstructBinaryTreeFromInorderAndPostorderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp

RotateImage: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateImage.cpp RandomData.o NormalData.o

SpiralMatrix: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrix.cpp NormalData.o

SpiralMatrixII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrixII.cpp

SetMatrixZeroes: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SetMatrixZeroes.cpp RandomData.o NormalData.o

SearchA2DMatrix: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrix.cpp RandomData.o NormalData.o

SearchA2DMatrixII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrixII.cpp RandomData.o NormalData.o

ContainerWithMostWater: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainerWithMostWater.cpp RandomData.o NormalData.o

TrappingRainWater: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TrappingRainWater.cpp RandomData.o NormalData.o

LongestConsecutiveSequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestConsecutiveSequence.cpp

Subsets: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Subsets.cpp NormalData.o

SubsetsII: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubsetsII.cpp NormalData.o RandomData.o

CombinationSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSum.cpp

CombinationSumII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumII.cpp

CombinationSumIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumIII.cpp

PartitionList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PartitionList.cpp

Triangle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Triangle.cpp

SearchForARange:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchForARange.cpp

RectangleArea:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RectangleArea.cpp

BitwiseAndOfNumbersRange:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BitwiseAndOfNumbersRange.cpp

JumpGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGame.cpp

JumpGameII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGameII.cpp

MergeIntervals:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeIntervals.cpp

InsertInterval:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertInterval.cpp

ImplementStackUsingQueues:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStackUsingQueues.cpp

ImplementQueueUsingStacks:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementQueueUsingStacks.cpp

SqrtX:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SqrtX.cpp

PowXN:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowXN.cpp

EditDistance:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EditDistance.cpp

RotateList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateList.cpp LinkList.o

InvertBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InvertBinaryTree.cpp Tree.o

BinaryTreeMaximumPathSum: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeMaximumPathSum.cpp Tree.o

LargestNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestNumber.cpp

LargestRectangleInHistogram: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestRectangleInHistogram.cpp NormalData.o

MaximalRectangle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalRectangle.cpp

MaximalSquare:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalSquare.cpp

InterLeavingString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InterLeavingString.cpp

# this solution uses string pop_back which is in c++ 11
SimplifyPath:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)SimplifyPath.cpp

FirstMissingPositive:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstMissingPositive.cpp

MergeKSortedLists: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeKSortedLists.cpp RandomData.o NormalData.o

LetterCombinationsOfAPhoneNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LetterCombinationsOfAPhoneNumber.cpp

CountCompleteTreeNodes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountCompleteTreeNodes.cpp

ImplementTrie:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementTrie.cpp

MedianOfTwoSortedArrays: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MedianOfTwoSortedArrays.cpp NormalData.o RandomData.o

Candy: RandomData.o NormalData.o
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)Candy.cpp RandomData.o NormalData.o

Anagrams:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Anagrams.cpp

ValidAnagram:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidAnagram.cpp

RecoverBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RecoverBinarySearchTree.cpp

MaximumGap: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumGap.cpp RandomData.o NormalData.o

DistinctSubsequences:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DistinctSubsequences.cpp

ScrambleString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ScrambleString.cpp

SummaryRanges:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SummaryRanges.cpp

CourseSchedule:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseSchedule.cpp

CourseScheduleII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseScheduleII.cpp

EvaluateReversePolishNotation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EvaluateReversePolishNotation.cpp

MultiplyStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MultiplyStrings.cpp

RestoreIPAddresses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RestoreIPAddresses.cpp

LongestValidParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestValidParentheses.cpp

AddAndSearchWord:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)AddAndSearchWord.cpp

LongestPalindromicSubstring:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestPalindromicSubstring.cpp

RegularExpressionMatching:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RegularExpressionMatching.cpp

LongestSubstringWithoutRepeatingCharacters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithoutRepeatingCharacters.cpp

WordSearch:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearch.cpp

WordSearchII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearchII.cpp

PalindromePartitioningII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioningII.cpp

RepeatedDNASequences:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RepeatedDNASequences.cpp

MaximumProductSubarray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumProductSubarray.cpp

SubstringWithConcatenationOfAllWords:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubstringWithConcatenationOfAllWords.cpp

WordLadder:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadder.cpp

WordLadderII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadderII.cpp

MinimumWindowSubstring:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumWindowSubstring.cpp

BasicCalculator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculator.cpp

BasicCalculatorII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculatorII.cpp

DungeonGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DungeonGame.cpp

ShortestPalindrome:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestPalindrome.cpp

TheSkylineProblem:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TheSkylineProblem.cpp

DecodeWays:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DecodeWays.cpp

WildcardMatching:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WildcardMatching.cpp

LRUCache:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)LRUCache.cpp

DivideTwoIntegers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DivideTwoIntegers.cpp

TextJustification:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TextJustification.cpp

FractionToRecurringDecimal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FractionToRecurringDecimal.cpp

MaxPointsOnALine:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaxPointsOnALine.cpp

ValidNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidNumber.cpp

KthSmallestElementInABST: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthSmallestElementInABST.cpp Tree.o

PalindromeLinkedList: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeLinkedList.cpp RandomData.o NormalData.o

LowestCommonAncestorOfABinarySearchTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinarySearchTree.cpp Tree.o

LowestCommonAncestorOfABinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinaryTree.cpp Tree.o

DeleteNodeInALinkedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DeleteNodeInALinkedList.cpp LinkList.o

ProductOfArrayExceptSelf:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ProductOfArrayExceptSelf.cpp

SlidingWindowMaximum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SlidingWindowMaximum.cpp

NumberOfDigitOne:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfDigitOne.cpp

DifferentWaysToAddParentheses:
	$(CC) -std=c++11 $(DFLAGS) $(INCLUDES) $(LEETCODE)DifferentWaysToAddParentheses.cpp

AddDigits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddDigits.cpp
	
BinaryTreePaths:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePaths.cpp

UglyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumber.cpp

UglyNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumberII.cpp

ctags:
	ctags -R .

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
