#include <iostream>
#include "QuickSort.h"

using namespace std;

#define LENGTH 21
#define I 7

static int A[] = {33, 26, 55, 78, 1, 28, 22, 94, 25, 35, 7, 16, 59, 98, 23, 34, 86, 61, 29, 13, 73};

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

int main()
{
    cout << RandomizedSelect(A, 0, LENGTH - 1, I) << endl;
    return 0;
}
