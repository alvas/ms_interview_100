#include <algorithm>
#include <iostream>
#include "NormalData.h"

struct c_unique
{
    int current;
    c_unique() { current = 0; }
    int operator ()() { return current++; }
} UniqueNumber;

void initializeIndexVector(vector<int> &v, const int size)
{
#if 0
    int column = 0;

    for (int i = 0; i < size; ++i)
    {
        v.push_back(i);
        cout << i << "\t";

        if (column++ % COLUMNS == COLUMNS - 1)
        {
            cout << endl;
        }
    }

    cout << endl;
#endif
    v.resize(size);
    generate(v.begin(), v.end(), UniqueNumber);
}

