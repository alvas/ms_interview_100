#include <iostream>
#include "InsertionSort.h"
#include "RandomArray.h"
#include "QuickSort.h"

using namespace std;

#define I 49

// I: p start index
//    r end index
//    i the ith rank element in the array
//    
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
        cerr << "The start index is bigger than the end index!" << endl;
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
        InsertionSort(A, j * 5, j * 5 + 4);
        medians[numMedian++] = A[j * 5 + 2];
    }

    if (numRemain != 0)
    {
        medians[numMedian] = A[numGroup * 5 + numRemain / 2 - 1];
        numMedian++;
    }

    if (numMedian == 0)
    {
        return medians[0];
    }
    else
    {
        return median(medians, 0, numMedian - 1);
    }
}

int medianIndex(int A[], int p, int r, int median)
{
    if (p > r)
    {
        cerr << "The start index is bigger than the end index!" << endl;
        exit(-1);
    }

    int size = r - p + 1;

    for (int i = 0; i < size; ++i)
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

    int k = Partition(A, p, r);

    if (k == i)
    {
        return A[i];
    }
    else if (i < k)
    {
        return Select(A, p, k - 1, i);
    }
    else if (i > k)
    {
        return Select(A, k + 1, r, i - k);
    }
}

#ifdef MAIN
int main()
{
    int A[LENGTH];
    initializeArray(A, LENGTH);
    printArray(A, LENGTH);
    cout << RandomizedSelect(A, 0, LENGTH - 1, I) << endl;
    int med = median(A, 0, LENGTH - 1);
    int index = medianIndex(A, 0, LENGTH - 1, med);
    cout << "median = " << med << "; index = " << index << endl;
//    cout << Select(A, 0, LENGTH - 1, I) << endl;
    RandomizedQuickSort(A, 0, LENGTH - 1);
    printArray(A, LENGTH);
    return 0;
}
#endif
