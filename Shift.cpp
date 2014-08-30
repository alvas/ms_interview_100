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
void Shift3(vector<int> &v, size_t n)
{
    int num = v.size();

    if (num <= n)
    {
        return;
    }

    int gcdOfNumAndI = gcd(num, (int)n);

    for (int i = 0; i < gcdOfNumAndI; ++i)
    {
        int index = i, index2 = i + n;
        int tmp = v[index];
        v[index] = v[index2];
        index = index2;
        index2 += n;

        while (index2 % num != i)
        {
            if (index2 > num)
            {
                index2 %= num;
            }

            v[index] = v[index2];
            index = index2;
            index2 += n;
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

int main()
{
    vector<int> v;
    initializeIndexVector(v, 8);
    clock_t start = clock();
    Shift3(v, 3);
//    Reverse3Component(v, 3, 6);
    clock_t end = clock();
    printVector(v);
    printTime(end - start);
    return 0;
}
