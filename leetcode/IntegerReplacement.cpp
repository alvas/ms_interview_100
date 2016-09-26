#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        int c = 0;
        // be careful about n + 1 overflow
        long t = n;

        if (t <= 0)
        {
            return c;
        }

        while (t != 1)
        {
            c++;

            if (t & 1)
            {
                // for other 11, we need n + 1,
                if ((t & 2) && t != 3)
                {
                    t++;
                }
                else
                {
                    // for other 01, we need n - 1
                    // for 3, n - 1
                    t--;
                }
            }
            else
            {
                t >>= 1;
            }
        }

        return c;
    }

    // Need to improve
    int integerReplacement1(int n) {
        int c = 0;
        
        if (n <= 0)
        {
            return c;
        }

        return helper(n, c);
    }

    // be careful about overflow 2147483647 + 1
    int helper(long n, int c)
    {
        if (n == 1)
        {
            return c;
        }
        else
        {
            c++;

            if (n & 1)
            {
                return min(helper(n + 1, c), helper(n - 1, c));
            }
            else
            {
                return helper(n >> 1, c);
            }
        }
    }
};

int main()
{
    Solution sln;
    //int n = 9;
    //int n = 7;
    //int n = 1257;
    //int n = 100000000;
    //int n = 390625;
    //int n = 390624;
    //int n = 12207;
    //int n = 763;
    int n = 2147483647;
    cout << n << ": " << bitset<32>(n) << ": "<< sln.integerReplacement(n) << endl;
    return 0;
}
