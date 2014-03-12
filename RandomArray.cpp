#include <iostream>
#include <cstdlib>
#include "RandomArray.h"

using namespace std;

const int COLUMNS = 5;

// I: length the size of the array to be initialized
void initializeArray(int A[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        A[i] = rand() % MAXNUM;
    }
}

void printArray(int A[], int p, int r)
{
    int column = 0;

    for (int i = p; i <= r; ++i)
    {
        cout << A[i] << "\t";

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }

    cout << endl;
}

void printArray(int A[], int size)
{
    printArray(A, 0, size - 1);
}
