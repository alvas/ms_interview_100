#include <algorithm>
#include <iostream>
#include "RandomData.h"

using namespace std;

const int SIZE = 100;

void Merge(vector<int>::iterator itr, const vector<int> &part1, const vector<int> &part2)
{
    vector<int>::const_iterator itr1 = part1.begin();
    vector<int>::const_iterator itr2 = part2.begin();

    while (itr1 != part1.end() && itr2 != part2.end())
    {
        if (*itr1 < *itr2)
        {
            *itr++ = *itr1++;
        }
        else
        {
            *itr++ = *itr2++;
        }
    }

    while (itr1 != part1.end())
    {
        *itr++ = *itr1++;
    }

    while (itr2 != part2.end())
    {
        *itr++ = *itr2++;
    }
}

void MergeSort(vector<int> &v)
{
    if (v.size() <= 1)
    {
        return;
    }

    vector<int>::iterator middle = v.begin() + (v.end() - v.begin()) / 2;
    vector<int> part1(v.begin(), middle);
    vector<int> part2(middle, v.end());

    MergeSort(part1);
    MergeSort(part2);
    Merge(v.begin(), part1, part2);
    return;
}

// Because we pass v.begin() and v.end() to this function, we can't
// declara the parameter of these two iterators as references.
void MergeSort(vector<int>::iterator first, vector<int>::iterator last)
{
    // !!WATCH OUT!! We need to check last is at least one after first.
    // Otherwise, first equals to last, then MergeSort would get into
    // infinte recursion when MergeSort(first, first).
    if (first + 1 >= last)
    {
        return;
    }

    vector<int>::iterator middle = first + (last - first) / 2;

    MergeSort(first, middle);
    MergeSort(middle, last);
    inplace_merge(first, middle, last);
    return;
}

#ifndef EXPORTED
int main()
{
    vector<int> v;
    initializeVector(v, SIZE);
    printVector(v);
//    MergeSort(v);
    MergeSort(v.begin(), v.end());
    printVector(v);
    return 0;
}
#endif
