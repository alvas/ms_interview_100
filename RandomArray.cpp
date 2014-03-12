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

void printArray(int A[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << A[i] << "\t";

        if (i % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }

    cout << endl;
}
