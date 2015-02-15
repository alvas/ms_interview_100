#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

const int NUM = 50;

int binarySearch(const vector<int> &v, int t, int l, int u)
{
    if (l >= u || l < 0 || u > v.size())
    {
        return -1;
    }

    int m = (l + u) / 2;

    if (v[m] == t)
    {
        return m;
    }
    else if (v[m] > t)
    {
        // !! Remember to return from here.
        return binarySearch(v, t, l, m);
    }
    else
    {
        // !! Remember to return from here.
        return binarySearch(v, t, m + 1, u);
    }
}

int binarySearch2(const vector<int> &v, int t, int l, int u)
{
    if (l >= u || l < 0 || u > v.size())
    {
        return -1;
    }

    int index = -1;

    while (l < u)
    {
        // Use l + (u - l) / 2 to prevent overflow
        int m = l + ((u - l) >> 1);

        if (v[m] == t)
        {
            index = m;
            break;
        }
        else if (v[m] < t)
        {
            // Don't use recurvsive.
            l = m + 1;
        }
        else
        {
            // Don't use recurvsive.
            u = m;
        }
    }

    return index;
}

int binarySearchFirst(const vector<int> &v, int t, int l, int u)
{
    if (l >= u || l < 0 || u > v.size())
    {
        return -1;
    }

    int index = binarySearch2(v, t, l, u);

    if (index == -1)
    {
        // Can't find t in vectro v.
        // leave blank intentionally, index == -1
    }
    else if (index == 0)
    {
        // t is the first element in vector.
        index = 0;
    }
    else if (v[index - 1] != t)
    {
        // v[index] is the first t in vector.
        // leave blank intentionally, index == index
    }
    else
    {
        int index2 = binarySearch2(v, t, l, index);

        while (index2 != -1)
        {
            index = index2;
            index2 = binarySearch(v, t, l, index);
        }
    }

    return index;
}

int binarySearchLast(const vector<int> &v, int t, int l, int u)
{
    if (l >= u || l < 0 || u > v.size())
    {
        return -1;
    }

    int index = binarySearch2(v, t, l, u);

    if (index == -1)
    {
        // Can't find t in vectro v.
        // leave blank intentionally, index == -1
    }
    else if (index == u - 1)
    {
        // t is the first element in vector.
        index = u - 1;
    }
    else if (v[index + 1] != t)
    {
        // v[index] is the last in vector.
        // leave blank intentionally, index == index
    }
    else
    {
        int index2 = binarySearch2(v, t, index + 1, u);

        while (index2 != -1)
        {
            index = index2;
            index2 = binarySearch(v, t, index + 1, u);
        }
    }

    return index;
}

int binarySearchUpperBound(const vector<int> &v, int t, int l, int u)
{
    if (l >= u || l < 0 || u > v.size())
    {
        return -1;
    }

    int index = binarySearchLast(v, t, l, u);

    if (index == -1)
    {
        // Can't find t in vectro v.
        // leave blank intentionally, index == -1
    }
    else
    {
        index++;
    }

    return index;
}

int tripleSearch(const vector<int> &v, int t, int l, int u)
{
    if (l >= u || l < 0 || u > v.size())
    {
        return -1;
    }

    int index = -1;

    while (l < u)
    {
        int m1 = l + (u - l) / 3;
        int m2 = l + 2 * (u - l) / 3;

        if (v[m1] == t)
        {
            index = m1;
            break;
        }
        else if (v[m2] == t)
        {
            index = m2;
            break;
        }
        else if (v[m1] > t)
        {
            u = m1;
        }
        else if (v[m2] > t)
        {
            l = m1 + 1;
            u = m2;
        }
        else
        {
            l = m2 + 1;
        }
    }

    return index;
}

int main()
{
    vector<int> v;

    //initializeIndexVector(v, NUM);
    initializeRandomVector(v, NUM);

    //printVector<int>(v);
    sort(v.begin(), v.end());
    printVector<int>(v);

/*
    int pick = rand() % NUM;

    cout << "The pick number is: v[" << pick << "] = " << v[pick] << endl;
    cout << "The result of binary search is: " << binarySearch2(v, v[pick], 0, 0 + v.size()) << endl;
    cout << "The result of binary search is: " << tripleSearch(v, v[pick], 0, 0 + v.size()) << endl;

*/
    int target = 0;
    cout << "Please input the number you want to search: ";
    cin >> target;
    cout << "The first of binary search is: " << binarySearchFirst(v, target, 0, 0 + v.size()) << endl;
    cout << "The last of binary search is: " << binarySearchLast(v, target, 0, 0 + v.size()) << endl;
    cout << "The upper bound of binary search is: " << binarySearchUpperBound(v, target, 0, 0 + v.size()) << endl;
    return 0;
}
