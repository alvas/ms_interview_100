#include <iostream>
#include "InsertionSort.h"
#include "RandomData.h"
#include "QuickSort.h"

using namespace std;

#define I 39

// I: p start index
//    r end index
//    i the ith rank element in the array
int RandomizedSelect(int A[], int p, int r, int i)
{
    if (p == r)
    {
        return A[p];
    }

    int q = RandomizedPartition(A, p, r);
    int k = q - p + 1;

    if (i == k)
    {
        return A[q];
    }
    else if (i < k)
    {
        return RandomizedSelect(A, p, q - 1, i);
    }
    else
    {
        return RandomizedSelect(A, q + 1, r, i - k);
    }
}

// find the element in the median position
// I: p start index
//    r end index
int median(int A[], int p, int r)
{
    if (p > r)
    {
        cerr << "median(): The start index " << p << " is bigger than the end index " << r << "!" << endl;
        exit(-1);
    }
    else if (p == r)
    {
        return A[p];
    }

    int size = r - p + 1;

    int numGroup = size / 5;
    int numRemain = size % 5;
    int medians[LENGTH] = {0};

    int numMedian = 0;

    for (int j = 0; j < numGroup; ++j)
    {
        // !! REMEMBER the index of the array starts from p!!
        InsertionSort(A, p + j * 5, p + j * 5 + 4);
        medians[numMedian++] = A[p + j * 5 + 2];
    }

    if (numRemain != 0)
    {
        // !! REMEMBER the index of the array starts from p!!
        InsertionSort(A, p + numGroup * 5, p + numGroup * 5 + numRemain - 1);
        medians[numMedian++] = A[p + numGroup * 5 + numRemain / 2];
    }
    
    if (numMedian == 1)
    {
        return medians[0];
    }
    else
    {
        // The start index of medians here is 0.
        return median(medians, 0, numMedian - 1);
    }
}

int medianIndex(int A[], int p, int r, int median)
{
    if (p > r)
    {
        cerr << "medianIndex(): The start index " << p << " is bigger than the end index " << r << "!" << endl;
        exit(-1);
    }

    // !!REMEMBER the start index!!
    for (int i = p; i <= r; ++i)
    {
        if (A[i] == median)
        {
            return i;
        }
    }
    
    return -1;
}

// I: p start index
//    r end index
//    i the ith rank element in the array
int Select(int A[], int p, int r, int i)
{
    int med = median(A, p, r);
    int medIdx = medianIndex(A, p, r, med);

    int tmp = A[r];
    A[r] = A[medIdx];
    A[medIdx] = tmp;

    // medIdx is the index of the pivot
    medIdx = Partition(A, p, r);
    // pivot is the kth element in the array
    int k = medIdx - p + 1;

    if (k == i)
    {
        // if k is excatly the ith element we want to find,
        // return the element under the pivot index A[medIdx]
        return A[medIdx];
    }
    else if (i < k)
    {
        // i is smaller than k, then we recursively select it
        // from the array before the pivot index
        return Select(A, p, medIdx - 1, i);
    }
    else
    {
        // i is bigger than k, the we recursively select it
        // from the array after the pivot index as the (i-k)th element
        return Select(A, medIdx + 1, r, i - k);
    }
}

#ifdef EXPORTED
int main()
{
    int A[LENGTH];
    initializeArray(A, LENGTH);
    printArray(A, LENGTH);
//    cout << RandomizedSelect(A, 0, LENGTH - 1, I) << endl;
    cout << Select(A, 0, LENGTH - 1, I) << endl;
    RandomizedQuickSort(A, 0, LENGTH - 1);
    printArray(A, LENGTH);
    return 0;
}
#endif
