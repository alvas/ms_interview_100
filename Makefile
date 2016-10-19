#default: all

#CFLAGS =-std=c++11 -stdlib=libc++
EXPORTED = -DEXPORTED
#DEBUG = -DDEBUG -g
#FLAGS =
# -c: compile or assemble the source files, but do not link.
CFLAGS = -c -Wall -DDEBUG -DEXPORTED
DFLAGS = -std=c++11 -Wall -g -DDEBUG
LFLAGS = -Wall
#CC = /usr/local/bin/g++-4.7
#CC = /usr/bin/g++
# use ccache speed up compile time
#CC = ccache clang++
# use distcc to distribute compile
#CC = distcc clang++
CC = clang++
# using boost
LEETCODE = ./leetcode/
mkfile_path :=$(shell pwd)
# using this, so the header file could be found in the ms_interview_100 folder.
INCLUDES = -I/usr/include -I/usr/local/include -I$(mkfile_path)
OPTS=-ggdb -pg -fprofile-arcs -ftest-coverage
UNITE_TEST = -L/usr/local/lib/ -lboost_unit_test_framework

LIBS = 

SRCS = *.cpp

#OBJS = $(SRCS:.cpp=.o)

#all:
#	@for i in {1..341}; do \
#		make $$i ; \
#	done

#   rm *.o

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
	$(CC) $(DFLAGS) $(INCLUDES) StringSearch.cpp RandomData.o NormalData.o

LinkList.o: RandomData.o NormalData.o
	$(CC) $(CFLAGS) LinkList.cpp RandomData.o NormalData.o

LinkList: NormalData.o RandomData.o
	$(CC) $(DFLAGS) LinkList.cpp NormalData.o RandomData.o

Bit: 
	$(CC) $(FLAGS) Bit.cpp

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
	$(CC) -std=c++11 $(DFLAGS) Graph.cpp NormalData.o

Power:
	$(CC) $(DFLAGS) Power.cpp

Shift: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) Shift.cpp NormalData.o

BinarySearch: RandomData.o
	$(CC) $(DFLAGS) BinarySearch.cpp RandomData.o NormalData.o

RotationallySymmetricNumbers:
	$(CC) $(DFLAGS) RotationallySymmetricNumbers.cpp

ZigZagArray:
	$(CC) $(DFLAGS) ZigZagArray.cpp
	
.PHONY: 1
1: TwoSum
TwoSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(UNITE_TEST) $(LEETCODE)TwoSum.cpp

.PHONY: 2
2: AddTwoNumbers
AddTwoNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddTwoNumbers.cpp 

.PHONY: 3
3: LongestSubstringWithoutRepeatingCharacters
LongestSubstringWithoutRepeatingCharacters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithoutRepeatingCharacters.cpp

.PHONY: 4
4: MedianOfTwoSortedArrays
MedianOfTwoSortedArrays: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MedianOfTwoSortedArrays.cpp NormalData.o RandomData.o

.PHONY: 5
5: LongestPalindromicSubstring
LongestPalindromicSubstring:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestPalindromicSubstring.cpp

.PHONY: 6
6: ZigZagConversion
ZigZagConversion:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ZigZagConversion.cpp 

.PHONY: 7
7: ReverseInteger
ReverseInteger:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseInteger.cpp 

.PHONY: 8
8: StringToInteger
StringToInteger:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StringToInteger.cpp 

.PHONY: 9
9: PalindromeNumber
PalindromeNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeNumber.cpp 

.PHONY: 10
10: RegularExpressionMatching
RegularExpressionMatching:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RegularExpressionMatching.cpp

.PHONY: 11
11: ContainerWithMostWater
ContainerWithMostWater: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainerWithMostWater.cpp RandomData.o NormalData.o

.PHONY: 12
12: IntegerToRoman
IntegerToRoman:
	$(CC) $(DFLAGS) $(LEETCODE)IntegerToRoman.cpp

.PHONY: 13
13: RomanToInteger
RomanToInteger:
	$(CC) $(DFLAGS) $(LEETCODE)RomanToInteger.cpp

.PHONY: 14
14: LongestCommonPrefix
LongestCommonPrefix:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestCommonPrefix.cpp 

.PHONY: 15
15: ThreeSum
ThreeSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSum.cpp

.PHONY: 16
16: ThreeSumClosest
ThreeSumClosest:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSumClosest.cpp

.PHONY: 17
17: LetterCombinationsOfAPhoneNumber
LetterCombinationsOfAPhoneNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LetterCombinationsOfAPhoneNumber.cpp

.PHONY: 18
18: FourSum
FourSum: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FourSum.cpp NormalData.o

.PHONY: 19
19: RemoveNthNodeFromEndOfList
RemoveNthNodeFromEndOfList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveNthNodeFromEndOfList.cpp LinkList.o RandomData.o NormalData.o

.PHONY: 20
20: ValidParentheses
ValidParentheses:
	$(CC) $(DFLAGS) $(LEETCODE)ValidParentheses.cpp

.PHONY: 21
21: MergeTwoSortedLists
MergeTwoSortedLists: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeTwoSortedLists.cpp LinkList.o

.PHONY: 22
22: GenerateParentheses
GenerateParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GenerateParentheses.cpp

.PHONY: 23
23: MergeKSortedLists
MergeKSortedLists: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeKSortedLists.cpp RandomData.o NormalData.o

.PHONY: 24
24: SwapNodesInPairs
SwapNodesInPairs: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SwapNodesInPairs.cpp LinkList.o

.PHONY: 25
25: ReverseNodesInKGroup
ReverseNodesInKGroup: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseNodesInKGroup.cpp LinkList.o

.PHONY: 26
26: RemoveDuplicatesFromSortedArray
RemoveDuplicatesFromSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArray.cpp

.PHONY: 27
27: RemoveElement
RemoveElement:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveElement.cpp 

.PHONY: 28
28: ImplementStrStr
ImplementStrStr:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStrStr.cpp

.PHONY: 29
29: DivideTwoIntegers
DivideTwoIntegers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DivideTwoIntegers.cpp

.PHONY: 30
30: SubstringWithConcatenationOfAllWords
SubstringWithConcatenationOfAllWords:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubstringWithConcatenationOfAllWords.cpp

.PHONY: 31
31: NextPermutation
NextPermutation: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NextPermutation.cpp NormalData.o

.PHONY: 32
32: LongestValidParentheses
LongestValidParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestValidParentheses.cpp

.PHONY: 33
33: SearchInRotatedSortedArray
SearchInRotatedSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArray.cpp

.PHONY: 34
34: SearchForARange
SearchForARange:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchForARange.cpp

.PHONY: 35
35: SearchInsertPosition
SearchInsertPosition:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInsertPosition.cpp

.PHONY: 36
36: ValidSudoku
ValidSudoku:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidSudoku.cpp 

.PHONY: 37
37: SudokuSolver
SudokuSolver:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SudokuSolver.cpp 

.PHONY: 38
38: CountAndSay
CountAndSay:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountAndSay.cpp

.PHONY: 39
39: CombinationSum
CombinationSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSum.cpp

.PHONY: 40
40: CombinationSumII
CombinationSumII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumII.cpp

.PHONY: 41
41: FirstMissingPositive
FirstMissingPositive:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstMissingPositive.cpp

.PHONY: 42
42: TrappingRainWater
TrappingRainWater: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TrappingRainWater.cpp RandomData.o NormalData.o

.PHONY: 43
43: MultiplyStrings
MultiplyStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MultiplyStrings.cpp

.PHONY: 44
44: WildcardMatching
WildcardMatching:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WildcardMatching.cpp

.PHONY: 45
45: JumpGameII
JumpGameII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGameII.cpp

.PHONY: 46
46: Permutations
Permutations:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Permutations.cpp

.PHONY: 47
47: PermutationsII
PermutationsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationsII.cpp

.PHONY: 48
48: RotateImage
RotateImage: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateImage.cpp RandomData.o NormalData.o

.PHONY: 49
49: GroupAnagrams
GroupAnagrams:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GroupAnagrams.cpp

.PHONY: 50
50: PowXN
PowXN:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowXN.cpp

.PHONY: 51
51: NQueens
NQueens: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueens.cpp NormalData.o

.PHONY: 52
52: NQueensII
NQueensII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueensII.cpp

.PHONY: 53
53: MaximumSubarray
MaximumSubarray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumSubarray.cpp

.PHONY: 54
54: SpiralMatrix
SpiralMatrix: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrix.cpp NormalData.o

.PHONY: 55
55: JumpGame
JumpGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGame.cpp

.PHONY: 56
56: MergeIntervals
MergeIntervals:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeIntervals.cpp

.PHONY: 57
57: InsertInterval
InsertInterval:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertInterval.cpp

.PHONY: 58
58: LengthOfLastWord
LengthOfLastWord:
	$(CC) $(DFLAGS) $(LEETCODE)LengthOfLastWord.cpp

.PHONY: 59
59: SpiralMatrixII
SpiralMatrixII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrixII.cpp

.PHONY: 60
60: PermutationSequence
PermutationSequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationSequence.cpp

.PHONY: 61
61: RotateList
RotateList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateList.cpp LinkList.o

.PHONY: 62
62: UniquePaths
UniquePaths:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePaths.cpp

.PHONY: 63
63: UniquePathsII
UniquePathsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePathsII.cpp

.PHONY: 64
64: MinimumPathSum
MinimumPathSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumPathSum.cpp

.PHONY: 65
65: ValidNumber
ValidNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidNumber.cpp

.PHONY: 66
66: PlusOne
PlusOne:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PlusOne.cpp 

.PHONY: 67
67: AddBinary
AddBinary:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddBinary.cpp 

.PHONY: 68
68: TextJustification
TextJustification:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TextJustification.cpp

.PHONY: 69
69: SqrtX
SqrtX:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SqrtX.cpp

.PHONY: 70
70: ClimbingStairs
ClimbingStairs:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClimbingStairs.cpp 

.PHONY: 71
71: SimplifyPath
SimplifyPath:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SimplifyPath.cpp

.PHONY: 72
72: EditDistance
EditDistance:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EditDistance.cpp

.PHONY: 73
73: SetMatrixZeroes
SetMatrixZeroes: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SetMatrixZeroes.cpp RandomData.o NormalData.o

.PHONY: 74
74: SearchA2DMatrix
SearchA2DMatrix: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrix.cpp RandomData.o NormalData.o

.PHONY: 75
75: SortColors
SortColors:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortColors.cpp

.PHONY: 76
76: MinimumWindowSubstring
MinimumWindowSubstring:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumWindowSubstring.cpp

.PHONY: 77
77: Combinations
Combinations:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Combinations.cpp

.PHONY: 78
78: Subsets
Subsets: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Subsets.cpp NormalData.o

.PHONY: 79
79: WordSearch
WordSearch:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearch.cpp

.PHONY: 80
80: RemoveDuplicatesFromSortedArrayII
RemoveDuplicatesFromSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArrayII.cpp

.PHONY: 81
81: SearchInRotatedSortedArrayII
SearchInRotatedSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArrayII.cpp

.PHONY: 82
82: RemoveDuplicatesFromSortedListII
RemoveDuplicatesFromSortedListII: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedListII.cpp LinkList.o

.PHONY: 83
83: RemoveDuplicatesFromSortedList
RemoveDuplicatesFromSortedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedList.cpp LinkList.o

.PHONY: 84
84: LargestRectangleInHistogram
LargestRectangleInHistogram: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestRectangleInHistogram.cpp NormalData.o

.PHONY: 85
85: MaximalRectangle
MaximalRectangle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalRectangle.cpp

.PHONY: 86
86: PartitionList
PartitionList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PartitionList.cpp

.PHONY: 87
87: ScrambleString
ScrambleString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ScrambleString.cpp

.PHONY: 88
88: MergeSortedArray
MergeSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeSortedArray.cpp 

.PHONY: 89
89: GrayCode
GrayCode:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GrayCode.cpp

.PHONY: 90
90: SubsetsII
SubsetsII: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubsetsII.cpp NormalData.o RandomData.o

.PHONY: 91
91: DecodeWays
DecodeWays:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DecodeWays.cpp

.PHONY: 92
92: ReverseLinkedListII
ReverseLinkedListII: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedListII.cpp LinkList.o

.PHONY: 93
93: RestoreIPAddresses
RestoreIPAddresses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RestoreIPAddresses.cpp

.PHONY: 94
94: BinaryTreeInorderTraversal
BinaryTreeInorderTraversal: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeInorderTraversal.cpp

.PHONY: 95
95: UniqueBinarySearchTreesII
UniqueBinarySearchTreesII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTreesII.cpp

.PHONY: 96
96: UniqueBinarySearchTrees
UniqueBinarySearchTrees:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTrees.cpp

.PHONY: 97
97: InterleavingString
InterleavingString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InterleavingString.cpp

.PHONY: 98
98: ValidateBinarySearchTree
ValidateBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidateBinarySearchTree.cpp

.PHONY: 99
99: RecoverBinarySearchTree
RecoverBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RecoverBinarySearchTree.cpp

.PHONY: 100
100: SameTree
SameTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SameTree.cpp

.PHONY: 101
101: SymmetricTree
SymmetricTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SymmetricTree.cpp

.PHONY: 102
102: BinaryTreeLevelOrderTraversal
BinaryTreeLevelOrderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversal.cpp

.PHONY: 103
103: BinaryTreeZigzagLevelOrderTraversal
BinaryTreeZigzagLevelOrderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeZigzagLevelOrderTraversal.cpp

.PHONY: 104
104: MaximumDepthOfBinaryTree
MaximumDepthOfBinaryTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumDepthOfBinaryTree.cpp 

.PHONY: 105
105: ConstructBinaryTreeFromPreorderAndInorderTraversal
ConstructBinaryTreeFromPreorderAndInorderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp

.PHONY: 106
106: ConstructBinaryTreeFromInorderAndPostorderTraversal
ConstructBinaryTreeFromInorderAndPostorderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp

.PHONY: 107
107: BinaryTreeLevelOrderTraversalII
BinaryTreeLevelOrderTraversalII: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversalII.cpp 

.PHONY: 108
108: ConvertSortedArrayToBinarySearchTree
ConvertSortedArrayToBinarySearchTree: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedArrayToBinarySearchTree.cpp 

.PHONY: 109
109: ConvertSortedListToBinarySearchTree
ConvertSortedListToBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedListToBinarySearchTree.cpp

.PHONY: 110
110: BalancedBinaryTree
BalancedBinaryTree: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BalancedBinaryTree.cpp 

.PHONY: 111
111: MinimumDepthOfBinaryTree
MinimumDepthOfBinaryTree: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumDepthOfBinaryTree.cpp 

.PHONY: 112
112: PathSum
PathSum: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSum.cpp 

.PHONY: 113
113: PathSumII
PathSumII: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSumII.cpp 

.PHONY: 114
114: FlattenBinaryLinkedList
FlattenBinaryLinkedList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FlattenBinaryLinkedList.cpp

.PHONY: 115
115: DistinctSubsequences
DistinctSubsequences:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DistinctSubsequences.cpp

.PHONY: 116
116: PopulatingNextRightPointersInEachNode
PopulatingNextRightPointersInEachNode: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNode.cpp 

.PHONY: 117
117: PopulatingNextRightPointersInEachNodeII
PopulatingNextRightPointersInEachNodeII: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNodeII.cpp 

.PHONY: 118
118: PascalsTriangle
PascalsTriangle: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle.cpp NormalData.o

.PHONY: 119
119: PascalsTriangle2 
PascalsTriangle2: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle2.cpp NormalData.o

.PHONY: 120
120: Triangle
Triangle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Triangle.cpp

.PHONY: 121
121: BestTimeToBuyAndSellStock
BestTimeToBuyAndSellStock:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStock.cpp

.PHONY: 122
122: BestTimeToBuyAndSellStockII
BestTimeToBuyAndSellStockII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockII.cpp

.PHONY: 123
123: BestTimeToBuyAndSellStockIII
BestTimeToBuyAndSellStockIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIII.cpp

.PHONY: 124
124: BinaryTreeMaximumPathSum
BinaryTreeMaximumPathSum: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeMaximumPathSum.cpp 

.PHONY: 125
125: ValidPalindrome
ValidPalindrome:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidPalindrome.cpp 

.PHONY: 126
126: WordLadderII
WordLadderII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadderII.cpp

.PHONY: 127
127: WordLadder
WordLadder:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadder.cpp

.PHONY: 128
128: LongestConsecutiveSequence
LongestConsecutiveSequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestConsecutiveSequence.cpp

.PHONY: 129
129: SumRootToLeafNumbers
SumRootToLeafNumbers: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SumRootToLeafNumbers.cpp 

.PHONY: 130
130: SurroundedRegions
SurroundedRegions:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SurroundedRegions.cpp

.PHONY: 131
131: PalindromePartitioning
PalindromePartitioning:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioning.cpp

.PHONY: 132
132: PalindromePartitioningII
PalindromePartitioningII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioningII.cpp

.PHONY: 133
133: CloneGraph
CloneGraph:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CloneGraph.cpp

.PHONY: 134
134: GasStation
GasStation: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GasStation.cpp RandomData.o NormalData.o

.PHONY: 135
135: Candy
Candy: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Candy.cpp RandomData.o NormalData.o

.PHONY: 136
136: SingleNumber
SingleNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumber.cpp

.PHONY: 137
137: SingleNumberII
SingleNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberII.cpp

.PHONY: 138
138: CopyListWithRandomPointer
CopyListWithRandomPointer: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CopyListWithRandomPointer.cpp LinkList.o

.PHONY: 139
139: WordBreak
WordBreak:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreak.cpp

.PHONY: 140
140: WordBreakII
WordBreakII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreakII.cpp

.PHONY: 141
141: LinkedListCycle
LinkedListCycle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycle.cpp 

.PHONY: 142
142: LinkedListCycleII
LinkedListCycleII: LinkList.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycleII.cpp LinkList.o NormalData.o

.PHONY: 143
143: ReorderList
ReorderList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReorderList.cpp LinkList.o

.PHONY: 144
144: BinaryTreePreorderTraversal
BinaryTreePreorderTraversal: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePreorderTraversal.cpp 

.PHONY: 145
145: BinarystorderTraversal
BinarystorderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinarystorderTraversal.cpp Tree.o

.PHONY: 146
146: LRUCache
LRUCache:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LRUCache.cpp

.PHONY: 147
147: InsertionSortList
InsertionSortList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertionSortList.cpp

.PHONY: 148
148: SortList
SortList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortList.cpp

.PHONY: 149
149: MaxPointsOnALine
MaxPointsOnALine:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaxPointsOnALine.cpp

.PHONY: 150
150: EvaluateReversePolishNotation
EvaluateReversePolishNotation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EvaluateReversePolishNotation.cpp

.PHONY: 151
151: ReverseWordsInAString
ReverseWordsInAString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseWordsInAString.cpp

.PHONY: 152
152: MaximumProductSubarray
MaximumProductSubarray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumProductSubarray.cpp

.PHONY: 153
153: FindMinimumInRotatedSortedArray
FindMinimumInRotatedSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArray.cpp

.PHONY: 154
154: FindMinimumInRotatedSortedArrayII
FindMinimumInRotatedSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArrayII.cpp

.PHONY: 155
155: MinStack
MinStack:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinStack.cpp 

.PHONY: 156
156: BinaryTreeUpsideDown
BinaryTreeUpsideDown:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeUpsideDown.cpp 
	
.PHONY: 157
157: ReadNCharactersGivenRead
ReadNCharactersGivenRead: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReadNCharactersGivenRead.cpp 

.PHONY: 158
158: ReadNCharactersGivenReadII
ReadNCharactersGivenReadII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReadNCharactersGivenReadII.cpp

.PHONY: 159
159: LongestSubstringWithAtMostTwoDistinctCharacters
LongestSubstringWithAtMostTwoDistinctCharacters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithAtMostTwoDistinctCharacters.cpp 

.PHONY: 160
160: IntersectionOfTwoLinkedLists
IntersectionOfTwoLinkedLists: LinkList.o
	$(CC) $(DFLAGS) $(LEETCODE)IntersectionOfTwoLinkedLists.cpp LinkList.o RandomData.o NormalData.o

.PHONY: 161
161: OneEditDistance
OneEditDistance:
	$(CC) $(DFLAGS) $(LEETCODE)OneEditDistance.cpp

.PHONY: 162
162: FindPeakElement
FindPeakElement: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindPeakElement.cpp RandomData.o NormalData.o

.PHONY: 163
163: MissingRanges
MissingRanges:
	$(CC) $(DFLAGS) $(LEETCODE)MissingRanges.cpp

.PHONY: 164
164: MaximumGap
MaximumGap: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumGap.cpp RandomData.o NormalData.o

.PHONY: 165
165: CompareVersionNumbers
CompareVersionNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CompareVersionNumbers.cpp

.PHONY: 166
166: FractionToRecurringDecimal
FractionToRecurringDecimal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FractionToRecurringDecimal.cpp

.PHONY: 167
167: TwoSumIIInputArrayIsSorted
TwoSumIIInputArrayIsSorted:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TwoSumIIInputArrayIsSorted.cpp

.PHONY: 168
168: ExcelSheetColumnTitle
ExcelSheetColumnTitle:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnTitle.cpp

.PHONY: 169
169: MajorityElement
MajorityElement:
	$(CC) $(DFLAGS) $(LEETCODE)MajorityElement.cpp

.PHONY: 170
170: TwoSumIII
TwoSumIII:
	$(CC) $(DFLAGS) $(LEETCODE)TwoSumIII.cpp

.PHONY: 171
171: ExcelSheetColumnNumber
ExcelSheetColumnNumber:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnNumber.cpp

.PHONY: 172
172: FactorialTrailingZeroes
FactorialTrailingZeroes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FactorialTrailingZeroes.cpp

.PHONY: 173
173: BinarySearchTreeIterator
BinarySearchTreeIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinarySearchTreeIterator.cpp

.PHONY: 174
174: DungeonGame
DungeonGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DungeonGame.cpp

.PHONY: 175
175:
	echo "No 175"

.PHONY: 176
176:
	echo "No 176"

.PHONY: 177
177:
	echo "No 177"

.PHONY: 178
178:
	echo "No 178"

.PHONY: 179
179: LargestNumber
LargestNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestNumber.cpp

.PHONY: 180
180:
	echo "No 180"

.PHONY: 181
181:
	echo "No 181"

.PHONY: 182
182:
	echo "No 182"

.PHONY: 183
183:
	echo "No 183"

.PHONY: 184
184:
	echo "No 184"

.PHONY: 185
185:
	echo "No 185"

.PHONY: 186
186: ReverseWordsInAStringII
ReverseWordsInAStringII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseWordsInAStringII.cpp

.PHONY: 187
187: RepeatedDNASequences
RepeatedDNASequences:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RepeatedDNASequences.cpp

.PHONY: 188
188: BestTimeToBuyAndSellStockIV
BestTimeToBuyAndSellStockIV:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIV.cpp

.PHONY: 189
189: RandomData.o
RotateArray: RandomData.o
	$(CC) $(DFLAGS) $(LEETCODE)RotateArray.cpp RandomData.o NormalData.o

.PHONY: 190
190: ReverseBits
ReverseBits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseBits.cpp

.PHONY: 191
191: NumberOf1Bits
NumberOf1Bits:
	$(CC) $(DFLAGS) $(LEETCODE)NumberOf1Bits.cpp

.PHONY: 192
192:
	echo "No 192"

.PHONY: 193
193:
	echo "No 193"

.PHONY: 194
194:
	echo "No 194"

.PHONY: 195
195:
	echo "No 195"

.PHONY: 196
196:
	echo "No 196"

.PHONY: 197
197:
	echo "No 197"

.PHONY: 198
198: HouseRobber
HouseRobber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobber.cpp 

.PHONY: 199
199: BinaryTreeRightSideView
BinaryTreeRightSideView:  NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeRightSideView.cpp  NormalData.o

.PHONY: 200
200: NumberOfIslands
NumberOfIslands:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfIslands.cpp

.PHONY: 201
201: BitwiseAndOfNumbersRange
BitwiseAndOfNumbersRange:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BitwiseAndOfNumbersRange.cpp

.PHONY: 202
202: HappyNumber
HappyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HappyNumber.cpp 

.PHONY: 203
203: RemoveLinkedListElements
RemoveLinkedListElements: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveLinkedListElements.cpp LinkList.o

.PHONY: 204
204: CountPrimes
CountPrimes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountPrimes.cpp

.PHONY: 205
205: IsomorphicStrings
IsomorphicStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IsomorphicStrings.cpp

.PHONY: 206
206: ReverseLinkedList
ReverseLinkedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedList.cpp LinkList.o

.PHONY: 207
207: CourseSchedule
CourseSchedule:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseSchedule.cpp

.PHONY: 208
208: ImplementTrie
ImplementTrie:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementTrie.cpp

.PHONY: 209
209: MinimumSizeSubarraySum
MinimumSizeSubarraySum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumSizeSubarraySum.cpp

.PHONY: 210
210: CourseScheduleII
CourseScheduleII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseScheduleII.cpp

.PHONY: 211
211: AddAndSearchWord
AddAndSearchWord:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddAndSearchWord.cpp

.PHONY: 212
212: WordSearchII
WordSearchII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearchII.cpp

.PHONY: 213
213: HouseRobberII
HouseRobberII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobberII.cpp RandomData.o NormalData.o

.PHONY: 214
214: ShortestPalindrome
ShortestPalindrome:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestPalindrome.cpp

.PHONY: 215
215: KthLargestElementInAnArray
KthLargestElementInAnArray: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthLargestElementInAnArray.cpp RandomData.o NormalData.o

.PHONY: 216
216: CombinationSumIII
CombinationSumIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumIII.cpp

.PHONY: 217
217: ContainsDuplicate
ContainsDuplicate:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicate.cpp

.PHONY: 218
218: TheSkylineProblem
TheSkylineProblem:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TheSkylineProblem.cpp

.PHONY: 219
219: ContainsDuplicateII
ContainsDuplicateII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateII.cpp

.PHONY: 220
220: ContainsDuplicateIII
ContainsDuplicateIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateIII.cpp

.PHONY: 221
221: MaximalSquare
MaximalSquare:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalSquare.cpp

.PHONY: 222
222: CountCompletedes
CountCompletedes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountCompletedes.cpp

.PHONY: 223
223: RectangleArea
RectangleArea:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RectangleArea.cpp

.PHONY: 224
224: BasicCalculator
BasicCalculator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculator.cpp

.PHONY: 225
225: ImplementStackUsingQueues
ImplementStackUsingQueues:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStackUsingQueues.cpp

.PHONY: 226
226: InvertBinaryTree
InvertBinaryTree: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InvertBinaryTree.cpp 

.PHONY: 227
227: BasicCalculatorII
BasicCalculatorII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculatorII.cpp

.PHONY: 228
228: SummaryRanges
SummaryRanges:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SummaryRanges.cpp

.PHONY: 229
229: MajorityElementII
MajorityElementII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MajorityElementII.cpp RandomData.o NormalData.o

.PHONY: 230
230: KthSmallestElementInABST
KthSmallestElementInABST: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthSmallestElementInABST.cpp 

.PHONY: 231
231: PowerOfTwo
PowerOfTwo:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowerOfTwo.cpp

.PHONY: 232
232: ImplementQueueUsingStacks
ImplementQueueUsingStacks:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementQueueUsingStacks.cpp

.PHONY: 233
233: NumberOfDigitOne
NumberOfDigitOne:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfDigitOne.cpp

.PHONY: 234
234: PalindromeLinkedList
PalindromeLinkedList: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeLinkedList.cpp RandomData.o NormalData.o

.PHONY: 235
235: LowestCommonAncestorOfABinarySearchTree
LowestCommonAncestorOfABinarySearchTree: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinarySearchTree.cpp 

.PHONY: 236
236: LowestCommonAncestorOfABinaryTree
LowestCommonAncestorOfABinaryTree: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinaryTree.cpp 

.PHONY: 237
237: DeleteNodeInALinkedList
DeleteNodeInALinkedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DeleteNodeInALinkedList.cpp LinkList.o

.PHONY: 238
238: ProductOfArrayExceptSelf
ProductOfArrayExceptSelf:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ProductOfArrayExceptSelf.cpp

.PHONY: 239
239: SlidingWindowMaximum
SlidingWindowMaximum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SlidingWindowMaximum.cpp

.PHONY: 240
240: SearchA2DMatrixII
SearchA2DMatrixII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrixII.cpp

Anagrams:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Anagrams.cpp

.PHONY: 241
241: DifferentWaysToAddParentheses
DifferentWaysToAddParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DifferentWaysToAddParentheses.cpp

.PHONY: 242
242: ValidAnagram
ValidAnagram:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidAnagram.cpp

.PHONY: 243
243: ShortestWordDistance
ShortestWordDistance:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistance.cpp

.PHONY: 244
244: ShortestWordDistanceII
ShortestWordDistanceII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistanceII.cpp

.PHONY: 245
245: ShortestWordDistanceIII
ShortestWordDistanceIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistanceIII.cpp

.PHONY: 246
246: StrobogrammaticNumber
StrobogrammaticNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumber.cpp

.PHONY: 247
247: StrobogrammaticNumberII
StrobogrammaticNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumberII.cpp

.PHONY: 248
248: StrobogrammaticNumberIII
StrobogrammaticNumberIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumberIII.cpp

.PHONY: 249
249: GroupShiftedStrings
GroupShiftedStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GroupShiftedStrings.cpp

.PHONY: 250
250: CountUnivalueSubtrees
CountUnivalueSubtrees:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountUnivalueSubtrees.cpp

.PHONY: 251
251: Flatten2DVector
Flatten2DVector:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Flatten2DVector.cpp

.PHONY: 252
252: MeetingRooms
MeetingRooms:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MeetingRooms.cpp

.PHONY: 253
253: MeetingRoomsII
MeetingRoomsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MeetingRoomsII.cpp

.PHONY: 254
254: FactorCombinations
FactorCombinations:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FactorCombinations.cpp

.PHONY: 255
255: VerifyPreOrderSequenceInBinarySearchTree
VerifyPreOrderSequenceInBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)VerifyPreOrderSequenceInBinarySearchTree.cpp

.PHONY: 256
256: PaintHouse
PaintHouse:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintHouse.cpp

.PHONY: 257
257: BinaryTreePaths
BinaryTreePaths:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePaths.cpp

.PHONY: 258
258: AddDigits
AddDigits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddDigits.cpp
	
.PHONY: 259
259: ThreeSumSmaller
ThreeSumSmaller:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSumSmaller.cpp
	
.PHONY: 260
260: SingleNumberIII
SingleNumberIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberIII.cpp

.PHONY: 261
261: GraphValidTree
GraphValidTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GraphValidTree.cpp

.PHONY: 263
263: UglyNumber
UglyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumber.cpp

.PHONY: 264
264: UglyNumberII
UglyNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumberII.cpp

.PHONY: 265
265: PaintHouseII
PaintHouseII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintHouseII.cpp

.PHONY: 266
266: PalindromePermutation
PalindromePermutation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePermutation.cpp

.PHONY: 267
267: PalindromePermutationII
PalindromePermutationII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePermutationII.cpp

.PHONY: 268
268: MissingNumber
MissingNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MissingNumber.cpp

.PHONY: 269
269: AlienDictonary
AlienDictonary:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AlienDictonary.cpp

.PHONY: 270
270: ClosestBinarySearchTreeValue
ClosestBinarySearchTreeValue:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClosestBinarySearchTreeValue.cpp

.PHONY: 271
271: EncodeAndDecodeStrings
EncodeAndDecodeStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EncodeAndDecodeStrings.cpp

.PHONY: 272
272: ClosestBinarySearchTreeValueII
ClosestBinarySearchTreeValueII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClosestBinarySearchTreeValueII.cpp

.PHONY: 273
273: IntegerToEnglishWords
IntegerToEnglishWords:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IntegerToEnglishWords.cpp

.PHONY: 274
274: HIndex
HIndex:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HIndex.cpp

.PHONY: 275
275: HIndexII
HIndexII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HIndexII.cpp

.PHONY: 276
276: PaintFence
PaintFence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintFence.cpp

.PHONY: 277
277: FindTheCelebrity
FindTheCelebrity:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindTheCelebrity.cpp

.PHONY: 278
278: FirstBadVersion
FirstBadVersion:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstBadVersion.cpp

.PHONY: 279
279: PerfectSquares
PerfectSquares:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PerfectSquares.cpp

.PHONY: 280
280: WiggleSort
WiggleSort:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WiggleSort.cpp

.PHONY: 281
281: ZigzagIterator
ZigzagIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ZigzagIterator.cpp

.PHONY: 282
282: ExpressionAddOperators
ExpressionAddOperators:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ExpressionAddOperators.cpp

.PHONY: 283
283: MoveZeros
MoveZeros:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MoveZeros.cpp

.PHONY: 284
284: PeekingIterator
PeekingIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PeekingIterator.cpp

.PHONY: 285
285: InorderSuccessorInBST
InorderSuccessorInBST:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InorderSuccessorInBST.cpp

.PHONY: 286
286: WallsAndGates
WallsAndGates:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WallsAndGates.cpp

.PHONY: 287
287: FindTheDuplicateNumber
FindTheDuplicateNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindTheDuplicateNumber.cpp

.PHONY: 288
288: UniqueWordAbbreviation
UniqueWordAbbreviation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueWordAbbreviation.cpp

.PHONY: 289
289: GameOfLife
GameOfLife:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GameOfLife.cpp

.PHONY: 290
290: WordPattern
WordPattern:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordPattern.cpp

.PHONY: 291
291: WordPatternII
WordPatternII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordPatternII.cpp

.PHONY: 292
292: NimGame
NimGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NimGame.cpp

.PHONY: 293
293: FlipGame
FlipGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FlipGame.cpp

.PHONY: 294
294: FlipGameII
FlipGameII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FlipGameII.cpp

.PHONY: 295
295: FindMedianFromDataStream
FindMedianFromDataStream:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMedianFromDataStream.cpp

.PHONY: 296
296: BestMeetingPoint
BestMeetingPoint:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestMeetingPoint.cpp

.PHONY: 297
297: SerializeAndDeserializeBinaryTree
SerializeAndDeserializeBinaryTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SerializeAndDeserializeBinaryTree.cpp

.PHONY: 298
298: BinaryngestConsecutiveSequence
BinaryngestConsecutiveSequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryngestConsecutiveSequence.cpp

.PHONY: 299
299: BullsAndCows
BullsAndCows:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BullsAndCows.cpp

.PHONY: 300
300: LongestIncreasingSubsequence
LongestIncreasingSubsequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestIncreasingSubsequence.cpp

.PHONY: 301
301: RemoveInvalidParenthese
RemoveInvalidParenthese:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveInvalidParenthese.cpp

.PHONY: 302
302: SmallestRectangleEnclosingBlackPixels
SmallestRectangleEnclosingBlackPixels:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SmallestRectangleEnclosingBlackPixels.cpp

.PHONY: 303
303: RangeSumQueryImmutable
RangeSumQueryImmutable:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RangeSumQueryImmutable.cpp

.PHONY: 304
304: RangeSumQuery2DImmutable
RangeSumQuery2DImmutable:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RangeSumQuery2DImmutable.cpp

.PHONY: 305
305: NumberOfIslandsII
NumberOfIslandsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfIslandsII.cpp

.PHONY: 306
306: AdditiveNumber
AdditiveNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AdditiveNumber.cpp

.PHONY: 307
307: RangeSumQueryMutable
RangeSumQueryMutable:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RangeSumQueryMutable.cpp

.PHONY: 308
308: RangeSumQuery2DMutable
RangeSumQuery2DMutable:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RangeSumQuery2DMutable.cpp

.PHONY: 309
309: BestTimeToBuyAndSellStockWithCooldown
BestTimeToBuyAndSellStockWithCooldown:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockWithCooldown.cpp

.PHONY: 310
310: MinimumHeightTrees
MinimumHeightTrees:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumHeightTrees.cpp

.PHONY: 311
311: SparseMatrixMultiplication
SparseMatrixMultiplication:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SparseMatrixMultiplication.cpp

.PHONY: 312
312: BurstBalloons
BurstBalloons:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BurstBalloons.cpp

.PHONY: 313
313: SuperUglyNumber
SuperUglyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SuperUglyNumber.cpp

.PHONY: 314
314: BinaryTreeVerticalOrderTraversal
BinaryTreeVerticalOrderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeVerticalOrderTraversal.cpp

.PHONY: 315
315: CountOfSmallerNumbersAfterSelf
CountOfSmallerNumbersAfterSelf:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountOfSmallerNumbersAfterSelf.cpp

.PHONY: 316
316: RemoveDuplicateLetters
RemoveDuplicateLetters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicateLetters.cpp

.PHONY: 317
317: ShortestDistanceFromAllBuildings
ShortestDistanceFromAllBuildings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestDistanceFromAllBuildings.cpp

.PHONY: 318
318: MaximumProductOfWordLengths
MaximumProductOfWordLengths:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumProductOfWordLengths.cpp

.PHONY: 319
319: BulbSwitcher
BulbSwitcher:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BulbSwitcher.cpp

.PHONY: 320
320: GeneralizedAbbreviation
GeneralizedAbbreviation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GeneralizedAbbreviation.cpp

.PHONY: 321
321: CreateMaximumNumber
CreateMaximumNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CreateMaximumNumber.cpp

.PHONY: 322
322: CoinChange
CoinChange:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CoinChange.cpp

.PHONY: 323
323: NumberOfConnectedComponentsInAnUndirectedGraph
NumberOfConnectedComponentsInAnUndirectedGraph:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfConnectedComponentsInAnUndirectedGraph.cpp

.PHONY: 324
324: WiggleSortII
WiggleSortII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WiggleSortII.cpp

.PHONY: 325
325: MaximumSizeSubarraySumEqualsK
MaximumSizeSubarraySumEqualsK:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumSizeSubarraySumEqualsK.cpp

.PHONY: 326
326: PowerOfThree
PowerOfThree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowerOfThree.cpp

.PHONY: 327
327: CountOfRangeSum
CountOfRangeSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountOfRangeSum.cpp

.PHONY: 328
328: OddEvenLinkedList
OddEvenLinkedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)OddEvenLinkedList.cpp LinkList.o

.PHONY: 329
329: LongestIncreasingPathInAMatrix
LongestIncreasingPathInAMatrix:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestIncreasingPathInAMatrix.cpp

.PHONY: 330
330: PatchingArray
PatchingArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PatchingArray.cpp

.PHONY: 331
331: VerifyPreorderSerializationOfABinaryTree
VerifyPreorderSerializationOfABinaryTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)VerifyPreorderSerializationOfABinaryTree.cpp

.PHONY: 332
332: ReconstructItinerary
ReconstructItinerary:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReconstructItinerary.cpp

.PHONY: 333
333: LargestBSTSubtree
LargestBSTSubtree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestBSTSubtree.cpp

.PHONY: 334
334: IncreasingTripletSubsequence
IncreasingTripletSubsequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IncreasingTripletSubsequence.cpp

.PHONY: 335
335: SelfCrossing
SelfCrossing:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SelfCrossing.cpp

.PHONY: 336
336: PalindromePairs
PalindromePairs:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePairs.cpp

.PHONY: 337
337: HouseRobberIII
HouseRobberIII: 
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobberIII.cpp 

.PHONY: 338
338: CountingBits
CountingBits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountingBits.cpp

.PHONY: 339
339: NestedListWeightSum
NestedListWeightSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NestedListWeightSum.cpp

.PHONY: 340
340: LongestSubstringWithAtMostKDistinctCharacters
LongestSubstringWithAtMostKDistinctCharacters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithAtMostKDistinctCharacters.cpp

.PHONY: 341
341: FlattenNestedListIterator
FlattenNestedListIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FlattenNestedListIterator.cpp

.PHONY: 342
342: PowerOfFour
PowerOfFour:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowerOfFour.cpp

.PHONY: 343
343: IntegerBreak
IntegerBreak:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IntegerBreak.cpp

.PHONY: 344
344: ReverseString
ReverseString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseString.cpp

.PHONY: 345
345: ReverseVowelsOfAString
ReverseVowelsOfAString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseVowelsOfAString.cpp

.PHONY: 346
346: MovingAverageFromDataStream
MovingAverageFromDataStream:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MovingAverageFromDataStream.cpp

.PHONY: 347
347: TopKFrequentElements
TopKFrequentElements:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TopKFrequentElements.cpp

.PHONY: 348
348: DesignTicTacToe
DesignTicTacToe:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DesignTicTacToe.cpp

.PHONY: 349
349: IntersectionOfTwoArrays
IntersectionOfTwoArrays:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IntersectionOfTwoArrays.cpp

.PHONY: 350
350: IntersectionOfTwoArraysII
IntersectionOfTwoArraysII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IntersectionOfTwoArraysII.cpp

.PHONY: 351
351: AndroidUnlockPatterns
AndroidUnlockPatterns:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AndroidUnlockPatterns.cpp

.PHONY: 352
352: DataStreamAsDisjointIntervals
DataStreamAsDisjointIntervals:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DataStreamAsDisjointIntervals.cpp

.PHONY: 353
353: DesignSnakeGame
DesignSnakeGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DesignSnakeGame.cpp

.PHONY: 354
354: RussianDollEnvelopes
RussianDollEnvelopes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RussianDollEnvelopes.cpp

.PHONY: 355
355: DesignTwitter
DesignTwitter:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DesignTwitter.cpp

.PHONY: 356
356: LineReflection
LineReflection:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LineReflection.cpp

.PHONY: 357
357: CountNumbersWithUniqueDigits
CountNumbersWithUniqueDigits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountNumbersWithUniqueDigits.cpp

.PHONY: 358
358: RearrangeStringKDistanceApart
RearrangeStringKDistanceApart:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RearrangeStringKDistanceApart.cpp

.PHONY: 359
359: LoggerRateLimiter
LoggerRateLimiter:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LoggerRateLimiter.cpp

.PHONY: 360
360: SortTransformedArray
SortTransformedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortTransformedArray.cpp

.PHONY: 361
361: BombEnemy
BombEnemy:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BombEnemy.cpp

.PHONY: 362
362: DesignHitCounter
DesignHitCounter:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DesignHitCounter.cpp

.PHONY: 363
363: MaxSumOfRectangleNoLargerThanK
MaxSumOfRectangleNoLargerThanK:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaxSumOfRectangleNoLargerThanK.cpp

.PHONY: 364
364: NestedListWeightSumII
NestedListWeightSumII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NestedListWeightSumII.cpp

.PHONY: 365
365: WaterAndJugProblem
WaterAndJugProblem:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WaterAndJugProblem.cpp

.PHONY: 366
366: FindLeavesOfBinaryTree
FindLeavesOfBinaryTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindLeavesOfBinaryTree.cpp

.PHONY: 367
367: ValidPerfectSquare
ValidPerfectSquare:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidPerfectSquare.cpp

.PHONY: 368
368: LargestDivisibleSubset
LargestDivisibleSubset:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestDivisibleSubset.cpp

.PHONY: 369
369: PlusOneLinkedList
PlusOneLinkedList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PlusOneLinkedList.cpp

.PHONY: 370
370: RangeAddition
RangeAddition:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RangeAddition.cpp

.PHONY: 371
371: SumOfTwoIntegers
SumOfTwoIntegers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SumOfTwoIntegers.cpp

.PHONY: 372
372: SuperPow
SuperPow:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SuperPow.cpp

.PHONY: 373
373: FindKPairsWithSmallestSums
FindKPairsWithSmallestSums:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindKPairsWithSmallestSums.cpp

.PHONY: 374
374: GuessNumberHigherOrLower
GuessNumberHigherOrLower:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GuessNumberHigherOrLower.cpp

.PHONY: 375
375: GuessNumberHigherOrLowerII
GuessNumberHigherOrLowerII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GuessNumberHigherOrLowerII.cpp

.PHONY: 376
376: WiggleSubsequence
WiggleSubsequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WiggleSubsequence.cpp

.PHONY: 377
377: CombinationSumIV
CombinationSumIV:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumIV.cpp

.PHONY: 378
378: KthSmallestElementInASortedMatrix
KthSmallestElementInASortedMatrix:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthSmallestElementInASortedMatrix.cpp

.PHONY: 379
379: DesignPhoneDirectory
DesignPhoneDirectory:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DesignPhoneDirectory.cpp

.PHONY: 380
380: InsertDeleteGetRandomO1
InsertDeleteGetRandomO1:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertDeleteGetRandomO1.cpp

.PHONY: 381
381: InsertDeleteGetRandomO1DuplicatedAllowed
InsertDeleteGetRandomO1DuplicatedAllowed:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertDeleteGetRandomO1DuplicatedAllowed.cpp

.PHONY: 382
382: LinkedListRandomNode
LinkedListRandomNode:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListRandomNode.cpp

.PHONY: 383
383: RansomNote
RansomNote:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RansomNote.cpp

.PHONY: 384
384: ShuffleAnArray
ShuffleAnArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShuffleAnArray.cpp

.PHONY: 385
385: MiniParser
MiniParser:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MiniParser.cpp

.PHONY: 386
386: LexicographicalNumbers
LexicographicalNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LexicographicalNumbers.cpp

.PHONY: 387
387: FirstUniqueCharacterInAString
FirstUniqueCharacterInAString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstUniqueCharacterInAString.cpp

.PHONY: 388
388: LongestAbsoluteFilePath
LongestAbsoluteFilePath:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestAbsoluteFilePath.cpp

.PHONY: 389
389: FindTheDifference
FindTheDifference:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindTheDifference.cpp

.PHONY: 390
390: EliminationGame
EliminationGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EliminationGame.cpp

.PHONY: 391
391: PerfectRectangle
PerfectRectangle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PerfectRectangle.cpp

.PHONY: 392
392: IsSubsequence
IsSubsequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IsSubsequence.cpp

.PHONY: 393
393: UTF8Validation
UTF8Validation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UTF8Validation.cpp

.PHONY: 394
394: DecodeString
DecodeString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DecodeString.cpp

.PHONY: 395
395: LongestSubstringWithAtLeastKRepeatingCharacters
LongestSubstringWithAtLeastKRepeatingCharacters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithAtLeastKRepeatingCharacters.cpp

.PHONY: 396
396: RotateFunction
RotateFunction:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateFunction.cpp

.PHONY: 397
397: IntegerReplacement
IntegerReplacement:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IntegerReplacement.cpp

.PHONY: 398
398: RandomPickIndex
RandomPickIndex:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RandomPickIndex.cpp

.PHONY: 399
399: EvaluateDivision
EvaluateDivision:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EvaluateDivision.cpp

.PHONY: 400
400: NthDigit
NthDigit:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NthDigit.cpp

.PHONY: 401
401: BinaryWatch
BinaryWatch:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryWatch.cpp

.PHONY: 402
402: RemoveKDigits
RemoveKDigits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveKDigits.cpp

.PHONY: 403
403: FrogJump
FrogJump:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FrogJump.cpp

.PHONY: 404
404: SumOfLeftLeaves
SumOfLeftLeaves:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SumOfLeftLeaves.cpp

.PHONY: 405
405: ConvertANumberToHexadecimal
ConvertANumberToHexadecimal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertANumberToHexadecimal.cpp

.PHONY: 406
406: QueueReconstructionByHeight
QueueReconstructionByHeight:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)QueueReconstructionByHeight.cpp

.PHONY: 407
407: 
	echo "No 407"

.PHONY: 408
408: 
	echo "No 408"

.PHONY: 409
409: LongestPalindrome
LongestPalindrome:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestPalindrome.cpp

.PHONY: 410
410: SplitArrayLargestSum
SplitArrayLargestSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SplitArrayLargestSum.cpp

.PHONY: 411
411: MinimumUniqueWordAbbreviation
MinimumUniqueWordAbbreviation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumUniqueWordAbbreviation.cpp

.PHONY: 412
412: FizzBuzz
FizzBuzz:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FizzBuzz.cpp


.PHONY: 413
413: ArithmeticSlices
ArithmeticSlices:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ArithmeticSlices.cpp

.PHONY: 414
414: 
	echo "No 414"

.PHONY: 415
415: AddStrings
AddStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddStrings.cpp

.PHONY: 416
416: PartitionEqualSubsetSum
PartitionEqualSubsetSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PartitionEqualSubsetSum.cpp

.PHONY: 417
417: PacificAtlanticWaterFlow
PacificAtlanticWaterFlow:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PacificAtlanticWaterFlow.cpp

.PHONY: 418
418: SentenceScreenFitting
SentenceScreenFitting:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SentenceScreenFitting.cpp

test:
	echo "test"

tags:
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
