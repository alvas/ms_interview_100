#include <algorithm>
#include <boost/math/common_factor.hpp>
#include <iostream>
#include <vector>
#include "NormalData.h"
#include "Timing.h"

using namespace std;
using namespace boost::math;

void Shift1(vector<int> &v, size_t n)
{
    int num = v.size();

    if (num <= n)
    {
        return;
    }

    size_t start = 0;
    int count = 0;

    do
    {
        size_t index = start, index2 = start + n;
        int tmp = v[index];
        v[index] = v[index2];
        count++;
        index = index2;
        index2 += n;

        while (index2 % num != start)
        {
            if (index2 > num)
            {
                index2 %= num;
            }

            v[index] = v[index2];
            index = index2;
            index2 += n;
            count++;
        }

        v[index] = tmp;
        count++;
        start++;
    } while (count < num);
}

void Shift2(vector<int> &v, size_t n)
{
    reverse(v.begin(), v.begin() + n);
    reverse(v.begin() + n, v.end());
    reverse(v.begin(), v.end());
}

// Shift algorithm with gcd
void Shift3(vector<int> &v, int n)
{
    int size = v.size();

    if (size <= n)
    {
        return;
    }

    int gcdOfSizeAndN = gcd(size, n);

    for (int i = 0; i < gcdOfSizeAndN; ++i)
    {
        int index = i;
        int tmp = v[index];

        while (((index + n) % size) != i)
        {
            v[index] = v[(index + n) % size];
            index = (index + n) % size;
        }

        v[index] = tmp;
    }
}

void Reverse(vector<int> &v)
{
    int num = v.size();

    for (int i = 0; i < num / 2; ++i)
    {
        int tmp = v[i];
        v[i] = v[num - 1 - i];
        v[num - 1 - i] = tmp;
    }
}

void Reverse3Component(vector<int> &v, const int first, const int second)
{
    if (first < 0 || second < 0 || first > second)
    {
        return;
    }

    int num = v.size();

    if (first > num || second > num)
    {
        return;
    }

    reverse(v.begin(), v.begin() + first);
    reverse(v.begin() + first, v.begin() + second);
    reverse(v.begin() + second, v.end());
    reverse(v.begin(), v.end());
}

int myGCD(int a, int b)
{
    while (b != 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

int main(int argc, char *argv[])
{
    vector<int> v;
    initializeIndexVector(v, 8);
    printVector(v);
    clock_t start = clock();
    Shift3(v, 3);
//    Reverse3Component(v, 3, 6);
    clock_t end = clock();
    printVector(v);
    printTime(end - start);
#if 0
    int a = atoi(argv[1]), b = atoi(argv[2]);
    cout << "gcd of " << a << " and " << b << " is: " << gcd(a,b) << endl;
    cout << "myGCD of " << a << " and " << b << " is: " << myGCD(a,b) << endl;
#endif
    return 0;
}
