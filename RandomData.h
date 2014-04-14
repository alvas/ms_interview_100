#include <vector>
#include "NormalData.h"

using namespace std;

// I: length the size of the array
void initializeArray(int A[], int length);
void initializeVector(vector<int> &v, int length);
void initializeRandomIndexVector(vector<int> &v, const int size);
void initializeStringArray(char S[], int length);
void printArray(int A[], int size);
void printArray(int A[], int p, int r);

// Template function must be in the calling site or header file,
// otherwise it would not compile.
// T must be a container type.
template<class T>
void printVector(const T &v)
{
    int column = 0;

    for (class T::const_iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        cout << *itr << "\t";

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }

    cout << endl;
}

void printStringArray(char S[], int length);
