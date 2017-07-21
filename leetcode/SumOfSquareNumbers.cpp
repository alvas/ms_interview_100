#include <cmath>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    // Fermat Theorem
    // "Any positive number n is expressible as a sum of two squares if and only if the prime factorization of n, every prime of the form (4k+3) occurs an even number of times."
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; ++i) {
            int count = 0;

            if (c % i == 0) {
                while (c % i == 0) {
                    count++;
                    c /= i;
                }

                if (i % 4 == 3 && count % 2 != 0) 
                    return false;
            }
        }

        return c % 4 != 3;
    }

    bool judgeSquareSum1(int c) {
        set<int> s;
        int root = sqrt(c);

        for (int i = 0; i <= root; ++i) {
            s.insert(i * i);
        }

        for (auto i: s) {
            if (s.find(c - i) != s.end())
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sln;
    //int c = 5;
    //int c = 3;
    //int c = 10;
    int c = 4;
    cout << sln.judgeSquareSum(c) << endl;
    return 0;
}
