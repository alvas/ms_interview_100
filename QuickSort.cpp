#include <iostream>
#include "RandomArray.h"
#include "QuickSort.h"

using namespace std;

// O: index of the pivot x
int Partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;

    // !!Be careful!! We need to process r - 1 also. Range from p to r - 1.
    for (int j = p; j < r; ++j)
    {
        if (A[j] <= x)
        {
            // j is the index where A[j] is smaller than pivot x

            // after i advances, i is smallest index where A[i] is bigger than pivot x
            // so after exchanging A[i] and A[j], the member between A[i+1] and A[j] would
            // be all bigger than pivot x
            ++i;

            // A[i] <-> A[j]
            int local = A[i];
            A[i] = A[j];
            A[j] = local;
        }
    }

    // A[i + 1] <-> A[r]
    int tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;

    return (i + 1);
}

int RandomizedPartition(int A[], int p, int r)
{
    // !! Watch out!! The index i should be in the range of [p, r], so we need to add p behind.
    int i = rand() % (r - p) + p;

    // A[r] <-> A[i]
    int tmp = A[r];
    A[r] = A[i];
    A[i] = tmp;

    return Partition(A, p, r);
}

void QuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

void RandomizedQuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = RandomizedPartition(A, p, r);
        RandomizedQuickSort(A, p, q - 1);
        RandomizedQuickSort(A, q + 1, r);
    }
}

#ifndef EXPORTED
int main()
{
    int A[LENGTH] = {0};

    cout << "The original array is:" << endl;
    initializeArray(A, LENGTH);
    printArray(A, LENGTH);

//    QuickSort(A, 0, LENGTH - 1);
    RandomizedQuickSort(A, 0, LENGTH - 1);

    cout << "The array after quick sort is:" << endl;
    printArray(A, LENGTH);

    return 0;
}
#endif
