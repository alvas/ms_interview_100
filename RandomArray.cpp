#include <iostream>
#include <cstdlib>
#include "RandomArray.h"

using namespace std;

// I: length the size of the array to be initialized
void initializeArray(int A[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        A[i] = rand() % MAXNUM;
    }
}

void initializeStringArray(char S[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        S[i] = 'A' + rand() % ALPHABET;
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

void printArray(int A[], int length)
{
    printArray(A, 0, length - 1);
}

void printStringArray(char S[], int length)
{
    int column = 0;

    for (int i = 0; i < length; ++i)
    {
        cout << S[i];

        if (column++ % CHARCOLUMNS == CHARCOLUMNS - 1)
        {
            cout << endl << endl;
        }
    }

    cout << endl;
}
