#include <iostream>

using namespace std;

class Solution {
public:
    // Fibonacci sequence
    int climbStairs(int n) {
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
    int n = 0;
    cout << "Please enter number: ";
    cin >> n;
    cout << sln.climbStairs(n) << endl;
    return 0;
}
