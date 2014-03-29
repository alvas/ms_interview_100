#include <cassert>
#include <iostream>
#include "QuickSort.h"
#include "RandomArray.h"

using namespace std;

int binarySearchRecursive(int A[], int p, int r, int x)
{
    assert(p >= 0 && p <= r);

    if (p > r)
    {
        cerr << "start index is bigger than end index!" << endl;
        exit(-1);
    }

    if (p == r)
    {
        if (A[p] == x)
        {
            return p;
        }
        else
        {
            return -1;
        }
    }

    int mid = p + (r - p) / 2;
    cout << "mid = " << mid << ": p = " << p << "; r = " << r << endl;

    if (A[mid] == x)
    {
        return mid;
    }
    // if mid is equsl to p or r now, but A[mid] is not
    // equal to x, then there is no such x
    else if (mid == p || mid == r)
    {
        return -1;
    }
    else if (A[mid] < x)
    {
        // !!IMPORTANT!! mid could be equal to r, then mid + 1 would be out of bound
        return binarySearchRecursive(A, mid + 1, r, x);
    }
    else
    {
        // !!IMPORTANT!!  mid could be equal to p, then mid - 1 would be out of bound
        return binarySearchRecursive(A, p, mid - 1, x);
    }
}

int binarySearch(int A[], int p, int length, int x)
{
    assert(p >= 0 && length >= 0);

    if (p < 0 || length < 0)
    {
        cerr << "The start index of and the length the array could not be negative!" << endl;
        exit(-1);
    }

    if (length == 0)
    {
        return -1;
    }

    int r = p + length - 1;

    while (p <= r)
    {
        int mid = p + (r - p) / 2;

        if (A[mid] < x)
        {
            p = mid + 1;
        }
        else if (A[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

#ifndef EXPORTED
int main()
{
    int A[LENGTH] = {0};
    initializeArray(A, LENGTH);
    QuickSort(A, 0, LENGTH - 1);
    printArray(A, LENGTH);
    int index = binarySearch(A, 0, LENGTH - 1, 1153);
    cout << index << endl;
    return 0;
}
#endif
