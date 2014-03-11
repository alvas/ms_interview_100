#include <iostream>
#include <cstdlib>
#include "RandomArray.h"

using namespace std;

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

        if (i % 10 == 9)
        {
            cout << endl;
        }
    }

    cout << endl;
}
