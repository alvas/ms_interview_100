#include <iostream>
#include "NormalData.h"

void initializeIndexVector(vector<int> &v, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << i << "\t";
        v.push_back(i);
    }

    cout << endl;
}

