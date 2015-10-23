#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
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
    int x = 0;
    std::cout << "Please input n: ";
    cin >> x;
    std::cout << sln.isPalindrome(x) << endl;
    return 0;
}

