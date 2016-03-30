#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);

        int i2 = 0, i3 = 0, i5 = 0;

        while (res.size() < n)
        {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;

            int mn = min(m2, min(m3, m5));

            if (mn == m2)
            {
                i2++;
            }

            // because mn could equal to m2 and m3 at the same time, so we need to use if, not else if
            if (mn == m3)
            {
                i3++;
            }

            if (mn == m5)
            {
                i5++;
            }

            res.push_back(mn);
        }

        return res.back();
    }

    int nthUglyNumber_use_priority_queue(int n) {
        if (n <= 1)
        {
            return n;
        }

        // use long to avoid overflow, f * 5.
        vector<long> v2 = {2}, v3 = {3}, v5 = {5};
        priority_queue<long, vector<long>, std::greater<long>> q2(std::greater<long>(), v2), q3(std::greater<long>(), v3), q5(std::greater<long>(), v5);
        vector<priority_queue<long, vector<long>, std::greater<long>>> v;
        v.push_back(q2);
        v.push_back(q3);
        v.push_back(q5);
        // using unordered_set is faster than set here
        unordered_set<long> s;
        long res = 0;

        while (--n > 0)
        {
            int minIndex = 0;
            long minV = v[0].top();

            for (int i = 1; i < 3; ++i)
            {
                if (v[i].top() < minV)
                {
                    minV = v[i].top();
                    minIndex = i;
                }
            }

            long f = v[minIndex].top();

            long f2 = f * 2;

            if (s.insert(f2).second)
            {
                v[minIndex].push(f2);
            }

            long f3 = f * 3;

            if (s.insert(f3).second)
            {
                v[minIndex].push(f3);
            }

            long f5 = f * 5;

            if (s.insert(f5).second)
            {
                v[minIndex].push(f5);
            }

            minIndex = 0;
            minV = v[0].top();

            for (int i = 1; i < 3; ++i)
            {
                if (v[i].top() < minV)
                {
                    minV = v[i].top();
                    minIndex = i;
                }
            }

            res = v[minIndex].top();
            v[minIndex].pop();
        }

        return res;
    }

    int nthUglyNumber_use_heap(int n) {
        if (n <= 1)
        {
            return n;
        }

        vector<vector<long>> v = {{2}, {3}, {5}};
        unordered_set<long> s;
        long res = 0;

        while (--n > 0)
        {
            int minIndex = 0;
            long minV = v[0].front();

            for (int i = 1; i < 3; ++i)
            {
                if (v[i].front() < minV)
                {
                    minV = v[i].front();
                    minIndex = i;
                }
            }

            make_heap(v[minIndex].begin(), v[minIndex].end(), std::greater<long>());
            long f = v[minIndex].front();

            long f2 = f * 2;

            if (s.insert(f2).second)
            {
                v[minIndex].push_back(f2);
            }

            long f3 = f * 3;

            if (s.insert(f3).second)
            {
                v[minIndex].push_back(f3);
            }

            long f5 = f * 5;

            if (s.insert(f5).second)
            {
                v[minIndex].push_back(f5);
            }

            // extend the range of heap
            // This is unnecessary.
            push_heap(v[minIndex].begin(), v[minIndex].end(), std::greater<long>());

            minIndex = 0;
            minV = v[0].front();

            for (int i = 1; i < 3; ++i)
            {
                if (v[i].front() < minV)
                {
                    minV = v[i].front();
                    minIndex = i;
                }
            }

            // decrease the range of heap
            res = v[minIndex].front();
            // why pop_heap doesn't preserve the heap property after moving the smallest element to the end
            // 6	10	20	8	12	18	30
            // 10	8	20	30	12	18	6
            // 8 should be the first element
            // This is because we don't call make_heap before we rearrange the heap.
            pop_heap(v[minIndex].begin(), v[minIndex].end(), std::greater<int>());
            v[minIndex].pop_back();
        }

        return res; 
    }

    int nthUglyNumber_slow(int n) {
        if (n <= 5)
        {
            return n;
        }

        unordered_set<int> s = {1, 2, 3, 4, 5};

        int num = 5;
        n -= 5;

        while (n > 0)
        {
            num++;
            int r1 = num % 2, r2 = num % 3, r3 = num % 5;

            if ((r1 != 0 && r2 != 0 && r3 != 0) ||
                (r1 == 0 && s.count(num / 2) == 0) ||
                (r2 == 0 && s.count(num / 3) == 0) ||
                (r3 == 0 && s.count(num / 5) == 0))

            {
                continue;
            }

            s.insert(num);
            n--;
        }

        return num;
    }
};

int main()
{
    Solution sln;
    std::vector<int> v = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 377, 1357, 1407};
    //std::vector<int> v = {7, 8, 9, 10};

    for (auto n: v)
    {
        std::cout << "n: " << n << ", " << sln.nthUglyNumber_use_priority_queue(n) << std::endl;
        //std::cout << "n: " << n << ", " << sln.nthUglyNumber_use_heap(n) << std::endl;
        std::cout << "n: " << n << ", " << sln.nthUglyNumber(n) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
