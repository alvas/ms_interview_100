#include <iostream>
#include "RandomArray.h"

using namespace std;

void InsertionSort(int A[], int size)
{
    // loop from 1 to size - 1
    for (int j = 1; j < size; ++j)
    {
        int key = A[j];
        int i = j - 1;

        while (i >= 0 && A[i] > key)
        {
            // !! assign A[i] to A[i+1]
            A[i + 1] = A[i];
            i--;
        }

        // A[i+1] is the last member who is bigger than key and moved afterward.
        // Or A[i+1] is A[0].
        A[i + 1] = key;
    }
}

void InsertionSort(int A[], int p, int r)
{
    if (p > r)
    {
        cerr << "The start index is smaller than the end index!" << endl;
        exit(-1);
    }

    int size = r - p + 1;
    InsertionSort(A, size);
}

#ifndef MAIN
int main()
{
    int A[LENGTH] = {0};
    initializeArray(A, LENGTH);
    printArray(A, LENGTH);
    InsertionSort(A, LENGTH);
    printArray(A, LENGTH);
    return 0;
}
#endif
