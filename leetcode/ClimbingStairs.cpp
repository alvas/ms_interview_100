#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0)
        {
            return 0;
        }

        // f(k - 1) is one step to f(k); f(k - 2) is one step or two steps to f(k).
        // but f(k - 2) go one step, it is the same as f(k - 1), so f(k) = f(k - 1) + f(k - 2).
        //vector<int> v = {1, 1};

        //for (int i = 2; i <= n; ++i)
        //{
            //v.push_back(v[i - 1] + v[i - 2]);
        //}

        //return v[n];
        int p1 = 1, p2 = 1;

        for (int i = 2; i <= n; ++i)
        {
            int p3 = p1 + p2;
            p1 = p2;
            p2 = p3;
        }

        return p2;
    }

    // Fibonacci sequence
    int climbStairs2(int n) {
        int A[3] = {1, 1, 0};

        if (n == 0)
        {
            return 0;
        }
        // Be careful about the tricky difference between Fibonacci sequence value and this problem,
        // for value less than 2: 0???, 1, 1???, 2, 3, ..
        else if (n < 2)
        {
            return A[n];
        }

        // proper start index
        int i = 2;

        for ( ; i <= n; ++i)
        {
            A[i % 3] = A[(i - 1) % 3] + A[(i - 2) % 3];
        }

        // Be careful the index here, can't use A[i];
        return A[n % 3];
    }

    // Time exceed
    int climbStairs1(int n) {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }

        return climbStairs1(n - 1) + climbStairs1(n - 2);
    }
};

int main()
{
    Solution sln;
    const int N = 20;

    for (int i = 0; i < N; ++i)
    {
        std::cout << "i: " << i << " ,";
        int a = sln.climbStairs(i);
        int b = sln.climbStairs2(i);
        std::cout << a << ", " << b << endl;
        assert(a == b);
    }

    return 0;
}
