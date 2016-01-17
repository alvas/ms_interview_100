default: all

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

all:
	@for i in {1..290}; \
		do \
			make $$i; \
		done

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

1:
	$(CC) $(DFLAGS) $(INCLUDES) $(UNITE_TEST) $(LEETCODE)TwoSum.cpp
TwoSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(UNITE_TEST) $(LEETCODE)TwoSum.cpp

2:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddTwoNumbers.cpp 
AddTwoNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddTwoNumbers.cpp 

3:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithoutRepeatingCharacters.cpp
LongestSubstringWithoutRepeatingCharacters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithoutRepeatingCharacters.cpp

4: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MedianOfTwoSortedArrays.cpp NormalData.o RandomData.o
MedianOfTwoSortedArrays: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MedianOfTwoSortedArrays.cpp NormalData.o RandomData.o

5:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestPalindromicSubstring.cpp
LongestPalindromicSubstring:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestPalindromicSubstring.cpp

6:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ZigZagConversion.cpp 
ZigZagConversion:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ZigZagConversion.cpp 

7:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseInteger.cpp 
ReverseInteger:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseInteger.cpp 

8:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StringToInteger.cpp 
StringToInteger:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StringToInteger.cpp 

9:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeNumber.cpp 
PalindromeNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeNumber.cpp 

10:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RegularExpressionMatching.cpp
RegularExpressionMatching:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RegularExpressionMatching.cpp

11: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainerWithMostWater.cpp RandomData.o NormalData.o
ContainerWithMostWater: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainerWithMostWater.cpp RandomData.o NormalData.o

12:
	$(CC) $(DFLAGS) $(LEETCODE)IntegerToRoman.cpp
IntegerToRoman:
	$(CC) $(DFLAGS) $(LEETCODE)IntegerToRoman.cpp

13:
	$(CC) $(DFLAGS) $(LEETCODE)RomanToInteger.cpp
RomanToInteger:
	$(CC) $(DFLAGS) $(LEETCODE)RomanToInteger.cpp

14:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestCommonPrefix.cpp 
LongestCommonPrefix:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestCommonPrefix.cpp 

15:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSum.cpp
ThreeSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSum.cpp

16:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSumClosest.cpp
ThreeSumClosest:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSumClosest.cpp

17:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LetterCombinationsOfAPhoneNumber.cpp
LetterCombinationsOfAPhoneNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LetterCombinationsOfAPhoneNumber.cpp

18: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FourSum.cpp NormalData.o
FourSum: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FourSum.cpp NormalData.o

19: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveNthNodeFromEndOfList.cpp LinkList.o RandomData.o NormalData.o
RemoveNthNodeFromEndOfList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveNthNodeFromEndOfList.cpp LinkList.o RandomData.o NormalData.o

20:
	$(CC) $(DFLAGS) $(LEETCODE)ValidParentheses.cpp
ValidParentheses:
	$(CC) $(DFLAGS) $(LEETCODE)ValidParentheses.cpp

21: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeTwoSortedLists.cpp LinkList.o
MergeTwoSortedLists: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeTwoSortedLists.cpp LinkList.o

22:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GenerateParentheses.cpp
GenerateParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GenerateParentheses.cpp

23: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeKSortedLists.cpp RandomData.o NormalData.o
MergeKSortedLists: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeKSortedLists.cpp RandomData.o NormalData.o

24: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SwapNodesInPairs.cpp LinkList.o
SwapNodesInPairs: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SwapNodesInPairs.cpp LinkList.o

25: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseNodesInKGroup.cpp LinkList.o
ReverseNodesInKGroup: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseNodesInKGroup.cpp LinkList.o

26:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArray.cpp
RemoveDuplicatesFromSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArray.cpp

27:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveElement.cpp 
RemoveElement:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveElement.cpp 

28:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStrStr.cpp
ImplementStrStr:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStrStr.cpp

29:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DivideTwoIntegers.cpp
DivideTwoIntegers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DivideTwoIntegers.cpp

30:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubstringWithConcatenationOfAllWords.cpp
SubstringWithConcatenationOfAllWords:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubstringWithConcatenationOfAllWords.cpp

31: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NextPermutation.cpp NormalData.o
NextPermutation: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NextPermutation.cpp NormalData.o

32:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestValidParentheses.cpp
LongestValidParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestValidParentheses.cpp

33:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArray.cpp
SearchInRotatedSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArray.cpp

34:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchForARange.cpp
SearchForARange:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchForARange.cpp

35:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInsertPosition.cpp
SearchInsertPosition:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInsertPosition.cpp

36:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidSudoku.cpp 
ValidSudoku:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidSudoku.cpp 

37:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SudokuSolver.cpp 
SudokuSolver:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SudokuSolver.cpp 

38:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountAndSay.cpp
CountAndSay:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountAndSay.cpp

39:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSum.cpp
CombinationSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSum.cpp

40:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumII.cpp
CombinationSumII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumII.cpp

41:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstMissingPositive.cpp
FirstMissingPositive:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstMissingPositive.cpp

42: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TrappingRainWater.cpp RandomData.o NormalData.o
TrappingRainWater: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TrappingRainWater.cpp RandomData.o NormalData.o

43:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MultiplyStrings.cpp
MultiplyStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MultiplyStrings.cpp

44:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WildcardMatching.cpp
WildcardMatching:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WildcardMatching.cpp

45:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGameII.cpp
JumpGameII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGameII.cpp

46:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Permutations.cpp
Permutations:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Permutations.cpp

47:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationsII.cpp
PermutationsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationsII.cpp

48: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateImage.cpp RandomData.o NormalData.o
RotateImage: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateImage.cpp RandomData.o NormalData.o

49:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GroupAnagrams.cpp
GroupAnagrams:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GroupAnagrams.cpp

50:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowXN.cpp
PowXN:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowXN.cpp

51: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueens.cpp NormalData.o
NQueens: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueens.cpp NormalData.o

52:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueensII.cpp
NQueensII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NQueensII.cpp

53:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumSubarray.cpp
MaximumSubarray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumSubarray.cpp

54: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrix.cpp NormalData.o
SpiralMatrix: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrix.cpp NormalData.o

55:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGame.cpp
JumpGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)JumpGame.cpp

56:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeIntervals.cpp
MergeIntervals:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeIntervals.cpp

57:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertInterval.cpp
InsertInterval:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertInterval.cpp

58:
	$(CC) $(DFLAGS) $(LEETCODE)LengthOfLastWord.cpp
LengthOfLastWord:
	$(CC) $(DFLAGS) $(LEETCODE)LengthOfLastWord.cpp

59:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrixII.cpp
SpiralMatrixII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SpiralMatrixII.cpp

60:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationSequence.cpp
PermutationSequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PermutationSequence.cpp

61: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateList.cpp LinkList.o
RotateList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RotateList.cpp LinkList.o

62:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePaths.cpp
UniquePaths:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePaths.cpp

63:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePathsII.cpp
UniquePathsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniquePathsII.cpp

64:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumPathSum.cpp
MinimumPathSum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumPathSum.cpp

65:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidNumber.cpp
ValidNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidNumber.cpp

66:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PlusOne.cpp 
PlusOne:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PlusOne.cpp 

67:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddBinary.cpp 
AddBinary:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddBinary.cpp 

68:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TextJustification.cpp
TextJustification:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TextJustification.cpp

69:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SqrtX.cpp
SqrtX:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SqrtX.cpp

70:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClimbingStairs.cpp 
ClimbingStairs:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClimbingStairs.cpp 

71:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SimplifyPath.cpp
SimplifyPath:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SimplifyPath.cpp

72:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EditDistance.cpp
EditDistance:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EditDistance.cpp

73: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SetMatrixZeroes.cpp RandomData.o NormalData.o
SetMatrixZeroes: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SetMatrixZeroes.cpp RandomData.o NormalData.o

74: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrix.cpp RandomData.o NormalData.o
SearchA2DMatrix: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrix.cpp RandomData.o NormalData.o

75:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortColors.cpp
SortColors:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortColors.cpp

76:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumWindowSubstring.cpp
MinimumWindowSubstring:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumWindowSubstring.cpp

77:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Combinations.cpp
Combinations:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Combinations.cpp

78: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Subsets.cpp NormalData.o
Subsets: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Subsets.cpp NormalData.o

79:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearch.cpp
WordSearch:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearch.cpp

80:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArrayII.cpp
RemoveDuplicatesFromSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedArrayII.cpp

81:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArrayII.cpp
SearchInRotatedSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchInRotatedSortedArrayII.cpp

82: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedListII.cpp LinkList.o
RemoveDuplicatesFromSortedListII: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedListII.cpp LinkList.o

83: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedList.cpp LinkList.o
RemoveDuplicatesFromSortedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveDuplicatesFromSortedList.cpp LinkList.o

84: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestRectangleInHistogram.cpp NormalData.o
LargestRectangleInHistogram: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestRectangleInHistogram.cpp NormalData.o

85:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalRectangle.cpp
MaximalRectangle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalRectangle.cpp

86:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PartitionList.cpp
PartitionList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PartitionList.cpp

87:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ScrambleString.cpp
ScrambleString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ScrambleString.cpp

88:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeSortedArray.cpp 
MergeSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MergeSortedArray.cpp 

89:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GrayCode.cpp
GrayCode:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GrayCode.cpp

90: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubsetsII.cpp NormalData.o RandomData.o
SubsetsII: NormalData.o RandomData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SubsetsII.cpp NormalData.o RandomData.o

91:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DecodeWays.cpp
DecodeWays:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DecodeWays.cpp

92: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedListII.cpp LinkList.o
ReverseLinkedListII: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedListII.cpp LinkList.o

93:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RestoreIPAddresses.cpp
RestoreIPAddresses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RestoreIPAddresses.cpp

94: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeInorderTraversal.cpp Tree.o
BinaryTreeInorderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeInorderTraversal.cpp Tree.o

95:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTreesII.cpp
UniqueBinarySearchTreesII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTreesII.cpp

96:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTrees.cpp
UniqueBinarySearchTrees:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueBinarySearchTrees.cpp

97:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InterleavingString.cpp
InterleavingString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InterleavingString.cpp

98: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidateBinarySearchTree.cpp Tree.o
ValidateBinarySearchTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidateBinarySearchTree.cpp Tree.o

99:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RecoverBinarySearchTree.cpp
RecoverBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RecoverBinarySearchTree.cpp

100: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SameTree.cpp Tree.o
SameTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SameTree.cpp Tree.o

101: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SymmetricTree.cpp Tree.o
SymmetricTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SymmetricTree.cpp Tree.o

102: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversal.cpp Tree.o
BinaryTreeLevelOrderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversal.cpp Tree.o

103: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeZigzagLevelOrderTraversal.cpp Tree.o
BinaryTreeZigzagLevelOrderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeZigzagLevelOrderTraversal.cpp Tree.o

104: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumDepthOfBinaryTree.cpp Tree.o
MaximumDepthOfBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumDepthOfBinaryTree.cpp Tree.o

105:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
ConstructBinaryTreeFromPreorderAndInorderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp

106:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
ConstructBinaryTreeFromInorderAndPostorderTraversal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp

107: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversalII.cpp Tree.o
BinaryTreeLevelOrderTraversalII: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeLevelOrderTraversalII.cpp Tree.o

108: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedArrayToBinarySearchTree.cpp Tree.o
ConvertSortedArrayToBinarySearchTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedArrayToBinarySearchTree.cpp Tree.o

109:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedListToBinarySearchTree.cpp
ConvertSortedListToBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ConvertSortedListToBinarySearchTree.cpp

110: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BalancedBinaryTree.cpp Tree.o
BalancedBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BalancedBinaryTree.cpp Tree.o

111: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumDepthOfBinaryTree.cpp Tree.o
MinimumDepthOfBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumDepthOfBinaryTree.cpp Tree.o

112: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSum.cpp Tree.o
PathSum: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSum.cpp Tree.o

113: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSumII.cpp Tree.o
PathSumII: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PathSumII.cpp Tree.o

114:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FlattenBinaryTreeToLinkedList.cpp
FlattenBinaryTreeToLinkedList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FlattenBinaryTreeToLinkedList.cpp

115:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DistinctSubsequences.cpp
DistinctSubsequences:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DistinctSubsequences.cpp

116: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNode.cpp Tree.o
PopulatingNextRightPointersInEachNode: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNode.cpp Tree.o

117: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNodeII.cpp Tree.o
PopulatingNextRightPointersInEachNodeII: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PopulatingNextRightPointersInEachNodeII.cpp Tree.o

118: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle.cpp NormalData.o
PascalsTriangle: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle.cpp NormalData.o

119: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle2.cpp NormalData.o
PascalsTriangle2: NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PascalsTriangle2.cpp NormalData.o

120:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Triangle.cpp
Triangle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Triangle.cpp

121:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStock.cpp
BestTimeToBuyAndSellStock:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStock.cpp

122:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockII.cpp
BestTimeToBuyAndSellStockII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockII.cpp

123:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIII.cpp
BestTimeToBuyAndSellStockIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIII.cpp

124: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeMaximumPathSum.cpp Tree.o
BinaryTreeMaximumPathSum: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeMaximumPathSum.cpp Tree.o

125:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidPalindrome.cpp 
ValidPalindrome:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidPalindrome.cpp 

126:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadderII.cpp
WordLadderII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadderII.cpp

127:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadder.cpp
WordLadder:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordLadder.cpp

128:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestConsecutiveSequence.cpp
LongestConsecutiveSequence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestConsecutiveSequence.cpp

129: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SumRootToLeafNumbers.cpp Tree.o
SumRootToLeafNumbers: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SumRootToLeafNumbers.cpp Tree.o

130:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SurroundedRegions.cpp
SurroundedRegions:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SurroundedRegions.cpp

131:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioning.cpp
PalindromePartitioning:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioning.cpp

132:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioningII.cpp
PalindromePartitioningII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePartitioningII.cpp

133:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CloneGraph.cpp
CloneGraph:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CloneGraph.cpp

134: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GasStation.cpp RandomData.o NormalData.o
GasStation: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GasStation.cpp RandomData.o NormalData.o

135: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Candy.cpp RandomData.o NormalData.o
Candy: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Candy.cpp RandomData.o NormalData.o

136:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumber.cpp
SingleNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumber.cpp

137:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberII.cpp
SingleNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberII.cpp

138: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CopyListWithRandomPointer.cpp LinkList.o
CopyListWithRandomPointer: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CopyListWithRandomPointer.cpp LinkList.o

139:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreak.cpp
WordBreak:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreak.cpp

140:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreakII.cpp
WordBreakII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordBreakII.cpp

141:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycle.cpp 
LinkedListCycle:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycle.cpp 

142: LinkList.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycleII.cpp LinkList.o NormalData.o
LinkedListCycleII: LinkList.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LinkedListCycleII.cpp LinkList.o NormalData.o

143: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReorderList.cpp LinkList.o
ReorderList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReorderList.cpp LinkList.o

144: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePreorderTraversal.cpp Tree.o
BinaryTreePreorderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePreorderTraversal.cpp Tree.o

145: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePostorderTraversal.cpp Tree.o
BinaryTreePostorderTraversal: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePostorderTraversal.cpp Tree.o

146:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LRUCache.cpp
LRUCache:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LRUCache.cpp

147:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertionSortList.cpp
InsertionSortList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InsertionSortList.cpp

148:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortList.cpp
SortList:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SortList.cpp

149:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaxPointsOnALine.cpp
MaxPointsOnALine:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaxPointsOnALine.cpp

150:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EvaluateReversePolishNotation.cpp
EvaluateReversePolishNotation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EvaluateReversePolishNotation.cpp

151:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseWordsInAString.cpp
ReverseWordsInAString:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseWordsInAString.cpp

152:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumProductSubarray.cpp
MaximumProductSubarray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumProductSubarray.cpp

153:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArray.cpp
FindMinimumInRotatedSortedArray:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArray.cpp

154:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArrayII.cpp
FindMinimumInRotatedSortedArrayII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindMinimumInRotatedSortedArrayII.cpp

155:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinStack.cpp 
MinStack:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinStack.cpp 

156:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeUpsideDown.cpp 
BinaryTreeUpsideDown:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeUpsideDown.cpp 
	
157:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReadNCharactersGivenRead4.cpp 
ReadNCharactersGivenRead4:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReadNCharactersGivenRead4.cpp 

158:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReadNCharactersGivenRead4II.cpp 
ReadNCharactersGivenRead4II:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReadNCharactersGivenRead4II.cpp 

159:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithAtMostTwoDistinctCharacters.cpp 
LongestSubstringWithAtMostTwoDistinctCharacters:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LongestSubstringWithAtMostTwoDistinctCharacters.cpp 

160: LinkList.o
	$(CC) $(DFLAGS) $(LEETCODE)IntersectionOfTwoLinkedLists.cpp LinkList.o RandomData.o NormalData.o
IntersectionOfTwoLinkedLists: LinkList.o
	$(CC) $(DFLAGS) $(LEETCODE)IntersectionOfTwoLinkedLists.cpp LinkList.o RandomData.o NormalData.o

161:
	$(CC) $(DFLAGS) $(LEETCODE)OneEditDistance.cpp
OneEditDistance:
	$(CC) $(DFLAGS) $(LEETCODE)OneEditDistance.cpp

162: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindPeakElement.cpp RandomData.o NormalData.o
FindPeakElement: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindPeakElement.cpp RandomData.o NormalData.o

163:
	$(CC) $(DFLAGS) $(LEETCODE)MissingRanges.cpp
MissingRanges:
	$(CC) $(DFLAGS) $(LEETCODE)MissingRanges.cpp

164: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumGap.cpp RandomData.o NormalData.o
MaximumGap: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximumGap.cpp RandomData.o NormalData.o

165:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CompareVersionNumbers.cpp
CompareVersionNumbers:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CompareVersionNumbers.cpp

166:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FractionToRecurringDecimal.cpp
FractionToRecurringDecimal:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FractionToRecurringDecimal.cpp

167:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TwoSumII.cpp
TwoSumII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TwoSumII.cpp

168:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnTitle.cpp
ExcelSheetColumnTitle:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnTitle.cpp

169:
	$(CC) $(DFLAGS) $(LEETCODE)MajorityElement.cpp
MajorityElement:
	$(CC) $(DFLAGS) $(LEETCODE)MajorityElement.cpp

170:
	$(CC) $(DFLAGS) $(LEETCODE)TwoSumIII.cpp
TwoSumIII:
	$(CC) $(DFLAGS) $(LEETCODE)TwoSumIII.cpp

171:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnNumber.cpp
ExcelSheetColumnNumber:
	$(CC) $(DFLAGS) $(LEETCODE)ExcelSheetColumnNumber.cpp

172:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FactorialTrailingZeroes.cpp
FactorialTrailingZeroes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FactorialTrailingZeroes.cpp

173:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinarySearchTreeIterator.cpp
BinarySearchTreeIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinarySearchTreeIterator.cpp

174:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DungeonGame.cpp
DungeonGame:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DungeonGame.cpp

175:
	echo "No 175"

176:
	echo "No 176"

177:
	echo "No 177"

178:
	echo "No 178"

179:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestNumber.cpp
LargestNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LargestNumber.cpp

180:
	echo "No 180"

181:
	echo "No 181"

182:
	echo "No 182"

183:
	echo "No 183"

184:
	echo "No 184"

185:
	echo "No 185"

186:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseWordsInAStringII.cpp
ReverseWordsInAStringII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseWordsInAStringII.cpp

187:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RepeatedDNASequences.cpp
RepeatedDNASequences:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RepeatedDNASequences.cpp

188:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIV.cpp
BestTimeToBuyAndSellStockIV:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BestTimeToBuyAndSellStockIV.cpp

189: RandomData.o
	$(CC) $(DFLAGS) $(LEETCODE)RotateArray.cpp RandomData.o NormalData.o
RotateArray: RandomData.o
	$(CC) $(DFLAGS) $(LEETCODE)RotateArray.cpp RandomData.o NormalData.o

190:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseBits.cpp
ReverseBits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseBits.cpp

191:
	$(CC) $(DFLAGS) $(LEETCODE)NumberOf1Bits.cpp
NumberOf1Bits:
	$(CC) $(DFLAGS) $(LEETCODE)NumberOf1Bits.cpp

192:
	echo "No 192"

193:
	echo "No 193"

194:
	echo "No 194"

195:
	echo "No 195"

196:
	echo "No 196"

197:
	echo "No 197"

198:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobber.cpp 
HouseRobber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobber.cpp 

199: Tree.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeRightSideView.cpp Tree.o NormalData.o
BinaryTreeRightSideView: Tree.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreeRightSideView.cpp Tree.o NormalData.o

200:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfIslands.cpp
NumberOfIslands:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfIslands.cpp

201:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BitwiseAndOfNumbersRange.cpp
BitwiseAndOfNumbersRange:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BitwiseAndOfNumbersRange.cpp

202:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HappyNumber.cpp 
HappyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HappyNumber.cpp 

203: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveLinkedListElements.cpp LinkList.o
RemoveLinkedListElements: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RemoveLinkedListElements.cpp LinkList.o

204:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountPrimes.cpp
CountPrimes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountPrimes.cpp

205:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IsomorphicStrings.cpp
IsomorphicStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IsomorphicStrings.cpp

206: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedList.cpp LinkList.o
ReverseLinkedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ReverseLinkedList.cpp LinkList.o

207:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseSchedule.cpp
CourseSchedule:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseSchedule.cpp

208:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementTrie.cpp
ImplementTrie:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementTrie.cpp

209:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumSizeSubarraySum.cpp
MinimumSizeSubarraySum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MinimumSizeSubarraySum.cpp

210:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseScheduleII.cpp
CourseScheduleII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CourseScheduleII.cpp

211:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddAndSearchWord.cpp
AddAndSearchWord:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddAndSearchWord.cpp

212:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearchII.cpp
WordSearchII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordSearchII.cpp

213: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobberII.cpp RandomData.o NormalData.o
HouseRobberII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HouseRobberII.cpp RandomData.o NormalData.o

214:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestPalindrome.cpp
ShortestPalindrome:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestPalindrome.cpp

215: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthLargestElementInAnArray.cpp RandomData.o NormalData.o
KthLargestElementInAnArray: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthLargestElementInAnArray.cpp RandomData.o NormalData.o

216:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumIII.cpp
CombinationSumIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CombinationSumIII.cpp

217:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicate.cpp
ContainsDuplicate:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicate.cpp

218:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TheSkylineProblem.cpp
TheSkylineProblem:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)TheSkylineProblem.cpp

219:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateII.cpp
ContainsDuplicateII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateII.cpp

220:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateIII.cpp
ContainsDuplicateIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ContainsDuplicateIII.cpp

221:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalSquare.cpp
MaximalSquare:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MaximalSquare.cpp

222:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountCompleteTreeNodes.cpp
CountCompleteTreeNodes:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountCompleteTreeNodes.cpp

223:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RectangleArea.cpp
RectangleArea:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)RectangleArea.cpp

224:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculator.cpp
BasicCalculator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculator.cpp

225:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStackUsingQueues.cpp
ImplementStackUsingQueues:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementStackUsingQueues.cpp

226: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InvertBinaryTree.cpp Tree.o
InvertBinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InvertBinaryTree.cpp Tree.o

227:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculatorII.cpp
BasicCalculatorII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BasicCalculatorII.cpp

228:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SummaryRanges.cpp
SummaryRanges:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SummaryRanges.cpp

229: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MajorityElementII.cpp RandomData.o NormalData.o
MajorityElementII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MajorityElementII.cpp RandomData.o NormalData.o

230: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthSmallestElementInABST.cpp Tree.o
KthSmallestElementInABST: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)KthSmallestElementInABST.cpp Tree.o

231:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowerOfTwo.cpp
PowerOfTwo:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PowerOfTwo.cpp

232:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementQueueUsingStacks.cpp
ImplementQueueUsingStacks:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ImplementQueueUsingStacks.cpp

233:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfDigitOne.cpp
NumberOfDigitOne:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)NumberOfDigitOne.cpp

234: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeLinkedList.cpp RandomData.o NormalData.o
PalindromeLinkedList: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromeLinkedList.cpp RandomData.o NormalData.o

235: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinarySearchTree.cpp Tree.o
LowestCommonAncestorOfABinarySearchTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinarySearchTree.cpp Tree.o

236: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinaryTree.cpp Tree.o
LowestCommonAncestorOfABinaryTree: Tree.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)LowestCommonAncestorOfABinaryTree.cpp Tree.o

237: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DeleteNodeInALinkedList.cpp LinkList.o
DeleteNodeInALinkedList: LinkList.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DeleteNodeInALinkedList.cpp LinkList.o

238:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ProductOfArrayExceptSelf.cpp
ProductOfArrayExceptSelf:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ProductOfArrayExceptSelf.cpp

239:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SlidingWindowMaximum.cpp
SlidingWindowMaximum:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SlidingWindowMaximum.cpp

240: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrixII.cpp RandomData.o NormalData.o
SearchA2DMatrixII: RandomData.o NormalData.o
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SearchA2DMatrixII.cpp RandomData.o NormalData.o

Anagrams:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Anagrams.cpp

241:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DifferentWaysToAddParentheses.cpp
DifferentWaysToAddParentheses:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)DifferentWaysToAddParentheses.cpp

242:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidAnagram.cpp
ValidAnagram:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ValidAnagram.cpp

243:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistance.cpp
ShortestWordDistance:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistance.cpp

244:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistanceII.cpp
ShortestWordDistanceII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistanceII.cpp

245:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistanceIII.cpp
ShortestWordDistanceIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ShortestWordDistanceIII.cpp

246:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumber.cpp
StrobogrammaticNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumber.cpp

247:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumberII.cpp
StrobogrammaticNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumberII.cpp

248:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumberIII.cpp
StrobogrammaticNumberIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)StrobogrammaticNumberIII.cpp

249:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GroupShiftedStrings.cpp
GroupShiftedStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GroupShiftedStrings.cpp

250:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountUnivalueSubtrees.cpp
CountUnivalueSubtrees:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)CountUnivalueSubtrees.cpp

251:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Flatten2DVector.cpp
Flatten2DVector:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)Flatten2DVector.cpp

252:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MeetingRooms.cpp
MeetingRooms:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MeetingRooms.cpp

253:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MeetingRoomsII.cpp
MeetingRoomsII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MeetingRoomsII.cpp

254:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FactorCombinations.cpp
FactorCombinations:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FactorCombinations.cpp

255:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)VerifyPreOrderSequenceInBinarySearchTree.cpp
VerifyPreOrderSequenceInBinarySearchTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)VerifyPreOrderSequenceInBinarySearchTree.cpp

256:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintHouse.cpp
PaintHouse:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintHouse.cpp

257:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePaths.cpp
BinaryTreePaths:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)BinaryTreePaths.cpp

258:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddDigits.cpp
AddDigits:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AddDigits.cpp
	
259:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSumSmaller.cpp
ThreeSumSmaller:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ThreeSumSmaller.cpp
	
260:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberIII.cpp
SingleNumberIII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)SingleNumberIII.cpp

261:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GraphValidTree.cpp
GraphValidTree:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GraphValidTree.cpp

263:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumber.cpp
UglyNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumber.cpp

264:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumberII.cpp
UglyNumberII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UglyNumberII.cpp

265:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintHouseII.cpp
PaintHouseII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintHouseII.cpp

266:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePermutation.cpp
PalindromePermutation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePermutation.cpp

267:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePermutationII.cpp
PalindromePermutationII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PalindromePermutationII.cpp

268:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MissingNumber.cpp
MissingNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MissingNumber.cpp

269:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AlienDictonary.cpp
AlienDictonary:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)AlienDictonary.cpp

270:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClosestBinarySearchTreeValue.cpp
ClosestBinarySearchTreeValue:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClosestBinarySearchTreeValue.cpp

271:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EncodeAndDecodeStrings.cpp
EncodeAndDecodeStrings:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)EncodeAndDecodeStrings.cpp

272:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClosestBinarySearchTreeValueII.cpp
ClosestBinarySearchTreeValueII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ClosestBinarySearchTreeValueII.cpp

273:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IntegerToEnglishWords.cpp
IntegerToEnglishWords:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)IntegerToEnglishWords.cpp

274:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HIndex.cpp
HIndex:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HIndex.cpp

275:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HIndexII.cpp
HIndexII:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)HIndexII.cpp

276:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintFence.cpp
PaintFence:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PaintFence.cpp

277:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindTheCelebrity.cpp
FindTheCelebrity:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindTheCelebrity.cpp

278:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstBadVersion.cpp
FirstBadVersion:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FirstBadVersion.cpp

279:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PerfectSquares.cpp
PerfectSquares:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PerfectSquares.cpp

280:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WiggleSort.cpp
WiggleSort:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WiggleSort.cpp

281:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ZigzagIterator.cpp
ZigzagIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ZigzagIterator.cpp

282:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ExpressionAddOperators.cpp
ExpressionAddOperators:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)ExpressionAddOperators.cpp

283:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MoveZeros.cpp
MoveZeros:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)MoveZeros.cpp

284:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PeekingIterator.cpp
PeekingIterator:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)PeekingIterator.cpp

285:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InorderSuccessorInBST.cpp
InorderSuccessorInBST:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)InorderSuccessorInBST.cpp

286:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WallsAndGates.cpp
WallsAndGates:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WallsAndGates.cpp

287:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindTheDuplicateNumber.cpp
FindTheDuplicateNumber:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)FindTheDuplicateNumber.cpp

288:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueWordAbbreviation.cpp
UniqueWordAbbreviation:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)UniqueWordAbbreviation.cpp

289:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GameOfLife.cpp
GameOfLife:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)GameOfLife.cpp

290:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordPattern.cpp
WordPattern:
	$(CC) $(DFLAGS) $(INCLUDES) $(LEETCODE)WordPattern.cpp

test:
	echo "test test!!"

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
