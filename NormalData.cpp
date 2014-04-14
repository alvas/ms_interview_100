#include <iostream>
#include "NormalData.h"

void initializeIndexVector(vector<int> &v, const int size)
{
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
}

