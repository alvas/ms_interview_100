#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        // be careful when x is bitter than 1000000000
        long d = 1;

        while (x / d)
        {
            d *= 10;
        }

        cout << d << endl;

        while (x)
        {
            d /= 10;

            if (x % 10 != x / d)
            {
                return false;
            }

            x %= d;
            x /= 10;
            d /= 10;
        }

        return true;
    }

    bool isPalindrome3(int x) {
        if (x < 0)
        {
            return false;
        }

        int a = x, b = 0;

        while (a != 0)
        {
            b *= 10;
            b += a % 10;
            a /= 10;
        }

        return b == x;
    }

    bool isPalindrome2(int x) {
        if (x < 0)
        {
            return false;
        }

        int len = 1;

        while (x / len >= 10)
        {
            len *= 10;
        }

        while (x != 0)
        {
            int l = x / len;
            int r = x % 10;

            if (l != r)
            {
                return false;
            }

            // chopping the first and last digit
            x = (x % len) / 10;
            len /= 100;
        }

        return true;
    }

    // Need to improve.
    bool isPalindrome1(int x) {
        bool isP = false;

        if (x >= 0)
        {
            int y = x % 10, z = x;
            x /= 10;

            while (x > 0)
            {
                y *= 10;
                y += (x % 10);
                x /= 10;
            }

            // y would overflow
            if (z == y)
            {
                isP = true;
            }
        }

        return isP;
    }
};

int main()
{
    Solution sln;
    //int x = 0;
    //std::cout << "Please input n: ";
    //cin >> x;
    //
    std::vector<int> v = {-1, 0, 1, 7, 10, 11, 15, 20, 22, 121, 123, 321, 202, 205, 1001, 10001, 55555, 1000000001};

    for (auto x : v)
    {
        std::cout << x << ": " << sln.isPalindrome(x) << endl;
    }
    return 0;
}

