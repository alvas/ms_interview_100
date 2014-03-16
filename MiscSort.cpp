#include <iostream>
#include "RandomArray.h"

using namespace std;

void CountingSort(int A[], int B[], int size, int k)
{
    // variable size array, which is support after C99
    // it doesn't support initialization at the same time of definition
    int C[k];

    for (int i = 0; i < k; ++i)
    {
        C[i] = 0;
    }

    for (int i = 0; i < size; ++i)
    {
        C[A[i]] = C[A[i]] + 1;
    }

    for (int i = 0; i < k; ++i)
    {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = size - 1; i >= 0; --i)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

#ifndef MAIN
int main()
{
    int A[LENGTH] = {0};
    int B[LENGTH] = {0};
    initializeArray(A, LENGTH);
    printArray(A, LENGTH);
    CountingSort(A, B, LENGTH, MAXNUM);
    printArray(B, LENGTH);
    return 0;
}
#endif
