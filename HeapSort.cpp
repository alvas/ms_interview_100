#include <iostream>

using namespace std;

#define HeapSize 10

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
    printHeapArray(A, HeapSize);
    BuildMaxHeap(A, HeapSize);
    printHeapArray(A, HeapSize);
    return 0;
}
