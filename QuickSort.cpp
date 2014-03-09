#include <iostream>
#include <cstdlib>

using namespace std;

#define LENGTH 100
#define MAXNUM 5000

int Partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r - 1; ++j)
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

    return (i+1);
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

static void initializeArray(int A[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        A[i] = rand() % MAXNUM;
    }
}

static void printArray(int A[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << A[i] << "\t";

        if (i % 10 == 9)
        {
            cout << endl;
        }
    }

    cout << endl;
}

int main()
{
    int A[LENGTH] = {0};

    cout << "The original array is:" << endl;
    initializeArray(A, LENGTH);
    printArray(A, LENGTH);

    QuickSort(A, 0, LENGTH - 1);

    cout << "The array after quick sort is:" << endl;
    printArray(A, LENGTH);

    return 0;
}
