#include <iostream>
#include "RandomArray.h"

using namespace std;

const int HEAPSIZE = 10;

// the first element A[0] of the heap array is not used.
static int A[11] = {0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

static void printHeapArray(int A[], int length);

int Parent(int i)
{
    return i/2;
}

int Left(int i)
{
    return 2 * i;
}

int Right(int i)
{
    return 2 * i + 1;
}

void MaxHeapify(int A[], int size, int i)
{
    int l = Left(i);
    int r = Right(i);
    int largest = 0;

    if (l <= size && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    // !! Be careful !! A[r] is comparing with A[largest].
    if (r <= size && A[r] > A[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        MaxHeapify(A, size, largest);
    }
}

void BuildMaxHeap(int A[], int size)
{
    for (int i = size / 2; i > 0; --i)
    {
        MaxHeapify(A, size, i);
    }
}

void HeapSort(int A[], int size)
{
    BuildMaxHeap(A, size);

    for (int i = size; i >= 2; --i)
    {
        int tmp = A[1];
        A[1] = A[i];
        A[i] = tmp;
        size = size - 1;
        MaxHeapify(A, size, 1);
    }
}

int HeapMaximum(int A[], int size = HEAPSIZE)
{
    if (size < 1)
    {
        cerr << "The size of the heap is smaller than 1!" << endl;
        exit(-1);
    }

    return A[1];
}

// I:
//    size of the array is a reference because it would reduce the size by one
int HeapExtractMax(int A[], int &size)
{
    if (size < 1)
    {
        cerr << "The size of the heap is smaller than 1!" << endl;
        exit(-1);
    }

    int max = A[1];
    A[1] = A[size];
    size = size - 1;
    MaxHeapify(A, size, 1);
    return max;
}

void HeapIncreaseKey(int A[], int i, int key)
{
    if (key < A[i])
    {
        cerr << "new key is smaller than current key" << endl;
        exit(-1);
    }
    // If the key equals to A[i], do nothing.
    else if (key == A[i])
    {
        return;
    }

    A[i] = key;

    while (i > 1 && A[Parent(i)] < A[i])
    {
        int tmp = A[i];
        A[i] = A[Parent(i)];
        A[Parent(i)] = tmp;
        i = Parent(i);
    }
}

// I:
//    size of the array is a reference because it would increase the size by on
void MaxHeapInsert(int A[], int &size, int key)
{
    size = size + 1;
    A[size] = key;
    HeapIncreaseKey(A, size, key);
}

static void printHeapArray(int A[], int length)
{
    cout << "Heap array is:" << endl;

    for (int i = 1; i <= length; ++i)
    {
        cout << A[i] << "\t";

        if (i % 10 == 0)
        {
            cout << endl;
        }
    }

    cout << endl;
}

int main()
{
    printHeapArray(A, HEAPSIZE);
    BuildMaxHeap(A, HEAPSIZE);
    printHeapArray(A, HEAPSIZE);
//    HeapSort(A, HEAPSIZE);
    int size = HEAPSIZE;
    cout << "The maximum of the heap is " << HeapExtractMax(A, size) << endl;
    printHeapArray(A, size);
    return 0;
}
