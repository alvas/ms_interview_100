#include <cassert>
#include <iostream>
#include "InsertionSort.h"
#include "RandomArray.h"

using namespace std;

void InsertionSort(int A[], int size)
{
    InsertionSort(A, 0, size - 1);
}

// I: p start index
//    r end index
void InsertionSort(int A[], int p, int r)
{
    assert(p >= 0 && p <= r);

    // !! be careful !! loop from p to r
    for (int j = p; j <= r; ++j)
    {
        int key = A[j];
        int i = j - 1;

        // !! be careful!! i should be not smaller than p(the start index), not 0
        while (i >= p && A[i] > key)
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

#ifndef EXPORTED
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
