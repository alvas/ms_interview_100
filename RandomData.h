#include <vector>
#include "NormalData.h"

using namespace std;

// I: length the size of the array
void initializeArray(int A[], int length);
void initializeRandomVector(vector<int> &v, int length);
void initializeRandomIndexVector(vector<int> &v, const int size);
void initializeRandomStringArray(char S[], int length);
void initializeRandomString(string &S, int length);
void printStringArray(char S[], int length);

template<typename T>
void printArray(T A[], int p, int r)
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

template<typename T>
void printArray(T A[], int length)
{
    printArray(A, 0, length - 1);
}

